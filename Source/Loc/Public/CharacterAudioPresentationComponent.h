#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PresentationActorComponent.h"
#include "ECharacterAudioPlayOption.h"
#include "CharacterAudioPresentationComponent.generated.h"

class UCharacterAudioDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UCharacterAudioPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCharacterAudioDataAsset* AudioDataAsset;
    
public:
    UCharacterAudioPresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void PlayAudioByTag(FGameplayTag Tag, ECharacterAudioPlayOption Option);
    
};

