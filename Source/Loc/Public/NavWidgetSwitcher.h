#pragma once
#include "CoreMinimal.h"
#include "Components/WidgetSwitcher.h"
#include "NavElementInterface.h"
#include "NavWidgetSwitcher.generated.h"

class UInputActionData;
class UNavFocusPath;

UCLASS(Blueprintable)
class LOC_API UNavWidgetSwitcher : public UWidgetSwitcher, public INavElementInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UNavFocusPath> ActivePath;
    
public:
    UNavWidgetSwitcher();


    // Fix for true pure virtual functions not being implemented
    UFUNCTION()
    void OnProcessInput(UNavFocusPath* Path, int32 PathIndex, UInputActionData* InputData) override PURE_VIRTUAL(OnProcessInput,);
    
};

