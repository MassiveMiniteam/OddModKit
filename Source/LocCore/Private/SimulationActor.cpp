#include "SimulationActor.h"

ASimulationActor::ASimulationActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bEnableTick = false;
    this->bPerformance_OnTickSimulationImplemented = false;
    this->bIgnoreInPlacementRules = false;
    this->bShouldSave = true;
    this->bIsGenerated = false;
    this->bKeepAliveWhenSpawnedProcedurally = false;
    this->bIsRegistered = false;
    this->bIsPooled = false;
    this->bIsSleeping = false;
    this->bDestroyPresentationOnSimEnd = true;
    this->bOnlySpawnPresentationOnServer = false;
    this->bPoolSimulationActor = false;
    this->bPoolPresentationActor = false;
    this->bAsyncSpawnPresentationActor = true;
    this->AsyncSpawnPresentationPriority = ELoadBalancerTaskPriority::Normal;
    this->bInitializedPresentation = false;
    this->bPresentationLoadRequested = false;
    this->bHasSetupPresentation = false;
}

void ASimulationActor::SetPresentationActor(TScriptInterface<IPresentationObjectInterface> PresentationObjectInterface) {
}

void ASimulationActor::SetEnableTick(bool bEnable) {
}

void ASimulationActor::OnTickSimulation_Implementation(FFixed DeltaTime) {
}

void ASimulationActor::OnSimulationPreBegin_Implementation(bool bIsLoading) {
}

void ASimulationActor::OnSimulationEnd_Implementation(EDestructionReason Reason) {
}

void ASimulationActor::OnSimulationBegin_Implementation(bool bIsLoading) {
}

void ASimulationActor::OnlySebastianIsAllowedToUseThisFunction(FText Name, FText Description, TSoftObjectPtr<UTexture2D> Icon) {
}

FString ASimulationActor::GetRichTextId() const {
    return TEXT("");
}

AActor* ASimulationActor::GetPresentationActorChecked() const {
    return NULL;
}

AActor* ASimulationActor::GetPresentationActorBranched(EValidityState& ValidityState) const {
    return NULL;
}

TScriptInterface<IPresentationObjectInterface> ASimulationActor::GetPresentationActor() const {
    return NULL;
}

int32 ASimulationActor::GetNumberOfTickingComponents() const {
    return 0;
}

FText ASimulationActor::GetLocName() const {
    return FText::GetEmpty();
}

TSoftObjectPtr<UTexture2D> ASimulationActor::GetLocIcon() const {
    return NULL;
}

FText ASimulationActor::GetLocDescription() const {
    return FText::GetEmpty();
}

bool ASimulationActor::GetIsTickingEnabled() const {
    return false;
}

bool ASimulationActor::GetIsPooled() const {
    return false;
}


