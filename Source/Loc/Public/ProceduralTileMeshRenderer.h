#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ISMTileLayerKey.h"
#include "ProceduralTileMeshRenderer.generated.h"

class UGridTileLayerAsset;
class UStableInstancedStaticMeshComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UProceduralTileMeshRenderer : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStableInstancedStaticMeshComponent*> ISMToDirty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<FISMTileLayerKey, UStableInstancedStaticMeshComponent*> ISMComponents;
    
    UProceduralTileMeshRenderer(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnAddedInstancedStaticMeshComponent(UStableInstancedStaticMeshComponent* InstancedStaticMeshComponent, UGridTileLayerAsset* ForLayer, UGridTileLayerAsset* ForLandscapeLayer, UGridTileLayerAsset* BelongPhysicsLayer);
    
};

