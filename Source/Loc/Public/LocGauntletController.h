#pragma once
#include "CoreMinimal.h"
#include "GauntletTestController.h"
#include "LocGauntletController.generated.h"

class ULocTestController;

UCLASS(Blueprintable)
class LOC_API ULocGauntletController : public UGauntletTestController {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULocTestController* TestController;
    
};

