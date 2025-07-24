#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "MusicInstrumentMappingDataAsset.generated.h"

class USoundBase;

UCLASS(Blueprintable)
class LOC_API UMusicInstrumentMappingDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, USoundBase*> TagToSound_Legato;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, USoundBase*> TagToSound_Staccato;
    
    UMusicInstrumentMappingDataAsset();

};

