#include "ProductEntitlementDataAsset.h"

UProductEntitlementDataAsset::UProductEntitlementDataAsset() {
    this->SteamAppId = 0;
    this->GOGProductID = 0;
    this->GOGStoreURL = TEXT("https://www.gog.com/game/are_you_smarter_than_a_5th_grader_extra_credit");
    this->XBoxEntitlementType = EXBoxEntitlementType::Core;
    this->SwitchAddOnContentIndex = 0;
    this->bShowInUI = true;
    this->bDefaultEntitled = false;
    this->bIsEntitledCache = false;
}

void UProductEntitlementDataAsset::SetEntitled(bool Value) {
}

void UProductEntitlementDataAsset::RefreshEntitlement(UObject* WorldContextObject) {
}

bool UProductEntitlementDataAsset::IsEntitled() {
    return false;
}


