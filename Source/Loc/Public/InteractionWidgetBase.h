#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InteractionWidgetBase.generated.h"

class UInteractionPresentationComponent;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UInteractionWidgetBase : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInteractionPresentationComponent> InteractionComponent;
    
public:
    UInteractionWidgetBase();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInteractionComponentSet(UInteractionPresentationComponent* Component);
    
};

