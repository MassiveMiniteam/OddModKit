#pragma once
#include "CoreMinimal.h"
#include "Achievement_BasicCount.h"
#include "Templates/SubclassOf.h"
#include "Achievement_UniqueEnemyKillsCount.generated.h"

class ASimulationActor;

UCLASS(Blueprintable)
class UAchievement_UniqueEnemyKillsCount : public UAchievement_BasicCount {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyCountLocalPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ASimulationActor>> SimulationActorsToCheck;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ASimulationActor>> UniqueSimulationActors;
    
public:
    UAchievement_UniqueEnemyKillsCount();

};

