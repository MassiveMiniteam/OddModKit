#pragma once
#include "CoreMinimal.h"
#include "ElementState.h"
#include "GameplayEffect.h"
#include "GE_ApplyElement.generated.h"

UCLASS(Abstract, Blueprintable)
class LOC_API UGE_ApplyElement : public UGameplayEffect {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FElementState ElementState;
    
public:
    UGE_ApplyElement();

};

