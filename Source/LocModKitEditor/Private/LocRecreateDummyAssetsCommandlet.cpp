// Copyright 2024 Massive Miniteam GmbH. All Rights Reserved.

#include "LocRecreateDummyAssetsCommandlet.h"

#include "FileHelpers.h"
#include "LocAssetDumpImporter.h"
#include "UObject/SavePackage.h"


void ULocRecreateDummyAssetsCommandlet::GetAllFilesInDirectory(const FString& Directory, TArray<FString>& OutFiles, bool bRecursive, const FString& FileExtensionFilter)
{
	FString FinalDirectory = Directory;
	if (!FinalDirectory.EndsWith(TEXT("/")))
	{
		FinalDirectory += TEXT("/");
	}

	// Construct the wildcard path, e.g., "C:/MyFolder/*.uasset"
	FString SearchPath = FinalDirectory + FileExtensionFilter;

	// Get the file manager
	IFileManager& FileManager = IFileManager::Get();

	// Get files in the current directory
	FileManager.FindFiles(OutFiles, *SearchPath, true, false);

	if (bRecursive)
	{
		// Get subdirectories
		TArray<FString> SubDirs;
		FileManager.FindFiles(SubDirs, *(FinalDirectory + TEXT("*")), false, true);

		for (const FString& SubDir : SubDirs)
		{
			FString SubDirFullPath = FinalDirectory + SubDir;
			GetAllFilesInDirectory(SubDirFullPath, OutFiles, bRecursive, FileExtensionFilter);
		}
	}
}

void ULocRecreateDummyAssetsCommandlet::SaveAllDirtyPackagesInCommandlet()
{
	TArray<UPackage*> DirtyPackages;

	// Iterate over all packages in memory and collect the dirty ones
	for (TObjectIterator<UPackage> PackageIt; PackageIt; ++PackageIt)
	{
		UPackage* Package = *PackageIt;
		if (Package && Package->IsDirty() && !Package->HasAnyFlags(RF_Transient))
		{
			DirtyPackages.Add(Package);
		}
	}

	// Save each dirty package
	for (UPackage* Package : DirtyPackages)
	{
		const FString PackageFilename = FPackageName::LongPackageNameToFilename(Package->GetName(), FPackageName::GetAssetPackageExtension());

		FSavePackageArgs SaveArgs;
		SaveArgs.TopLevelFlags = RF_Public | RF_Standalone;
		SaveArgs.Error = GError;
		SaveArgs.bForceByteSwapping = false;
		SaveArgs.SaveFlags = SAVE_NoError;
        
		UWorld* World = nullptr;
		if (!UPackage::SavePackage(Package, nullptr, *PackageFilename, SaveArgs))
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to save package: %s"), *Package->GetName());
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Saved package: %s"), *Package->GetName());
		}
	}
}

int32 ULocRecreateDummyAssetsCommandlet::Main(const FString& Params)
{
	UE_LOG(LogTemp, Log, TEXT("Command let main"));

	TArray<FString> Tokens, Switches;
	ParseCommandLine(*Params, Tokens, Switches);

	TArray<FString> FilesFound;
	TArray<FString> FilesToCreate;
	IFileManager::Get().FindFilesRecursive(FilesFound, *(FPaths::ProjectSavedDir() / "Backup"), TEXT("*"), true, false, true);
	for (auto File : FilesFound)
	{
		FString RelativeFile = "/Game/LOC" / File.RightChop(File.Find("OddModKit/Saved/Backup") + std::strlen("OddModKit/Saved/Backup"));
		RelativeFile = RelativeFile.Replace(TEXT(".uasset"), TEXT(""));
		FilesToCreate.Add(RelativeFile);
		UE_LOG(LogTemp, Log, TEXT("%s"), *RelativeFile);
	}

	ULocAssetDumpImporter::ImportAssetDumpWithFileList(FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectDir(), "AssetDump.bin")), FilesToCreate);
	SaveAllDirtyPackagesInCommandlet();
	
	return 0;
}
