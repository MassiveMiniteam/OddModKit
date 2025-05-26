#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "Fixed64.h"
#include "OnNewTrackSegmentReached_DelegateDelegate.h"
#include "OnTrainStartedMovement_DelegateDelegate.h"
#include "OnTrainStoppedMovement_DelegateDelegate.h"
#include "TrainTrackLocation.h"
#include "TrainTracksAgentSimulationComponent.generated.h"

class UActorChainSimulationComponent;
class UPositionSimulationComponent;
class UTrainTrackSegmentSimulationComponent;
class UTrainTracksAgentSimulationComponent;
class UTrainTracksPoleBaseSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTrainTracksAgentSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnNewTrackSegmentReached_Delegate OnNewTrackSegmentReached_Delegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTrainStartedMovement_Delegate OnTrainStartedMovement_Delegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTrainStoppedMovement_Delegate OnTrainStoppedMovement_Delegate;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FTrainTrackLocation CurrentLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FTrainTrackLocation LastLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bWasMovingLastFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPositionSimulationComponent* PositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorChainSimulationComponent* ActorChainComponent;
    
public:
    UTrainTracksAgentSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool WholeTrainHasAnyLocomotive() const;
    
    UFUNCTION(BlueprintCallable)
    void UpdateAllTrainAgentPositionsStartingOnPrimaryAgent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlacedOnTracks() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLeadingLocomotive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCurrentlyMoving() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasCurrentlyPlayerInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTrainTrackLocation GetTrackLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrainTracksAgentSimulationComponent* GetPrimaryAgent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrainTracksPoleBaseSimulationComponent* GetPreviousPole() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrainTracksAgentSimulationComponent* GetPreviousAgent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrainTracksPoleBaseSimulationComponent* GetNextPole() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrainTracksAgentSimulationComponent* GetNextAgent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTrainTrackLocation GetLastLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrainTracksAgentSimulationComponent* GetLastAttachedAgent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrainTracksAgentSimulationComponent* GetFrontAgent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrainTrackSegmentSimulationComponent* GetCurrentSegment() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed64 GetCurrentProgressOnSegment() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed64 GetCurrentMovementDelta() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed64 GetCurrentDistanceAlongSegment() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrainTracksPoleBaseSimulationComponent* GetClosestPole() const;
    
    UFUNCTION(BlueprintCallable)
    void AttachInFrontOfTrainAgent(UTrainTracksAgentSimulationComponent* TrainAgent);
    
    UFUNCTION(BlueprintCallable)
    void AttachBehindTrainAgent(UTrainTracksAgentSimulationComponent* TrainAgent);
    
};

