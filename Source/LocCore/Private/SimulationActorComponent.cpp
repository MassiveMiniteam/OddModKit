#include "SimulationActorComponent.h"

USimulationActorComponent::USimulationActorComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bPerformance_OnSimulationBeginImplemented = false;
    this->bPerformance_OnSimulationPreBeginImplemented = false;
    this->bPerformance_OnSimulationEndImplemented = false;
    this->bPredictionKeepAlwaysAlive = false;
    this->bIsPredictedComponent = false;
    this->PredictionTimeoutCounter = 0;
    this->bCanEverTick = false;
    this->bStartTickEnabled = true;
    this->bIsTickEnabled = true;
}

void USimulationActorComponent::SetTickEnabled(bool bShouldTick) {
}

void USimulationActorComponent::OnSimulationPreBegin_Implementation(bool bIsLoading) {
}

void USimulationActorComponent::OnSimulationEnd_Implementation(EDestructionReason Reason) {
}

void USimulationActorComponent::OnSimulationBegin_Implementation(bool bIsLoading) {
}

void USimulationActorComponent::OnSetPresentationActor() {
}

void USimulationActorComponent::OnDestroyingPresentationActor() {
}

void USimulationActorComponent::OnCreatedAsPredictionComponent() {
}

bool USimulationActorComponent::GetSupportsPrediction_Implementation() {
    return false;
}


