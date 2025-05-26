#pragma once
#include "CoreMinimal.h"
#include "TrainsConnectionChangeDelegateParams.generated.h"

class ASimulationActor;
class UInputContextBuildConnector;
class UTrainTracksPoleBaseSimulationComponent;
class UTrainTracksPoleConnectionSimulationComponent;

USTRUCT(BlueprintType)
struct FTrainsConnectionChangeDelegateParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTrainTracksPoleBaseSimulationComponent* FirstPole;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTrainTracksPoleConnectionSimulationComponent* FirstConnection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTrainTracksPoleConnectionSimulationComponent* SecondConnection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextBuildConnector* InputContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFailDueToIntersection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTrainTracksPoleBaseSimulationComponent* HoveredPole;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASimulationActor* HoveredRail;
    
    LOC_API FTrainsConnectionChangeDelegateParams();
};

