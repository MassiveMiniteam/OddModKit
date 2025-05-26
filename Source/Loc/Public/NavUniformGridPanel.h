#pragma once
#include "CoreMinimal.h"
#include "Components/UniformGridPanel.h"
#include "NavElementInterface.h"
#include "NavUniformGridPanel.generated.h"

class UInputActionData;
class UNavFocusPath;
class USoundCue;

UCLASS(Blueprintable)
class LOC_API UNavUniformGridPanel : public UUniformGridPanel, public INavElementInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* OnTransitionHorizontalSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* OnTransitionVerticalSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSelectLastColumnAndRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSelectNearestSlotOnEnter;
    
    UNavUniformGridPanel();


    // Fix for true pure virtual functions not being implemented
    UFUNCTION()
    void OnProcessInput(UNavFocusPath* Path, int32 PathIndex, UInputActionData* InputData) override PURE_VIRTUAL(OnProcessInput,);
    
};

