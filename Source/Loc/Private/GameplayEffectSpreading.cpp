#include "GameplayEffectSpreading.h"

UGameplayEffectSpreading::UGameplayEffectSpreading() {
    this->MaxSpreading = 1;
    this->CurrentSpreading = 0;
    this->ActorsToIgnore = NULL;
}


