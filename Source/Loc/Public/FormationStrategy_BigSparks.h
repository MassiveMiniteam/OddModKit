#pragma once
#include "CoreMinimal.h"
#include "FormationStrategy.h"
#include "FormationStrategy_BigSparks.generated.h"

UCLASS(Blueprintable)
class UFormationStrategy_BigSparks : public UFormationStrategy {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DistanceBetweenUnits;
    
public:
    UFormationStrategy_BigSparks();

};

