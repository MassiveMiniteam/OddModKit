#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "Templates/SubclassOf.h"
#include "UpdateCatapultTargetingSimulationCommand.generated.h"

class UCatapultAimSimulationComponent;
class UGameplayAbilityTargeting;

UCLASS(Blueprintable)
class UUpdateCatapultTargetingSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UCatapultAimSimulationComponent* CatapultAimingComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayAbilityTargeting> TargetingClass;
    
public:
    UUpdateCatapultTargetingSimulationCommand();

};

