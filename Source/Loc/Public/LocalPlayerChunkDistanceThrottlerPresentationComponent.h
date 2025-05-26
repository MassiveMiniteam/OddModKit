#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PresentationActorComponent.h"
#include "LocalPlayerChunkDistanceThrottlerPresentationComponent.generated.h"

class UChunkSpawnerSimulationComponent;
class UGridChunk;
class UPositionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULocalPlayerChunkDistanceThrottlerPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionSimulationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UChunkSpawnerSimulationComponent> ChunkSpawnerSimulation;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGridChunk*> CurrentChunks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint LoadSize;
    
public:
    ULocalPlayerChunkDistanceThrottlerPresentationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnGridPositionChanged(UPositionSimulationComponent* PositionComponent, FIntPoint LastGridPosition);
    
    UFUNCTION(BlueprintCallable)
    void OnChunksUpdated();
    
};

