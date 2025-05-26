#pragma once
#include "CoreMinimal.h"
#include "LogicSensorFoundActorsFilterStrategy.h"
#include "Templates/SubclassOf.h"
#include "LogicSensorFoundActorsFilterStrategy_AnyOtherFilter.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class LOC_API ULogicSensorFoundActorsFilterStrategy_AnyOtherFilter : public ULogicSensorFoundActorsFilterStrategy {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ULogicSensorFoundActorsFilterStrategy>> FilterStrategies;
    
public:
    ULogicSensorFoundActorsFilterStrategy_AnyOtherFilter();

};

