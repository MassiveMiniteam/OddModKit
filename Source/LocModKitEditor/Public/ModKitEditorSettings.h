

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "UObject/Object.h"
#include "ModKitEditorSettings.generated.h"

USTRUCT(BlueprintType)
struct FModEditorManifestShort {
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ID;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Version;
};


USTRUCT(BlueprintType)
struct FModEditorManifest
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Author;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Version;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString GameVersion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FModEditorManifestShort> Dependencies;
	UPROPERTY(VisibleAnywhere)
	FString LastUpdated;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bAchievementsAllowed = true;
};

USTRUCT(BlueprintType)
struct FModKitModDefinition
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ModId;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ChunkId = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SteamPublishedFileId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FModEditorManifest Manifest;

	uint64 GetSteamPublisherFileId() const
	{
		return FCString::Strtoui64(*SteamPublishedFileId, nullptr, 10);
	}
};

/**
 * 
 */
UCLASS(config = Editor, defaultconfig, meta = (DisplayName = "ModKit Developer Settings"))
class LOCMODKITEDITOR_API UModKitEditorSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite)
	TArray<FModKitModDefinition> ModDefinitions;
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite)
	FString OddsparksSteamDirectory;
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite)
	FString AdditionalLaunchArguments;
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static UModKitEditorSettings* GetModKitEditorSettings()
	{
		return GetMutableDefault<UModKitEditorSettings>();
	}

	FModKitModDefinition* GetModDefinition(FString ModId)
	{
		for (int i = 0; i < ModDefinitions.Num(); i++)
		{
			if (ModDefinitions[i].ModId == ModId)
			{
				return &ModDefinitions[i];
			}
		}

		return nullptr;
	}
};
