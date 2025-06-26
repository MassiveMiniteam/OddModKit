#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "OctaveMapping.generated.h"

class USoundBase;

USTRUCT(BlueprintType)
struct FOctaveMapping {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, USoundBase*> Notes;
    
    LOC_API FOctaveMapping();
};

