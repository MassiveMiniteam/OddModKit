#include "LocGameState.h"
#include "Templates/SubclassOf.h"

ALocGameState::ALocGameState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Grid = NULL;
    this->NavRootWidget = NULL;
    this->ProceduralTerrainManager = NULL;
    this->SharedWorldActor = NULL;
    this->bAIDebugFloatingTextIsEnabled = false;
    this->MapSeed = 0;
    this->GridTileRuleTable = NULL;
}

void ALocGameState::ShopTokenCalculation(int32 Level) {
}

void ALocGameState::Setup(int32 Seed, bool bIsLoading, FWorldGenerationInfo& InOutWorldGenerationInfoo, bool bRerollInvalidSeed) {
}

void ALocGameState::SetNavRootWidget(UNavRootCanvasWidget* InNavRootWidget) {
}


void ALocGameState::OnPlayerLogout(AController* Controller) {
}


void ALocGameState::LocUnmountPakFile(const FString& Path) {
}

void ALocGameState::LocUnlock(UUnlockableDataAsset* UnlockableDataAsset) {
}

void ALocGameState::LocTogglePlayerGravity() {
}

void ALocGameState::LocTimeDilation(float Scale) {
}

void ALocGameState::LocTestObjectPath(const FString& Path) {
}

void ALocGameState::LocTestDesyncSentryReport() {
}

void ALocGameState::LocTestAddHeight(int32 Height) {
}

void ALocGameState::LocTeleportToRandomInfiniteResource(const FString& ResourceName) {
}

void ALocGameState::LocTeleportToRandomBiome(const FString& BiomeName) {
}

void ALocGameState::LocTeleport(int32 X, int32 Y) {
}

void ALocGameState::LocStealPlayerInventories() {
}

void ALocGameState::LocStatDumpFrame() {
}

void ALocGameState::LocSimulateAutosave() {
}

void ALocGameState::LocSetSimpleHashMode(bool bSimpleHashMode) {
}

void ALocGameState::LocSetPlayerStatSim(const FString& TagString, float Value) {
}

void ALocGameState::LocSetFixedUpdateDisabled(bool bDisabled) {
}

void ALocGameState::LocSetComponentTickEnabled(const FString& ComponentName, bool bEnableTick) {
}

void ALocGameState::LocSetActorTickEnabled(const FString& ActorName, bool bEnableTick) {
}

void ALocGameState::LocScanSynchronous(const FString& Path, bool bForce) {
}

void ALocGameState::LocScanModifiedAssetFiles(const FString& Path) {
}

void ALocGameState::LocReserializeObject(const FString& From, const FString& To) {
}

void ALocGameState::LocReloadLibraries() {
}

void ALocGameState::LocRefreshEntitlements() {
}

void ALocGameState::LocPatchCaveEntrance(TSubclassOf<ASimulationActor> CaveEntranceSimulationActor, UBiomeCellConfig* EntranceCell) {
}

void ALocGameState::LocOnlineExec(const FString& Exec) {
}

void ALocGameState::LocMountPakFile(const FString& Path, int32 Order, const FString& MountPoint) {
}

void ALocGameState::LocLogTicks() {
}

void ALocGameState::LocLogSimulationActors() {
}

void ALocGameState::LocLogPathNetworks() {
}

void ALocGameState::LocLogAllUnlockables() {
}

void ALocGameState::LocLogAllMetaSpawns() {
}

void ALocGameState::LocLogActorPool() {
}

void ALocGameState::LocLoadSeedAndPos(int32 Seed, int32 X, int32 Y) {
}

void ALocGameState::LocLoadRecording(const FString& Filename, bool bForceLoad, bool bIgnoreDesync) {
}

void ALocGameState::LocLoadCommands(const FString& Filename) {
}

void ALocGameState::LocLoadAssetRegistry(const FString& PakPath) {
}

void ALocGameState::LocListPakContents(const FString& Path) {
}

void ALocGameState::LocListAssetTypes(UClass* Class, const FString& Path) {
}

void ALocGameState::LocJoinSessionWithRoomCode(const FString& RoomCode) {
}

void ALocGameState::LocEnableInputConsumptionLogging() {
}

void ALocGameState::LocDrawPlayerPaths(const FString& Path) {
}

void ALocGameState::LocDesync() {
}

void ALocGameState::LocDestroyPresentationActors(UClass* ActorClass) {
}

void ALocGameState::LocDestroyComponentsWithComponentName(const FString& ComponentName) {
}

void ALocGameState::LocDestroyComponentsWithClassName(const FString& ComponentName) {
}

void ALocGameState::LocDestroyAll(TSubclassOf<AActor> aClass) {
}

void ALocGameState::LocDecompressDesyncReport(const FString& Path) {
}

void ALocGameState::LocCopyUserLogsToSharedDrive(int32 DaysInPast) {
}

void ALocGameState::LocClearLibraries() {
}

ASharedWorldActor* ALocGameState::GetSharedWorldActor(const UObject* WorldContext) {
    return NULL;
}

AProceduralTerrainManager* ALocGameState::GetProceduralTerrainManager(const UObject* WorldContext) {
    return NULL;
}

UNavRootCanvasWidget* ALocGameState::GetNavRootWidget() const {
    return NULL;
}

void ALocGameState::DesyncVerifyDebuggerDumps(const FString& DirectoryName, const FString& Filename) {
}

void ALocGameState::DesyncDebuggerStopDump() {
}

void ALocGameState::DesyncDebuggerStartDump() {
}

bool ALocGameState::CanTickSimulation() {
    return false;
}


