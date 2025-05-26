#pragma once
#include "CoreMinimal.h"
#include "AdvancedForceFeedback.generated.h"

class UAudioComponent;
class UForceFeedbackComponent;

USTRUCT(BlueprintType)
struct FAdvancedForceFeedback {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* AudioVibrationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UForceFeedbackComponent* ForceFeedbackComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Handle;
    
    LOC_API FAdvancedForceFeedback();
};

