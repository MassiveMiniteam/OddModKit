#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationActorComponent.h"
#include "CopyToolUseable.h"
#include "OnPoleConnectionsChanged_DelegateDelegate.h"
#include "OnPolePositionOffsetChanged_DelegateDelegate.h"
#include "TrainAgentPole_DelegateDelegate.h"
#include "TrainTracksPoleBaseSimulationComponent.generated.h"

class UTrainTrackSegmentSimulationComponent;
class UTrainTracksAgentSimulationComponent;
class UTrainTracksPoleBaseSimulationComponent;
class UTrainTracksPoleConnectionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTrainTracksPoleBaseSimulationComponent : public USimulationActorComponent, public ICopyToolUseable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrainAgentPole_Delegate OnTrainAgentReachedThisPole_Delegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrainAgentPole_Delegate OnTrainAgentStopsMovementOnThisPole_Delegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrainAgentPole_Delegate OnTrainAgentStartsMovementOnThisPole_Delegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPolePositionOffsetChanged_Delegate OnPolePositionOffsetChanged_Delegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPoleConnectionsChanged_Delegate OnPoleConnectionsChanged_Delegate;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UTrainTracksPoleConnectionSimulationComponent*> Connections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector PositionOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntVector PositionOffsetRuntimeAdjustment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ConnectionTag;
    
public:
    UTrainTracksPoleBaseSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetPositionOffset(FIntVector NewPositionOffset);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTrainStopControlledByLogic() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsConnectedTo(const UTrainTrackSegmentSimulationComponent* Segment) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasUsableConnection() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasLogicInputSignal() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasConnectedConnectionsWithTag(FName Tag) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector GetPositionOffset() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrainTrackSegmentSimulationComponent* GetNextTrackSegment(const UTrainTracksAgentSimulationComponent* Agent, const UTrainTrackSegmentSimulationComponent* LastSegment) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UTrainTracksPoleConnectionSimulationComponent*> GetConnectedConnectionsWithTag(FName Tag) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UTrainTracksPoleConnectionSimulationComponent*> GetConnectedConnections() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrainTracksPoleConnectionSimulationComponent* GetClosestUsableConnection(const FIntVector& QueryLocation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UTrainTracksPoleConnectionSimulationComponent*> GetAllConnections() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrainTrackSegmentSimulationComponent* FindSegmentByOtherPole(const UTrainTracksPoleBaseSimulationComponent* OtherPole) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrainTracksPoleConnectionSimulationComponent* FindConnectionBySegment(const UTrainTrackSegmentSimulationComponent* Segment) const;
    

    // Fix for true pure virtual functions not being implemented
};

