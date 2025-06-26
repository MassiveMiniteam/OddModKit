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

TSoftObjectPtr<UStaticMesh> UItemConfig::GetStackMeshByStrategy(TSubclassOf<UItemStackingStrategy> StackingStrategy, int32 Amount) const {
    return NULL;
}

TSoftObjectPtr<UStaticMesh> UItemConfig::GetStackLayout(int32 Amount) const {
    return NULL;
}

FString UItemConfig::GetRichTextId() const {
    return TEXT("");
}


