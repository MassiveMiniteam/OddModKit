// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <steam/isteamugc.h>

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include <steam/isteamutils.h>

#include "ModKitEditorSettings.h"
#include "LocUGCSteamHelper.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class LOCMODKITEDITOR_API ULocUGCSteamHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static void GetModContextForAPICall(const FString& ModId, TFunction<void(bool bSuccess, FModKitModDefinition* ModDefinition, UModKitEditorSettings* Settings, ISteamUGC* UGC)> OnContext);
	static void SubmitItemUpdate(const FString& ModId, UGCUpdateHandle_t Handle, const FString& ChangeNote);
	
	UFUNCTION(BlueprintCallable)
	static void UGC_ListMods();

	UFUNCTION(BlueprintCallable)
	static void UGC_CreateNewItem(const FString& ModId);

	template <typename ResultType>
	static bool WaitForSteamAPICall(uint64 Handle, ResultType& Result)
	{
		bool bFailedResult;
		bool bFailedCall;
		while (!SteamUtils()->IsAPICallCompleted(Handle, &bFailedCall));
		bool bSuccessCallResult = SteamUtils()->GetAPICallResult(Handle, &Result, sizeof(ResultType), Result.k_iCallback, &bFailedResult);
		return bSuccessCallResult && !bFailedCall && !bFailedResult;
	}
};
