#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "Fixed.h"
#include "TemperatureEfficiencyConfig.generated.h"

UCLASS(Blueprintable)
class LOC_API UTemperatureEfficiencyConfig : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed OptimalEfficiency;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FInt32Interval OptimalEfficiencyRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed EfficiencyDecreasePerNonOptimalStep;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TemperatureStepsRequiredPerEfficiencyDecreaseStep;
    
    UTemperatureEfficiencyConfig();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed CalcEfficiency(int32 Temperature) const;
    
};

