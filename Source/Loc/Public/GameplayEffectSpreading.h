#pragma once
#include "CoreMinimal.h"
#include "GameplayEffectWithTargeting.h"
#include "GameplayEffectSpreading.generated.h"

class USharedActorContainer;

UCLASS(Blueprintable)
class LOC_API UGameplayEffectSpreading : public UGameplayEffectWithTargeting {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxSpreading;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CurrentSpreading;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    USharedActorContainer* ActorsToIgnore;
    
public:
    UGameplayEffectSpreading();

};

