#pragma once
#include "CoreMinimal.h"
#include "InteractionStrategy.h"
#include "Templates/SubclassOf.h"
#include "InteractionStrategy_OpenDetailUI.generated.h"

class UDetailUIWidget;

UCLASS(Abstract, Blueprintable)
class UInteractionStrategy_OpenDetailUI : public UInteractionStrategy {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDetailUIWidget> WidgetClass;
    
public:
    UInteractionStrategy_OpenDetailUI();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDetailUIWidgetCreated(UDetailUIWidget* Widget) const;
    
};

