#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "GridAreaRegistrationStrategy.generated.h"

class UPositionSimulationComponent;

UCLASS(Abstract, Blueprintable)
class LOC_API UGridAreaRegistrationStrategy : public UObject {
    GENERATED_BODY()
public:
    UGridAreaRegistrationStrategy();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntPoint> GetGridPositionsInArea(const UPositionSimulationComponent* PositionSimulationComponent) const;
    
};

