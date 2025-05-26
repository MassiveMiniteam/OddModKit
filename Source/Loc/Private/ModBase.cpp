#include "ModBase.h"

UModBase::UModBase() {
    this->ModSettings = NULL;
}

void UModBase::RegisterObjectForOverride(UObject* Object) {
}



bool UModBase::IsCompatibleWithVersion_Implementation(const FString& Version) {
    return false;
}


