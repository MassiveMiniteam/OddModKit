#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WidgetHook.generated.h"

class UNavUserWidget;
class UWorld;

UCLASS(Blueprintable, meta=(ShowWorldContextPin))
class LOCCORE_API UWidgetHook : public UObject {
    GENERATED_BODY()
public:
    UWidgetHook();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnWidgetShow(UWorld* World, UNavUserWidget* NavUserWidget);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnWidgetPostShow(UWorld* World, UNavUserWidget* NavUserWidget);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnWidgetPostHide(UWorld* World, UNavUserWidget* NavUserWidget);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnWidgetHide(UWorld* World, UNavUserWidget* NavUserWidget);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnWidgetConstruct(UWorld* World, UNavUserWidget* NavUserWidget);
    
};

