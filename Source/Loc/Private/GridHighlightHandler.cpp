#include "GridHighlightHandler.h"
#include "StableInstancedStaticMeshComponent.h"

AGridHighlightHandler::AGridHighlightHandler(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StableInstancedStaticMeshComponent = CreateDefaultSubobject<UStableInstancedStaticMeshComponent>(TEXT("StableInstancedMeshComponent"));
    this->MeshType = NULL;
    this->Material = NULL;
}

void AGridHighlightHandler::SetMeshAndMaterial(UStaticMesh* InMesh, UMaterialInterface* InMaterial) {
}

void AGridHighlightHandler::HighlightGridPositions(const TArray<FIntPoint>& GridPositions) {
}


