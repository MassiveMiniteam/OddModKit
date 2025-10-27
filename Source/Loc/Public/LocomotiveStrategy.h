#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FixedInterval.h"
#include "LocomotiveStrategy.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class LOC_API ULocomotiveStrategy : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixedInterval SpeedLimits;
    
public:
    ULocomotiveStrategy();

};

