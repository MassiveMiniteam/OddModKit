#pragma once
#include "CoreMinimal.h"
#include "AssemblyCondition.h"
#include "AssemblyCondition_NoConnectedTrainSegmentIsOccupied.generated.h"

UCLASS(Blueprintable)
class LOC_API UAssemblyCondition_NoConnectedTrainSegmentIsOccupied : public UAssemblyCondition {
    GENERATED_BODY()
public:
    UAssemblyCondition_NoConnectedTrainSegmentIsOccupied();

};

