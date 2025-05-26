#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Templates/SubclassOf.h"
#include "NavFocusPath.generated.h"

class INavElementInterface;
class UNavElementInterface;
class UNavUserWidget;

UCLASS(Blueprintable)
class LOC_API UNavFocusPath : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TScriptInterface<INavElementInterface>> NavElements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLastInteractionByMouse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnGoingMouseInteraction;
    
public:
    UNavFocusPath();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 Num();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasElementOfType(TArray<TSubclassOf<UNavUserWidget>> WidgetClass);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetIndexForElement(TScriptInterface<INavElementInterface> Element);
    
    UFUNCTION(BlueprintCallable)
    TScriptInterface<INavElementInterface> GetFirstElementOfType(TSubclassOf<UNavUserWidget> WidgetClass);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TScriptInterface<INavElementInterface> GetElementAtIndex(int32 Index);
    
};

