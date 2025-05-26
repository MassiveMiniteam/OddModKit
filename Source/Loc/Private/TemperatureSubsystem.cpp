#include "TemperatureSubsystem.h"

UTemperatureSubsystem::UTemperatureSubsystem() {
}

bool UTemperatureSubsystem::HasEmitterInfluenceAt(FIntPoint GridPosition) const {
    return false;
}

int32 UTemperatureSubsystem::GetTemperatureAt(FIntPoint GridPosition) const {
    return 0;
}

TMap<FIntPoint, int32> UTemperatureSubsystem::GetCachedTemperatureMap() const {
    return TMap<FIntPoint, int32>();
}


