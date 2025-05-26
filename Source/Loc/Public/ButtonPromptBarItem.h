#pragma once
#include "CoreMinimal.h"
#include "ButtonPromptBarItem.generated.h"

class UInputActionData;

USTRUCT(BlueprintType)
struct FButtonPromptBarItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowMouseKeyboard;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowGamepad;
    
    LOC_API FButtonPromptBarItem();
};

