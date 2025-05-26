#include "BiomeInstance.h"

UBiomeInstance::UBiomeInstance() {
    this->BiomeConfig = NULL;
    this->WorldGenerator = NULL;
    this->BiomeSeed = 0;
}

void UBiomeInstance::SetBiomeInstanceName(const FText& NewName) {
}

FIntPoint UBiomeInstance::GetCenterAsGridPosition() const {
    return FIntPoint{};
}

FText UBiomeInstance::GetBiomeInstanceName() const {
    return FText::GetEmpty();
}


