#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "EGameplayStatModifierType.h"
#include "GameplayStatModifier.generated.h"

class ASimulationActor;

USTRUCT(BlueprintType)
struct FGameplayStatModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<ASimulationActor> Origin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EGameplayStatModifierType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTag Tag;
    
    LOC_API FGameplayStatModifier();
};

