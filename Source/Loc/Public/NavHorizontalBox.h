#pragma once
#include "CoreMinimal.h"
#include "Components/HorizontalBox.h"
#include "NavElementInterface.h"
#include "NavHorizontalBox.generated.h"

class UInputActionData;
class UNavFocusPath;
class USoundCue;

UCLASS(Blueprintable)
class LOC_API UNavHorizontalBox : public UHorizontalBox, public INavElementInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* OnTransitionSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableWrapping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSelectSpecificIndexOnFocus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FirstSelectIndex;
    
    UNavHorizontalBox();


    // Fix for true pure virtual functions not being implemented
    UFUNCTION()
    void OnProcessInput(UNavFocusPath* Path, int32 PathIndex, UInputActionData* InputData) override PURE_VIRTUAL(OnProcessInput,);
    
};

