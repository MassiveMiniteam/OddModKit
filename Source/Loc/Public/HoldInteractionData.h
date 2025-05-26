#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HoldInteractionData.generated.h"

class UNavFocusPath;

UCLASS(Blueprintable)
class LOC_API UHoldInteractionData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNavFocusPath* FocusPath;
    
    UHoldInteractionData();

};

