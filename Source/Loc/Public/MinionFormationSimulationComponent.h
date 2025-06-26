#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "MinionConfigDataMapping.h"
#include "WeakActorArray.h"
#include "MinionFormationSimulationComponent.generated.h"

class ASimulationActor;
class UMovementTrackerSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMinionFormationSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<FMinionConfigDataMapping, FWeakActorArray> FollowingMinions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DistanceToLeader;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UMovementTrackerSimulationComponent> MovementTrackerComponent;
    
public:
    UMinionFormationSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateMinionSlots();
    
    UFUNCTION(BlueprintCallable)
    void RemoveMinion(ASimulationActor* Minion);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnLeaderPositionChanged();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FWeakActorArray GetMinionsInFormationOfType(const FMinionConfigDataMapping& MinionConfigDataMapping) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMinionIsFollowing(const ASimulationActor* Minion) const;
    
    UFUNCTION(BlueprintCallable)
    void AddMinion(ASimulationActor* Minion);
    
};

