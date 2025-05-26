#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "Templates/SubclassOf.h"
#include "SingleDamageTrackData.generated.h"

class AActor;
class UGameplayEffectDamage;
class UMinionControllerSimulationBaseComponent;

USTRUCT(BlueprintType)
struct FSingleDamageTrackData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Amount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayEffectDamage> DamageClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> Instigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMinionControllerSimulationBaseComponent> MinionController;
    
    LOC_API FSingleDamageTrackData();
};

