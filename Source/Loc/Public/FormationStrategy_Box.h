#pragma once
#include "CoreMinimal.h"
#include "FormationStrategy.h"
#include "FormationStrategy_Box.generated.h"

UCLASS(Blueprintable)
class UFormationStrategy_Box : public UFormationStrategy {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DistanceBetweenUnits;
    
public:
    UFormationStrategy_Box();

};

