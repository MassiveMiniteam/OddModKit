#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DeveloperSettings.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "PatchingUnlockingBehaviour.h"
#include "TerraformLandscapeBlocker.h"
#include "LocDeveloperSettings.generated.h"

class AActor;
class ALocActor;
class ASimulationActor;
class UAchievement_BasicCount;
class UBiomeCellConfig;
class UBiomeConfig;
class UDataTable;
class UEndpointSubmix;
class UGameplayEffect;
class UGridTileGroundLayer;
class UGridTileLandscapeLayer;
class UGroundMeshMappingAsset;
class UInputContextBuild;
class UInventoryRule;
class ULocDeveloperSettings;
class URuntimeVirtualTexture;
class UUnlockableDataAsset;

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class LOC_API ULocDeveloperSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<EObjectTypeQuery>> DefaultTraceObjectTypes;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UEndpointSubmix> AudioBasedVibrationSubmix;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UEndpointSubmix> AudioFromControllerSubmix;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxDistanceToIncubatorForAdditionalInputs;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> Patching_DontDeleteClassesFromVillage;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> Patching_DeleteClassesFromVillage_Prio;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> Patching_ClassesDontCopyFromNewVillage;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPatchingUnlockingBehaviour> Patching_UnlockingBehaviours;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UBiomeCellConfig>> Patching_BiomeCellsThatSpawnedNoEnemiesBug;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, TSoftObjectPtr<UGroundMeshMappingAsset>> Patching_GrassGroundMeshMappings;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ASimulationActor> Patching_GrassSimulationActor;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> Patching_SpawnIfNotInGameplayMap;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ALocActor> Patching_ItemDropLocation;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAchievement_BasicCount> Achievement_ChooChoo;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UUnlockableDataAsset> Unlockable_Logic;
    
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInt32Interval TemperatureRange;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UGridTileGroundLayer>> NonWalkableGroundLayers;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UBiomeCellConfig>> FlatSeedCellsExceptions;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameplayTag> FlatSeedCellGameplayTagExceptions;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UBiomeConfig>> FlatSeedBiomeExceptions;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UBiomeCellConfig>> CaveEntranceCells;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UBiomeCellConfig>> CaveEntranceNeedNeighbourCells;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTerraformLandscapeBlocker> TerraformBlockerLandscapeLayers;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint TerraformHeightsAllowedInclusive;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UBiomeConfig>> TerraformBlockerBiomes;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<URuntimeVirtualTexture> VTEnvironmentTerrain;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UGridTileLandscapeLayer> LandscapeLayer_Lake;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UDataTable> EnemyHostilityValues;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UDataTable> EvolutionBudgetToVisualIndexMappingTable;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ASimulationActor>> AIPerceptionIgnoreDefaultClasses;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UInputContextBuild> BuildInputContextClass;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> BossClass;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> LootDropWhiteListClasses;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UInventoryRule>> DefaultInventoryRules;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UGameplayEffect> GameplayEffect_PlayerIsOffline;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CorruptionMarkerMinimumDistance;
    
    ULocDeveloperSettings();

    UFUNCTION(BlueprintCallable)
    static ULocDeveloperSettings* GetLocDeveloperSettings();
    
};

