#pragma once
#include "CoreMinimal.h"
#include "Components/CanvasPanel.h"
#include "TabContainer.generated.h"

class UWidget;

UCLASS(Blueprintable)
class LOC_API UTabContainer : public UCanvasPanel {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWidget*> TabElements;
    
public:
    UTabContainer();

};

