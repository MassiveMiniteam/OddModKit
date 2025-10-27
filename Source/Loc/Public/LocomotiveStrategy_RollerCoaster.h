#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "LocomotiveStrategy.h"
#include "LocomotiveStrategy_RollerCoaster.generated.h"

class UStatsComponent;
class UTrainTracksAgentSimulationComponent;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API ULocomotiveStrategy_RollerCoaster : public ULocomotiveStrategy {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatsComponent* StatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTrainTracksAgentSimulationComponent* TrainAgentComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Acceleration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Acceleration_Backwards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Deceleration_Breaking;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Friction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed DownHillAcceleration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed UpHillDeAcceleration;
    
public:
    ULocomotiveStrategy_RollerCoaster();

};

