#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PresentationActorComponent.h"
#include "ProjectileParameters.h"
#include "ProjectilePresentationParameters.h"
#include "ProjectileThrowEventDelegate.h"
#include "ProjectilePresentationComponent.generated.h"

class UProjectileSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UProjectilePresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRotateToThrowDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFullProjectileCurveRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PositionOffset;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProjectileThrowEvent OnProjectileThrowStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProjectileThrowEvent OnProjectileThrowLand;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UProjectileSimulationComponent> ProjectileSimulationComponent;
    
public:
    UProjectilePresentationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnThrowStart(const FProjectilePresentationParameters& Params);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSimulationLaunched(UProjectileSimulationComponent* SimulationComponent, const FProjectileParameters& SimulationParameters);
    
    UFUNCTION(BlueprintCallable)
    void OnSimulationAtTarget(UProjectileSimulationComponent* SimulationComponent, const FProjectileParameters& SimulationParameters);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAtTarget(const FProjectilePresentationParameters& Params);
    
public:
    UFUNCTION(BlueprintCallable)
    void LaunchPredicted(const FProjectileParameters& SimulationParameters);
    
    UFUNCTION(BlueprintCallable)
    void Launch(const FProjectileParameters& SimulationParameters, bool bIgnorePredictionAlreadyRunning);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRunning() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCurrentlyInPrediction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetCurrentTargetPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentProgress() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FProjectilePresentationParameters GetCurrentParameters() const;
    
};

