#pragma once
#include "CoreMinimal.h"
#include "MinionControllerSimulationBaseComponent.h"
#include "MinionControllerSimulationMovingHostComponent.generated.h"

class UMinionFormationSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMinionControllerSimulationMovingHostComponent : public UMinionControllerSimulationBaseComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMinionFormationSimulationComponent* MinionFormationComponent;
    
public:
    UMinionControllerSimulationMovingHostComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetFollowingMinionCount(int32 MinionSlotIndex) const;
    
};

