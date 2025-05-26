#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MessageDialogWidgetInterface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UMessageDialogWidgetInterface : public UInterface {
    GENERATED_BODY()
};

class IMessageDialogWidgetInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ShowMessage(const FText& Title, const FText& Content);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsReadyToShow();
    
};

