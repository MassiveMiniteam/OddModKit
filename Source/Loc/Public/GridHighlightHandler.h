#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "GridHighlightHandler.generated.h"

class UMaterialInterface;
class UStableInstancedStaticMeshComponent;
class UStaticMesh;

UCLASS(Blueprintable)
class LOC_API AGridHighlightHandler : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStableInstancedStaticMeshComponent* StableInstancedStaticMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* MeshType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Material;
    
public:
    AGridHighlightHandler(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetMeshAndMaterial(UStaticMesh* InMesh, UMaterialInterface* InMaterial);
    
    UFUNCTION(BlueprintCallable)
    void HighlightGridPositions(const TArray<FIntPoint>& GridPositions);
    
};

