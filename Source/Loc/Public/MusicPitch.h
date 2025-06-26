#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MusicPitch.generated.h"

USTRUCT(BlueprintType)
struct FMusicPitch {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Note;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Octave;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Instrument;
    
    LOC_API FMusicPitch();
};

