#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "Templates/SubclassOf.h"
#include "RemoveGameplayEffectCommand.generated.h"

class UGameplayEffect;
class UStatsComponent;

UCLASS(Blueprintable)
class LOC_API URemoveGameplayEffectCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UStatsComponent* Stats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayEffect> EffectClass;
    
    URemoveGameplayEffectCommand();

};

