#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "EFactionType.h"
#include "OnPerceivedActorsUpdatedDelegate.h"
#include "Templates/SubclassOf.h"
#include "AIPerceptionSimulationComponent.generated.h"

class AGrid;
class ASimulationActor;
class UGameplayAbility;
class UItemConfig;
class UPathFinderComponent;
class UPositionSimulationComponent;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UAIPerceptionSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPerceivedActorsUpdated OnPerceivedActorsUpdated;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreDefaultActorClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASimulationActor*> PerceivedActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPathFinderComponent> PathFinderComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AGrid> Grid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 NumFramesSinceLastUpdate;
    
public:
    UAIPerceptionSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCostForTargetingActorWithAbility(const ASimulationActor* Actor, TSubclassOf<UGameplayAbility> Ability) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASimulationActor* GetClosestPickUpItem(TArray<UItemConfig*> OptionalWhitelist, bool bIgnoreReservedStat) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASimulationActor* GetClosestAttackableActorWithIgnoreTags(TSubclassOf<UGameplayAbility> Ability, TArray<EFactionType> OptionalFactionWhiteList, TArray<FGameplayTag> IgnoreTags, bool OnlyPrey, bool bOnlyTargetsThatAreAlreadyInCombatWithMyFaction, int32 MaxDistanceOverride) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASimulationActor* GetClosestAttackableActor(TSubclassOf<UGameplayAbility> Ability, TArray<EFactionType> OptionalFactionWhiteList, bool OnlyPrey, bool bOnlyTargetsThatAreAlreadyInCombatWithMyFaction, int32 MaxDistanceOverride) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASimulationActor* GetClosestActorThatConsidersMeAsPrey() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<ASimulationActor*> GetAttackableActorsInRange(int32 Range, TSubclassOf<UGameplayAbility> Ability) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<ASimulationActor*> GetAllPerceivedActors() const;
    
};

