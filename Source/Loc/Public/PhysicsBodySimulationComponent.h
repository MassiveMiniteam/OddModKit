#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationActorComponent.h"
#include "Templates/SubclassOf.h"
#include "PhysicsBodySimulationComponent.generated.h"

class UGameplayEffect;
class UPositionSimulationComponent;
class UProjectileSimulationComponent;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPhysicsBodySimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bBlockPositionUpdate;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntVector Velocity_Internal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntVector Velocity_LastFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UProjectileSimulationComponent> ProjectileComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayEffect> RammedIntoWallOrObjectGameplayEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinSpeedForTriggeringCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTestCollisionOnEdgeOfRadius;
    
public:
    UPhysicsBodySimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector GetCurrentVelocity() const;
    
    UFUNCTION(BlueprintCallable)
    void AddVelocity(FIntVector Velocity);
    
    UFUNCTION(BlueprintCallable)
    void AddForceDirectionAndScale(FIntVector ForceDirection, int32 ForceScale);
    
    UFUNCTION(BlueprintCallable)
    void AddForce(FIntVector Force);
    
};

