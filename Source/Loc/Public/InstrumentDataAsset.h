#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InstrumentDataAsset.generated.h"

class USoundBase;

UCLASS(Blueprintable)
class LOC_API UInstrumentDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* SoundBaseNote;
    
    UInstrumentDataAsset();

};

