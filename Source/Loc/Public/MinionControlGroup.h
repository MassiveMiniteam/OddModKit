#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MinionControlGroup.generated.h"

class ASimulationActor;
class UItemMinionConfig;

USTRUCT(BlueprintType)
struct FMinionControlGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UItemMinionConfig* MinionConfig;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ASimulationActor>> DeployedMinions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MinionGroupTag;
    
    LOC_API FMinionControlGroup();
};

