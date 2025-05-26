#pragma once
#include "CoreMinimal.h"
#include "Components/ScrollBox.h"
#include "NavElementInterface.h"
#include "AutoScrollBox.generated.h"

class UInputActionData;
class UNavFocusPath;

UCLASS(Blueprintable)
class LOC_API UAutoScrollBox : public UScrollBox, public INavElementInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsNavigatable;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNavFocusPath* ActiveFocusPath;
    
public:
    UAutoScrollBox();

private:
    UFUNCTION(BlueprintCallable)
    void OnFocusPathChanged(UNavFocusPath* PathIn);
    

    // Fix for true pure virtual functions not being implemented
public:
    UFUNCTION()
    void OnProcessInput(UNavFocusPath* Path, int32 PathIndex, UInputActionData* InputData) override PURE_VIRTUAL(OnProcessInput,);
    
};

