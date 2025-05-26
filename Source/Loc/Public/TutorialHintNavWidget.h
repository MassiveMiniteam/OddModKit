#pragma once
#include "CoreMinimal.h"
#include "NavUserWidget.h"
#include "TutorialHintNavWidget.generated.h"

class UInputActionData;
class UTutorialHintData;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UTutorialHintNavWidget : public UNavUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* ConfirmInputData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTutorialHintData* TutorialHintWidgetData;
    
public:
    UTutorialHintNavWidget();

    UFUNCTION(BlueprintCallable)
    void SetTutorialData(UTutorialHintData* InTutorialHintData);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnTutorialDataSet();
    
};

