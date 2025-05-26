#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerInput.h"
#include "InputActionKeyReMapping.generated.h"

class UInputActionData;

USTRUCT(BlueprintType)
struct FInputActionKeyReMapping {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UInputActionData* InputActionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FInputActionKeyMapping UsedKeyRemapping;
    
    LOC_API FInputActionKeyReMapping();
};

