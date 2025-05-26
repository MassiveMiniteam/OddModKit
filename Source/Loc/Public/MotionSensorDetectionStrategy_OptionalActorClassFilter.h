#pragma once
#include "CoreMinimal.h"
#include "LogicSensorFoundActorsFilterStrategy.h"
#include "Templates/SubclassOf.h"
#include "MotionSensorDetectionStrategy_OptionalActorClassFilter.generated.h"

class ASimulationActor;

UCLASS(Blueprintable)
class LOC_API UMotionSensorDetectionStrategy_OptionalActorClassFilter : public ULogicSensorFoundActorsFilterStrategy {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASimulationActor> OptionalFilteredClass;
    
public:
    UMotionSensorDetectionStrategy_OptionalActorClassFilter();

};

