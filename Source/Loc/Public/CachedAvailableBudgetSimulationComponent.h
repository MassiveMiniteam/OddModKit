#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "HostilitySimulationComponentIntEventDelegate.h"
#include "RegisteredSimulationComponent.h"
#include "CachedAvailableBudgetSimulationComponent.generated.h"

class UTimedTargetDetectorSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UCachedAvailableBudgetSimulationComponent : public URegisteredSimulationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHostilitySimulationComponentIntEvent OnCachedAvailableBudgetSet;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference TimedTargetDetectorReference;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTimedTargetDetectorSimulationComponent* TimedTargetDetector;
    
public:
    UCachedAvailableBudgetSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void SetAvailableBudgetForInfluenceRadius(int32 AvailableBudget);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRadius();
    
};

