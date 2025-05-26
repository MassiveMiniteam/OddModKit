#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LocSimulationSubsystem.h"
#include "SpawnBlockerSubsystemEventDelegate.h"
#include "SpawnBlockerSimulationSubsystem.generated.h"

class ASimulationActor;
class USpawnBlockerComponent;

UCLASS(Blueprintable)
class LOC_API USpawnBlockerSimulationSubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnBlockerSubsystemEvent OnSpawnBlockerAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnBlockerSubsystemEvent OnSpawnBlockerRemoved;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<USpawnBlockerComponent>> Blockers;
    
    USpawnBlockerSimulationSubsystem();

    UFUNCTION(BlueprintCallable)
    void RemoveSpawnBlocker(USpawnBlockerComponent* Blocker);
    
    UFUNCTION(BlueprintCallable)
    bool IsSpawnBlockerInRange(const FIntVector& WorldPosition);
    
    UFUNCTION(BlueprintCallable)
    bool IsSpawnBlocked(const FIntVector& WorldPosition, TSoftClassPtr<ASimulationActor> ActorClass);
    
    UFUNCTION(BlueprintCallable)
    void AddSpawnBlocker(USpawnBlockerComponent* Blocker);
    
};

