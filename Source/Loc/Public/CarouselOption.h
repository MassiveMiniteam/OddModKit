#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "CarouselOption.generated.h"

USTRUCT(BlueprintType)
struct FCarouselOption {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Tag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText OptionText;
    
    LOC_API FCarouselOption();
};

