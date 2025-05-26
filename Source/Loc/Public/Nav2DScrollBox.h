#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "2DScrollBox.h"
#include "NavElementInterface.h"
#include "Nav2DScrollBox.generated.h"

class ALocPlayerController;
class UInputActionData;
class UNavFocusPath;

UCLASS(Blueprintable)
class LOC_API UNav2DScrollBox : public U2DScrollBox, public INavElementInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* ScrollXAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* ScrollYAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInvertAxisInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GamepadScrollSpeed;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNavFocusPath* ActiveFocusPath;
    
public:
    UNav2DScrollBox();

protected:
    UFUNCTION(BlueprintCallable)
    void OnScrollYInput(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnScrollXInput(UInputActionData* InputAction, ALocPlayerController* Player);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnFocusPathChanged(UNavFocusPath* PathIn);
    
protected:
    UFUNCTION(BlueprintCallable)
    void AddScroll(FVector2D ScrollAmount);
    

    // Fix for true pure virtual functions not being implemented
public:
    UFUNCTION()
    void OnProcessInput(UNavFocusPath* Path, int32 PathIndex, UInputActionData* InputData) override PURE_VIRTUAL(OnProcessInput,);
    
};

