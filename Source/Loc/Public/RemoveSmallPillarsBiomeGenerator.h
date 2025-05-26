#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "BiomeGenerator.h"
#include "RemoveSmallPillarsBiomeGenerator.generated.h"

UCLASS(Blueprintable)
class LOC_API URemoveSmallPillarsBiomeGenerator : public UBiomeGenerator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed MinHeightDifference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Radius;
    
public:
    URemoveSmallPillarsBiomeGenerator();

};

