#include "SimulationManager.h"
#include "Templates/SubclassOf.h"

ASimulationManager::ASimulationManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PredictionTimeoutFrames = 60;
    this->bHasBegunSimulation = false;
    this->bIsCurrentlyResettingPredictedComponents = false;
    this->CurrentFrameStartTime = 0.00f;
    this->NameIndexCounter = 1;
    this->HashCounter = 0;
    this->SimulationActorTickIndex = 0;
    this->ActorTicksPerSubTick = 0;
    this->ActorHashesPerFrame = 20;
    this->bForceDesync = false;
}

void ASimulationManager::UnregisterSimulationActorHook(UClass* Class, TSubclassOf<USimulationActorHook> Hook) {
}

void ASimulationManager::UnregisterSimulationActor(ASimulationActor* SimulationActor, EDestructionReason Reason) {
}

ASimulationActor* ASimulationManager::SpawnSimulationActorWithoutRegisteringWithName(TSubclassOf<ASimulationActor> Class, FName Name, FIntVector CenterLocation, int32 Rotation) {
    return NULL;
}

ASimulationActor* ASimulationManager::SpawnSimulationActorWithoutRegistering(TSubclassOf<ASimulationActor> Class, FIntVector CenterLocation, int32 Rotation) {
    return NULL;
}

ASimulationActor* ASimulationManager::SpawnSimulationActor(TSubclassOf<ASimulationActor> Class, FIntVector CenterLocation, int32 Rotation, bool bForceSyncPresentationActorSpawn) {
    return NULL;
}

bool ASimulationManager::RollChanceInPercent(int32 Chance) {
    return false;
}

void ASimulationManager::ReleaseComponentPrediction(USimulationActorComponent* Component) {
}

void ASimulationManager::RegisterSimulationActorHook(UClass* Class, TSubclassOf<USimulationActorHook> Hook) {
}

void ASimulationManager::RegisterSimulationActor(ASimulationActor* SimulationActor, bool bIsLoading, bool bForceSyncPresentationActorSpawn) {
}

TArray<ASimulationActor*> ASimulationManager::GetSimulationActors() const {
    return TArray<ASimulationActor*>();
}

TArray<TSubclassOf<USimulationActorHook>> ASimulationManager::GetSimulationActorHooks(UClass* Class) {
    return TArray<TSubclassOf<USimulationActorHook>>();
}

FIntPoint ASimulationManager::GetRandomIntPointUniformDistributedOnRing(FInt32Interval Range) {
    return FIntPoint{};
}

FIntPoint ASimulationManager::GetRandomIntPointUniformDistributedOnCircle(int32 Radius) {
    return FIntPoint{};
}

FIntPoint ASimulationManager::GetRandomIntPointInRingThatIsAlsoOnCircle(FIntPoint RingOrigin, FInt32Interval RingRadii, FIntPoint CircleOrigin, int32 CircleRadius) {
    return FIntPoint{};
}

int32 ASimulationManager::GetRandomIntegerInRange(int32 min, int32 max) {
    return 0;
}

int32 ASimulationManager::GetRandomInteger() {
    return 0;
}

USimulationActorComponent* ASimulationManager::GetPredictedActorComponentIfPossible(USimulationActorComponent* Component) {
    return NULL;
}

USimulationActorComponent* ASimulationManager::GetPredictedActorComponent(USimulationActorComponent* Component) {
    return NULL;
}

TArray<FIntPoint> ASimulationManager::GetMostBusyPositions(int32 Num, float Radius) {
    return TArray<FIntPoint>();
}

void ASimulationManager::DestroySimulationActor(ASimulationActor* SimulationActor, EDestructionReason Reason) {
}

void ASimulationManager::CreateComponentPrediction(USimulationActorComponent* Component) {
}

void ASimulationManager::ClearSimulation() {
}


