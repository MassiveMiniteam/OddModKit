#include "SimulationTimerComponent.h"

USimulationTimerComponent::USimulationTimerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
    this->bStartTickEnabled = false;
    this->bForceTicking = false;
    this->bIsRunning = false;
    this->bIsCurrentlyLooping = false;
    this->bIsPaused = false;
}

void USimulationTimerComponent::StopAndReset() {
}

void USimulationTimerComponent::SetupAndStart(FFixed Duration, bool bIsLooping) {
}

void USimulationTimerComponent::SetTimeDilation(FFixed NewDialation) {
}

void USimulationTimerComponent::ResetElapsedTime() {
}

void USimulationTimerComponent::Pause(bool NewIsPaused) {
}

void USimulationTimerComponent::OverwriteCurrentDuration(FFixed NewDuration) {
}


bool USimulationTimerComponent::IsRunningAndNotPaused() const {
    return false;
}

bool USimulationTimerComponent::IsRunning() const {
    return false;
}

bool USimulationTimerComponent::IsPaused() const {
    return false;
}

bool USimulationTimerComponent::IsCurrentlyLooping() const {
    return false;
}

FFixed USimulationTimerComponent::GetCurrentTimeDilation() const {
    return FFixed{};
}

FFixed USimulationTimerComponent::GetCurrentProgress() const {
    return FFixed{};
}

FFixed USimulationTimerComponent::GetCurrentElapsedTime() const {
    return FFixed{};
}

FFixed USimulationTimerComponent::GetCurrentDurationWithDilation() const {
    return FFixed{};
}

FFixed USimulationTimerComponent::GetCurrentDuration() const {
    return FFixed{};
}


