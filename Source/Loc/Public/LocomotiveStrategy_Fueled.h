#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "LocomotiveStrategy.h"
#include "LocomotiveStrategy_Fueled.generated.h"

class UItemDecayComponent;
class UTrainTracksAgentSimulationComponent;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API ULocomotiveStrategy_Fueled : public ULocomotiveStrategy {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemDecayComponent* FuelDecayComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Acceleration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Acceleration_Backwards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Deceleration_Breaking;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Deceleration_RollOut;
    
public:
    ULocomotiveStrategy_Fueled();

private:
    UFUNCTION(BlueprintCallable)
    void OnMovementStopped(UTrainTracksAgentSimulationComponent* Agent);
    
    UFUNCTION(BlueprintCallable)
    void OnMovementStarted(UTrainTracksAgentSimulationComponent* Agent);
    
};

