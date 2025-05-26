#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "PresetSpawnerConditionComponent.generated.h"

class UPresetSpawnerSimulationComponent;
class UUnlockHandlingSimulationComponent;
class UUnlockableDataAsset;
class UVillageLoadSimulationSubsystem;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPresetSpawnerConditionComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UUnlockableDataAsset*> SpawnPrerequisites;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UUnlockableDataAsset*> DespawnPrerequisites;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UUnlockHandlingSimulationComponent> UnlockHandler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPresetSpawnerSimulationComponent> PresetSpawner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UVillageLoadSimulationSubsystem> VillageSubsystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnlockOnVillageLoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsSpawned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsDespawned;
    
public:
    UPresetSpawnerConditionComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnVillageUnloaded(UVillageLoadSimulationSubsystem* InVillageSubsystem);
    
    UFUNCTION(BlueprintCallable)
    void OnVillageLoading(UVillageLoadSimulationSubsystem* InVillageSubsystem);
    
    UFUNCTION(BlueprintCallable)
    void OnVillageLoaded(UVillageLoadSimulationSubsystem* InVillageSubsystem);
    
    UFUNCTION(BlueprintCallable)
    void OnItemUnlock(UUnlockableDataAsset* UnlockableDataAsset);
    
};

