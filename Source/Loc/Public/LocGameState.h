#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LocCoreGameState.h"
#include "EGridBiome.h"
#include "GridTileRule.h"
#include "Templates/SubclassOf.h"
#include "WorldGenerationInfo.h"
#include "LocGameState.generated.h"

class AActor;
class AController;
class AGrid;
class AProceduralTerrainManager;
class ASharedWorldActor;
class ASimulationActor;
class UBiomeCellConfig;
class UDataTable;
class UNavRootCanvasWidget;
class UObject;
class UUnlockableDataAsset;

UCLASS(Blueprintable)
class LOC_API ALocGameState : public ALocCoreGameState {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AGrid* Grid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNavRootCanvasWidget* NavRootWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AProceduralTerrainManager* ProceduralTerrainManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASharedWorldActor* SharedWorldActor;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAIDebugFloatingTextIsEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MapSeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* GridTileRuleTable;
    
    ALocGameState(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, Exec)
    void ShopTokenCalculation(int32 Level);
    
    UFUNCTION(BlueprintCallable)
    void Setup(int32 Seed, bool bIsLoading, FWorldGenerationInfo& InOutWorldGenerationInfoo, bool bRerollInvalidSeed);
    
    UFUNCTION(BlueprintCallable)
    void SetNavRootWidget(UNavRootCanvasWidget* InNavRootWidget);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTileRule(FIntPoint GridPos, int32 Rotation, const FGridTileRule& TileRule);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPlayerLogout(AController* Controller);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDualGridCell(FIntPoint TopLeftGridPos, EGridBiome BiomeTopLeft, EGridBiome BiomeTopRight, EGridBiome BiomeBottomLeft, EGridBiome BiomeBottomRight);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocUnmountPakFile(const FString& Path);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocUnlock(UUnlockableDataAsset* UnlockableDataAsset);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocTogglePlayerGravity();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocTimeDilation(float Scale);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocTestObjectPath(const FString& Path);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocTestDesyncSentryReport();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocTestAddHeight(int32 Height);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocTeleportToRandomInfiniteResource(const FString& ResourceName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocTeleportToRandomBiome(const FString& BiomeName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocTeleport(int32 X, int32 Y);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocStealPlayerInventories();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocStatDumpFrame();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocSimulateAutosave();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocSetSimpleHashMode(bool bSimpleHashMode);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocSetPlayerStatSim(const FString& TagString, float Value);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocSetFixedUpdateDisabled(bool bDisabled);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocSetComponentTickEnabled(const FString& ComponentName, bool bEnableTick);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocSetActorTickEnabled(const FString& ActorName, bool bEnableTick);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocScanSynchronous(const FString& Path, bool bForce);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocScanModifiedAssetFiles(const FString& Path);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocReserializeObject(const FString& From, const FString& To);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocReloadLibraries();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocRefreshEntitlements();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocPatchCaveEntrance(TSubclassOf<ASimulationActor> CaveEntranceSimulationActor, UBiomeCellConfig* EntranceCell);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocOnlineExec(const FString& Exec);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocMountPakFile(const FString& Path, int32 Order, const FString& MountPoint);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocLogTicks();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocLogSimulationActors();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocLogPathNetworks();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocLogAllUnlockables();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocLogAllMetaSpawns();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocLogActorPool();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocLoadSeedAndPos(int32 Seed, int32 X, int32 Y);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocLoadRecording(const FString& Filename, bool bForceLoad, bool bIgnoreDesync);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocLoadCommands(const FString& Filename);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocLoadAssetRegistry(const FString& PakPath);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocListPakContents(const FString& Path);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocListAssetTypes(UClass* Class, const FString& Path);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocJoinSessionWithRoomCode(const FString& RoomCode);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocEnableInputConsumptionLogging();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocDrawPlayerPaths(const FString& Path);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocDesync();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocDestroyPresentationActors(UClass* ActorClass);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocDestroyComponentsWithComponentName(const FString& ComponentName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocDestroyComponentsWithClassName(const FString& ComponentName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocDestroyAll(TSubclassOf<AActor> aClass);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocDecompressDesyncReport(const FString& Path);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocCopyUserLogsToSharedDrive(int32 DaysInPast);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocClearLibraries();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static ASharedWorldActor* GetSharedWorldActor(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static AProceduralTerrainManager* GetProceduralTerrainManager(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UNavRootCanvasWidget* GetNavRootWidget() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void DesyncVerifyDebuggerDumps(const FString& DirectoryName, const FString& Filename);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DesyncDebuggerStopDump();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DesyncDebuggerStartDump();
    
protected:
    UFUNCTION(BlueprintCallable)
    bool CanTickSimulation();
    
};

