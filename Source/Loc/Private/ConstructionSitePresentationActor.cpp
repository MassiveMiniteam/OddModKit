#include "ConstructionSitePresentationActor.h"
#include "Components/SceneComponent.h"

AConstructionSitePresentationActor::AConstructionSitePresentationActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Container"));
    this->Root = (USceneComponent*)RootComponent;
    this->SceneComponent_ReservedParent = CreateDefaultSubobject<USceneComponent>(TEXT("Parent_ReservedForConstruction"));
    this->SceneComponent_UnderConstructionParent = CreateDefaultSubobject<USceneComponent>(TEXT("Parent_UnderConstruction"));
    this->SceneComponent_FinishedParent = CreateDefaultSubobject<USceneComponent>(TEXT("Parent_Finished"));
    this->ConstructionSiteSimulationComponent = NULL;
    this->SceneComponent_FinishedParent->SetupAttachment(RootComponent);
    this->SceneComponent_ReservedParent->SetupAttachment(RootComponent);
    this->SceneComponent_UnderConstructionParent->SetupAttachment(RootComponent);
}

void AConstructionSitePresentationActor::OnConstructionStarted(UConstructionSiteObjectSimulationComponent* InConstructionSiteSimulationComponent) {
}

void AConstructionSitePresentationActor::OnConstructionSiteStateChanged(UConstructionSiteObjectSimulationComponent* InConstructionSiteSimulationComponent, EConstructionSiteState ConstructionSiteState) {
}

void AConstructionSitePresentationActor::OnConstructionFinished(UConstructionSiteObjectSimulationComponent* InConstructionSiteSimulationComponent) {
}





