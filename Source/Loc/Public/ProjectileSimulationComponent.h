#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProjectileEventDelegate.h"
#include "ProjectileParameters.h"
#include "SimulationTimerComponent.h"
#include "ProjectileSimulationComponent.generated.h"

class UPositionSimulationComponent;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UProjectileSimulationComponent : public USimulationTimerComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetOwnerPositionToDestinationOnLaunch;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProjectileEvent OnLaunch;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProjectileEvent OnAtTarget;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FProjectileParameters ProjectileParameters;
    
public:
    UProjectileSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void Launch(const FProjectileParameters& Parameters);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector GetTargetPosition() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetIsMidAir() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FProjectileParameters GetCurrentParameters() const;
    
};

