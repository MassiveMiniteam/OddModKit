#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateTypes.h"
#include "Components/EditableTextBox.h"
#include "NavElementInterface.h"
#include "AdvancedTextBox.generated.h"

class UInputActionData;
class UNavFocusPath;

UCLASS(Blueprintable)
class LOC_API UAdvancedTextBox : public UEditableTextBox, public INavElementInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyAlphanumeric;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnsureValidFileName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReadOnlyOnConsoles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEditableTextBoxStyle DefaultStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEditableTextBoxStyle FocussedStyle;
    
public:
    UAdvancedTextBox();


    // Fix for true pure virtual functions not being implemented
    UFUNCTION()
    void OnProcessInput(UNavFocusPath* Path, int32 PathIndex, UInputActionData* InputData) override PURE_VIRTUAL(OnProcessInput,);
    
};

