#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "LogicSensorFoundActorsFilterStrategy.h"
#include "MotionSensorDetectionStrategy_TagFilter.generated.h"

UCLASS(Blueprintable)
class LOC_API UMotionSensorDetectionStrategy_TagFilter : public ULogicSensorFoundActorsFilterStrategy {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
public:
    UMotionSensorDetectionStrategy_TagFilter();

};

