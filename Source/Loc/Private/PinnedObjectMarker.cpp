#include "PinnedObjectMarker.h"
#include "PlayerIdentificationSimulationReferenceComponent.h"
#include "PositionAttachmentSimulationComponent.h"
#include "PositionSimulationComponent.h"

APinnedObjectMarker::APinnedObjectMarker(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bEnableTick = true;
    this->PositionComponent = CreateDefaultSubobject<UPositionSimulationComponent>(TEXT("position"));
    this->PlayerIdentificationReference = CreateDefaultSubobject<UPlayerIdentificationSimulationReferenceComponent>(TEXT("PlayerIdentificationReference"));
    this->PositionAttachmentSimulationComponent = CreateDefaultSubobject<UPositionAttachmentSimulationComponent>(TEXT("PositionAttachment"));
}

void APinnedObjectMarker::SetTarget(UMapIconSimulationComponent* InMapIconComponent, UPositionSimulationComponent* InPositionComponent) {
}


