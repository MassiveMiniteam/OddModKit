#pragma once
#include "CoreMinimal.h"
#include "SimulationActor.h"
#include "UnitBase.generated.h"

class UPositionSimulationComponent;
class UStatsComponent;

UCLASS(Blueprintable)
class LOC_API AUnitBase : public ASimulationActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPositionSimulationComponent* NativeCachedPositionSimulationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatsComponent* NativeCachedStatsComponent;
    
public:
    AUnitBase(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPositionSimulationComponent* GetPositionSimulationComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UStatsComponent* GetCachedStatsComponent() const;
    
};

