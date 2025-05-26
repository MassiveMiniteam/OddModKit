#pragma once
#include "CoreMinimal.h"
#include "UserPopupWidgetData.generated.h"

USTRUCT(BlueprintType)
struct FUserPopupWidgetData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Headline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Content;
    
    LOC_API FUserPopupWidgetData();
};

