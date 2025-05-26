#pragma once
#include "CoreMinimal.h"
#include "WidgetArray.generated.h"

class UUserWidget;

USTRUCT(BlueprintType)
struct FWidgetArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UUserWidget*> Widgets;
    
    LOCCORE_API FWidgetArray();
};

