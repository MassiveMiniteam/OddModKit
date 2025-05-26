#include "MinionControllerSimulationBaseComponent.h"

UMinionControllerSimulationBaseComponent::UMinionControllerSimulationBaseComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OnLoadOutSwapProgressChanged = NULL;
    this->bEnableUnitSpawning = true;
    this->bDisablePushback = false;
    this->bRespawnOnRelocate = false;
    this->DeployMinionsDirectlyOnInventorySlotChange = false;
    this->bAllowTakeoverByOtherMinionController = false;
    this->bIsLoadOutSwapPossible = false;
}

void UMinionControllerSimulationBaseComponent::UnregisterToMinionDelegates(ASimulationActor* Minion) {
}

bool UMinionControllerSimulationBaseComponent::TryAddAlreadySpawnedMinion(ASimulationActor* Minion) {
    return false;
}

void UMinionControllerSimulationBaseComponent::TriggerLoadOutSwap() {
}

void UMinionControllerSimulationBaseComponent::ThrowMinion(ASimulationActor* Minion, FProjectileParameters ThrowProperties) {
}

void UMinionControllerSimulationBaseComponent::SpawnUnitsByClass(UItemMinionConfig* Config, int32 AmountToBeSpawned, ASimulationManager* SimulationManager) {
}

void UMinionControllerSimulationBaseComponent::SpawnUnits(const FMinionControlGroup& ControlGroup, int32 AmountToBeSpawned, ASimulationManager* SimulationManager) {
}

void UMinionControllerSimulationBaseComponent::SpawnAllNotSpawnedUnits() {
}

void UMinionControllerSimulationBaseComponent::RequestLoadOutSwap(UInventoryComponent* LoadOut) {
}

void UMinionControllerSimulationBaseComponent::RemoveMinion(ASimulationActor* Minion) {
}

void UMinionControllerSimulationBaseComponent::RegisterToMinionDelegates(ASimulationActor* Minion) {
}

void UMinionControllerSimulationBaseComponent::OnUnitSpawned_Implementation(ASimulationActor* Minion) {
}

void UMinionControllerSimulationBaseComponent::OnSimulationActorShutDown(ASimulationActor* Minion, EDestructionReason Reason) {
}

void UMinionControllerSimulationBaseComponent::OnRelocated(UPositionSimulationComponent* PositionComponent, FIntPoint LastGridPosition) {
}

void UMinionControllerSimulationBaseComponent::OnMinionStateGroupChanged(UBTStateMachineComponent* StateMachine, FGameplayTag StateGroupTag) {
}

void UMinionControllerSimulationBaseComponent::OnMinionStatDead(UStatsComponent* StatsComponent) {
}

void UMinionControllerSimulationBaseComponent::OnMinionStatChanged(UStatsComponent* StatsComponent, FGameplayTag Tag, FFixed OldValue, FFixed NewValue) {
}

void UMinionControllerSimulationBaseComponent::OnMinionInventoryUpdated(int32 InventorySlotIndex) {
}

void UMinionControllerSimulationBaseComponent::OnControlGroupTagChanged(UControllableMinionSimulationComponent* ControllableMinionComponent) {
}

bool UMinionControllerSimulationBaseComponent::IsLoadOutSwapPossible() const {
    return false;
}

bool UMinionControllerSimulationBaseComponent::IsLoadOutSwapInProgress() const {
    return false;
}

int32 UMinionControllerSimulationBaseComponent::GetNumSlots() const {
    return 0;
}

UItemMinionConfig* UMinionControllerSimulationBaseComponent::GetMinionConfig(int32 MinionSlotIndex) const {
    return NULL;
}

UInventoryComponent* UMinionControllerSimulationBaseComponent::GetLoadOutSwapToInventory() const {
    return NULL;
}

TArray<ASimulationActor*> UMinionControllerSimulationBaseComponent::GetDeployedMinionsForTagPair(FMinionConfigTagPair ConfigTagPair) {
    return TArray<ASimulationActor*>();
}

int32 UMinionControllerSimulationBaseComponent::GetDeployedMinionCountInTaggedGroups(UItemConfig* Config) const {
    return 0;
}

int32 UMinionControllerSimulationBaseComponent::GetDeployedMinionCount(int32 MinionSlotIndex) const {
    return 0;
}

int32 UMinionControllerSimulationBaseComponent::GetControlGroupIndex(FMinionConfigTagPair MinionConfigTagPair) {
    return 0;
}

ASimulationActor* UMinionControllerSimulationBaseComponent::GetClosestControlledMinion(const FIntVector& QueryPosition) const {
    return NULL;
}

TArray<ASimulationActor*> UMinionControllerSimulationBaseComponent::GetAllDeployedMinionsWithStat(FGameplayTag StatTag) const {
    return TArray<ASimulationActor*>();
}

TArray<ASimulationActor*> UMinionControllerSimulationBaseComponent::GetAllDeployedMinionsWithoutGroupTag() const {
    return TArray<ASimulationActor*>();
}

TArray<ASimulationActor*> UMinionControllerSimulationBaseComponent::GetAllDeployedMinions() const {
    return TArray<ASimulationActor*>();
}

UInventoryComponent* UMinionControllerSimulationBaseComponent::GetActiveLoadOutInventory() const {
    return NULL;
}

void UMinionControllerSimulationBaseComponent::DespawnUnits(const FMinionControlGroup& ControlGroup, int32 AmountToBeDespawned, ASimulationManager* SimulationManager) {
}

void UMinionControllerSimulationBaseComponent::DespawnAllUnits() {
}

TArray<FItemStack> UMinionControllerSimulationBaseComponent::ComputeDifferenceOfMinionsInControlGroupsAndInventory() const {
    return TArray<FItemStack>();
}

bool UMinionControllerSimulationBaseComponent::AllowsTakeoverByOtherMinionController() const {
    return false;
}

void UMinionControllerSimulationBaseComponent::AddMinion(ASimulationActor* Minion) {
}


