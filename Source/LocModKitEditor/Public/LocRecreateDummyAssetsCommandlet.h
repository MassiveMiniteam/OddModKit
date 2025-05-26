// Copyright 2024 Massive Miniteam GmbH. All Rights Reserved.

#pragma once

#include "Commandlets/Commandlet.h"
#include "LocRecreateDummyAssetsCommandlet.generated.h"
 
UCLASS()
class ULocRecreateDummyAssetsCommandlet : public UCommandlet
{
	GENERATED_BODY()

	virtual int32 Main(const FString& Params) override;
	void GetAllFilesInDirectory(const FString& Directory, TArray<FString>& OutFiles, bool bRecursive = true, const FString& FileExtensionFilter = TEXT("*"));
	void SaveAllDirtyPackagesInCommandlet();
};
