#pragma once
#include "CoreMinimal.h"
#include "Layout/Margin.h"
#include "Components/PanelSlot.h"
#include "NavElementInterface.h"
#include "2DScrollBoxSlot.generated.h"

class UInputActionData;
class UNavFocusPath;

UCLASS(Blueprintable)
class LOC_API U2DScrollBoxSlot : public UPanelSlot, public INavElementInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMargin Padding;
    
    U2DScrollBoxSlot();

    UFUNCTION(BlueprintCallable)
    void SetPadding(FMargin InPadding);
    

    // Fix for true pure virtual functions not being implemented
    UFUNCTION()
    void OnProcessInput(UNavFocusPath* Path, int32 PathIndex, UInputActionData* InputData) override PURE_VIRTUAL(OnProcessInput,);
    
};

