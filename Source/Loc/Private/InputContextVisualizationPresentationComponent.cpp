#include "InputContextVisualizationPresentationComponent.h"

UInputContextVisualizationPresentationComponent::UInputContextVisualizationPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InputContext = NULL;
}

void UInputContextVisualizationPresentationComponent::VisualizeInputContext(UInputContext* InInputContext) {
}

void UInputContextVisualizationPresentationComponent::TickVisualization(UInputContext* InInputContext, float DeltaTime) {
}

void UInputContextVisualizationPresentationComponent::StopVisualizazion(UInputContext* InInputContext) {
}





