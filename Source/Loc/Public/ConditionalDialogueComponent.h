#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "ConditionalDialogueComponent.generated.h"

class UDialogueConfig;
class UUnlockableDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UConditionalDialogueComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogueConfig* DialogueA;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogueConfig* DialogueB;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogueConfig* DialogueC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUnlockableDataAsset* Condition_PickDialogueB;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUnlockableDataAsset* Condition_PickDialogueC;
    
public:
    UConditionalDialogueComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UDialogueConfig* GetDialogue();
    
};

