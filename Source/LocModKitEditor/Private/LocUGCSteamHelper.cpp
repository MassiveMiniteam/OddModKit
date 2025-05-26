// Fill out your copyright notice in the Description page of Project Settings.


#include "LocUGCSteamHelper.h"

#include "ModKitEditorSettings.h"
#include <steam/isteamugc.h>
#include <steam/isteamutils.h>
#include <steam/steam_api.h>

#include "Kismet/KismetSystemLibrary.h"

void ULocUGCSteamHelper::UGC_CreateNewItem(const FString& ModId)
{
	EAppReturnType::Type Result = FMessageDialog::Open(EAppMsgCategory::Info, EAppMsgType::OkCancel, FText::FromString("By submitting this item, you agree to the agreement at:\nhttp://steamcommunity.com/sharedfiles/workshoplegalagreement"));
	if (Result == EAppReturnType::Type::Cancel)
	{
		return;
	}
	
	GetModContextForAPICall(ModId, [ModId](bool bSuccess, FModKitModDefinition* ModDefinition, UModKitEditorSettings* Settings, ISteamUGC* UGC)
	{
		if (bSuccess)
		{
			auto Call = UGC->CreateItem(SteamUtils()->GetAppID(), k_EWorkshopFileTypeCommunity);
			CreateItemResult_t Result;
			if (WaitForSteamAPICall(Call, Result))
			{
				UE_LOG(LogTemp, Log, TEXT("PublishedFileId: %llu"), Result.m_nPublishedFileId);
				ModDefinition->SteamPublishedFileId = FString::Printf(TEXT("%llu"), Result.m_nPublishedFileId);
				Settings->TryUpdateDefaultConfigFile();

				auto UpdateHandle = UGC->StartItemUpdate(SteamUtils()->GetAppID(), ModDefinition->GetSteamPublisherFileId());
				UGC->SetItemTitle(UpdateHandle, TCHAR_TO_ANSI(*ModDefinition->ModId));
				UGC->AddItemKeyValueTag(UpdateHandle, "ModId", TCHAR_TO_ANSI(*ModDefinition->ModId));
				SubmitItemUpdate(ModId, UpdateHandle, "[ModKit] created item");

				FPlatformProcess::Sleep(2);
				
				FString URL = FString::Printf(TEXT("steam://url/CommunityFilePage/%llu"), Result.m_nPublishedFileId);
				UKismetSystemLibrary::LaunchURL(URL);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("CreateItem failed in steamsdk"));
			}
		}
	});
}

void ULocUGCSteamHelper::SubmitItemUpdate(const FString& ModId, UGCUpdateHandle_t Handle, const FString& ChangeNote)
{
	GetModContextForAPICall(ModId, [Handle, ChangeNote](bool bSuccess, FModKitModDefinition* ModDefinition, UModKitEditorSettings* Settings, ISteamUGC* UGC)
	{
		if (bSuccess)
		{
			auto Call = UGC->SubmitItemUpdate(Handle, TCHAR_TO_ANSI(*ChangeNote));
			SubmitItemUpdateResult_t Result;
			if (WaitForSteamAPICall(Call, Result))
			{
				UE_LOG(LogTemp, Log, TEXT("SubmitItemUpdate finished %s"), *ChangeNote);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("SubmitItemUpdate failed in steamsdk"));
			}
		}
	});
}

void ULocUGCSteamHelper::GetModContextForAPICall(const FString& ModId, TFunction<void(bool bSuccess, FModKitModDefinition* ModDefinition, UModKitEditorSettings* Settings, ISteamUGC* UGC)> OnContext)
{
	ISteamUGC* UGC = SteamUGC();
	if (UGC == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Error, SteamSDK invalid"));
		OnContext(false, nullptr, nullptr, nullptr);
		return;
	}

	UModKitEditorSettings* ModKitSettings = GetMutableDefault<UModKitEditorSettings>();
	FModKitModDefinition* Definition = ModKitSettings->GetModDefinition(ModId);
	if (Definition == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Failed to create new item, modid invalid"));
		OnContext(false, nullptr, ModKitSettings, UGC);
		return;
	}
	
	OnContext(true, Definition, ModKitSettings, UGC);
}

void ULocUGCSteamHelper::UGC_ListMods()
{
	ISteamUGC* UGC = SteamUGC();
	if (UGC == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Error, SteamSDK invalid"));
		return;
	}

	CSteamID SteamID = SteamUser()->GetSteamID();
	auto QueryHandle = UGC->CreateQueryUserUGCRequest(SteamID.GetAccountID(), k_EUserUGCList_Published, k_EUGCMatchingUGCType_All, k_EUserUGCListSortOrder_CreationOrderDesc, SteamUtils()->GetAppID(), SteamUtils()->GetAppID(), 1);
	SteamAPICall_t ApiCall = SteamUGC()->SendQueryUGCRequest(QueryHandle);
	
	SteamUGCQueryCompleted_t Result;
	if (WaitForSteamAPICall(ApiCall, Result))
	{
		for (uint32 i = 0; i < Result.m_unNumResultsReturned; i++) {
			SteamUGCDetails_t details;
			if (SteamUGC()->GetQueryUGCResult(Result.m_handle, i, &details)) {
				UE_LOG(LogTemp, Log, TEXT("Found UGC item: %hs (ID: %llu)"), details.m_rgchTitle, details.m_nPublishedFileId);
			}
		}

		// Release the query handle
		SteamUGC()->ReleaseQueryUGCRequest(Result.m_handle);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("CreateQueryUserUGCRequest failed in steamsdk"));
	}
}