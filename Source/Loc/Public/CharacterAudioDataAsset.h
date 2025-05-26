#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "CharacterAudioDataAsset.generated.h"

class USoundBase;

UCLASS(Blueprintable)
class LOC_API UCharacterAudioDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, TSoftObjectPtr<USoundBase>> Sounds;
    
public:
    UCharacterAudioDataAsset();

};

