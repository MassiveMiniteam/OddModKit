#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "SimulationActorComponent.h"
#include "TrainTracksPoleConnectionSimulationComponent.generated.h"

class ASimulationPlayer;
class UConstructionAssemblySimulationComponent;
class USceneComponent;
class UTrainTrackSegmentSimulationComponent;
class UTrainTracksPoleBaseSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTrainTracksPoleConnectionSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTrainTracksPoleBaseSimulationComponent* CachedOwnerPole;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTrainTrackSegmentSimulationComponent> ConnectedSegment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UConstructionAssemblySimulationComponent* MyAssemblyComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference SceneComponentReference_PoleCenter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference SceneComponentReference_OuterSplinePoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector OuterSplinePointOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector OuterSplinePointTangent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector PoleCenterTangent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference RequiredConnection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FComponentReference> ForbiddenConnections;
    
public:
    UTrainTracksPoleConnectionSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetConnection(UTrainTrackSegmentSimulationComponent* Segment);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnDisassmble(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingSimulationPlayer);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsConnected() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrainTracksPoleBaseSimulationComponent* GetPoleComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector GetPoleCenterTangent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector GetOuterSplinePointTangent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector GetOuterSplinePointOffset() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrainTrackSegmentSimulationComponent* GetConnectedSegment() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USceneComponent* GetAttachmentScene_PoleCenter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USceneComponent* GetAttachmentScene_OuterSplinePoint() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanBeConnected() const;
    
};

