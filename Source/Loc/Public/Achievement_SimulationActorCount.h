#pragma once
#include "CoreMinimal.h"
#include "Achievement_BasicCount.h"
#include "Achievement_SimulationActorCount.generated.h"

class ASimulationActor;

UCLASS(Blueprintable)
class LOC_API UAchievement_SimulationActorCount : public UAchievement_BasicCount {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASimulationActor*> SimulationActorsCheck;
    
public:
    UAchievement_SimulationActorCount();

};

