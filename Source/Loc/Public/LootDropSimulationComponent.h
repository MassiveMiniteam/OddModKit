#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "FixedInterval.h"
#include "SimulationActorComponent.h"
#include "OnLootDroppedDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "LootDropSimulationComponent.generated.h"

class ASimulationActor;
class UDataTable;
class UDespawnOnDeathSimulationComponent;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULootDropSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLootDroppedDelegate OnLootDropped;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* LootTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, UDataTable*> LootTableOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LootAmountOnDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LootAmountDueToDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLootUsesProjectileComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixedInterval ProjectileDuration;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FInt32Interval ProjectileHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ProjectileFlyRadiusMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ProjectileFlyRadiusMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ASimulationActor>> ActorLootForwarding;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UDespawnOnDeathSimulationComponent> DespawnOnDeathSimulation;
    
public:
    ULootDropSimulationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnGameplayStatChanged(UStatsComponent* StatsComp, FGameplayTag Tag, FFixed OldValue, FFixed NewValue);
    
    UFUNCTION(BlueprintCallable)
    void OnBeforeDespawn(UDespawnOnDeathSimulationComponent* DespawnComponent);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<TSubclassOf<ASimulationActor>> GetLootForwardingActors() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void DropMultipleItems(int32 NumDrops);
    
};

