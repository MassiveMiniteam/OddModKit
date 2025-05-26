#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "DialogueComponent.generated.h"

class UDialogueConfig;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UDialogueComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogueConfig* DialogueConfig;
    
public:
    UDialogueComponent(const FObjectInitializer& ObjectInitializer);

};

