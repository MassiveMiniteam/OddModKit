#include "ItemConfig.h"
#include "Templates/SubclassOf.h"

UItemConfig::UItemConfig() {
    this->Icon = NULL;
    this->IconSmall = NULL;
    this->IconLarge = NULL;
    this->StackSize = 20;
    this->CategoryUIOrder = 0;
    this->bCanBeTransformedToToken = true;
    this->ShopTokenValue = 10;
    this->BlobShadowScale = 1.00f;
    this->PickupSound = NULL;
    this->DropSound = NULL;
    this->BuffToAllEquippedSparks = NULL;
}

AGridObject* UItemConfig::SpawnItemGridObject(const UObject* WorldContext, FIntPoint position, int32 Amount, UItemStackData* Data, bool bTryInstantlyMergeIntoAnotherActorAtGridPosition, bool bInstantlySpawnPresentation) {
    return NULL;
}

bool UItemConfig::IsStackable_Implementation(UItemConfig* LeftConfig, UItemStackData* LeftData, UItemConfig* RightConfig, UItemStackData* RightData) {
    return false;
}

FStaticMeshAndTransforms UItemConfig::GetStackLayoutByStackingStrategy(TSubclassOf<UItemStackingStrategy> StackingStrategy, int32 Amount) const {
    return FStaticMeshAndTransforms{};
}

FStaticMeshAndTransforms UItemConfig::GetStackLayout(int32 Amount) const {
    return FStaticMeshAndTransforms{};
}

FString UItemConfig::GetRichTextId() const {
    return TEXT("");
}

UItemStackData* UItemConfig::CreateItemStackData_Implementation(const UObject* WorldContext) {
    return NULL;
}


