#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "CopyToolUseable.h"
#include "SimulationTimerComponent.h"
#include "Templates/SubclassOf.h"
#include "CatapultAimSimulationComponent.generated.h"

class ASimulationActor;
class UGameplayAbilityTargeting;
class UInventoryComponent;
class UPositionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UCatapultAimSimulationComponent : public USimulationTimerComponent, public ICopyToolUseable {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UGameplayAbilityTargeting> DefaultTargetingClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* WorkerInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ASimulationActor> CurrentTargetActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UGameplayAbilityTargeting> CurrentTargetingClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed RotationSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed ShootingAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed LocalRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed TargetDistance;
    
public:
    UCatapultAimSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void PickNewTargetActor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTargetActorValid() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTargetActorInShootingAngle() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetTargetDistance() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetLocalRotation() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UGameplayAbilityTargeting> GetCurrentTargetingClass() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASimulationActor* GetCurrentTargetActor() const;
    

    // Fix for true pure virtual functions not being implemented
};

