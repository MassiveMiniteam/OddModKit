#include "ShopTokenGeneratorComponent.h"

UShopTokenGeneratorComponent::UShopTokenGeneratorComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CurrentLevel = 1;
    this->CurrentScore = 0;
    this->LevelGrowthModifier = 500;
}

UShopTokenGeneratorComponent* UShopTokenGeneratorComponent::GetShopTokenGenerator(UObject* WorldContext) {
    return NULL;
}

int64 UShopTokenGeneratorComponent::CalculateNeededPointsForLevel(int32 Level) const {
    return 0;
}


