#pragma once
#include "CoreMinimal.h"
#include "Components/Slider.h"
#include "NavElementInterface.h"
#include "NavInteractionEventDelegate.h"
#include "OnSliderAcceptedDelegate.h"
#include "NavSlider.generated.h"

class UInputActionData;
class UNavFocusPath;

UCLASS(Blueprintable)
class LOC_API UNavSlider : public USlider, public INavElementInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSliderAccepted OnSliderAccepted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNavInteractionEvent OnGainFocusByPlayer;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNavInteractionEvent OnLostFocusByPlayer;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNavInteractionEvent OnInteractionByPlayerEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNavInteractionEvent OnInteractionStartedByPlayerEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInteractable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNavigable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnhoverRemovesFocus;
    
public:
    UNavSlider();

    UFUNCTION(BlueprintCallable)
    void SetNavSliderValueWithoutDelegate(float NewValue);
    
    UFUNCTION(BlueprintCallable)
    void SetNavSliderValue(float NewValue);
    
    UFUNCTION(BlueprintCallable)
    void SetMouseUsesSteps(bool bNewMouseUsesSteps);
    
    UFUNCTION(BlueprintCallable)
    void AcceptValue();
    

    // Fix for true pure virtual functions not being implemented
    UFUNCTION()
    void OnProcessInput(UNavFocusPath* Path, int32 PathIndex, UInputActionData* InputData) override PURE_VIRTUAL(OnProcessInput,);
    
};

