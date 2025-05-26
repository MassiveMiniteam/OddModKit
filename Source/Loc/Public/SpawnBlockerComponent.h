#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "SimulationActorComponent.h"
#include "Templates/SubclassOf.h"
#include "SpawnBlockerComponent.generated.h"

class ASimulationActor;
class UPositionSimulationComponent;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API USpawnBlockerComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ASimulationActor>> BlockedClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BlockRadius;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPositionSimulationComponent* PositionSimulationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatsComponent* StatsComponent;
    
public:
    USpawnBlockerComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnStatBoolRemoved(UStatsComponent* InStatsComponent, FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    void OnStatBoolAdded(UStatsComponent* InStatsComponent, FGameplayTag Tag);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWorldPositionInRange(const FIntVector& WorldPosition) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBlocked(const FIntVector& WorldPosition, TSoftClassPtr<ASimulationActor> ActorClass) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DoesCareAboutClass(TSoftClassPtr<ASimulationActor> ActorClass) const;
    
};

