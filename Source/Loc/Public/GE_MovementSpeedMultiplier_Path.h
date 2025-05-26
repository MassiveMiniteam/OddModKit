#pragma once
#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "GE_MovementSpeedMultiplier_Path.generated.h"

class USubGridMovementSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UGE_MovementSpeedMultiplier_Path : public UGameplayEffect {
    GENERATED_BODY()
public:
    UGE_MovementSpeedMultiplier_Path();

    UFUNCTION(BlueprintCallable)
    void OnNewTileEntered(USubGridMovementSimulationComponent* SubGridMovementSimulationComponent);
    
};

