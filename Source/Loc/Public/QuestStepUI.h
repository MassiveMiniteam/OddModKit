#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuestStepUI.generated.h"

class UQuestStepBehaviour;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UQuestStepUI : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UQuestStepBehaviour* QuestStepBehaviour;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyUpdateOnce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDarkMode;
    
public:
    UQuestStepUI();

};

