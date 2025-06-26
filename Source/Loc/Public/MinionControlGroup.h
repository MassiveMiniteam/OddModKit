#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ItemStack.h"
#include "MinionControlGroup.generated.h"

class ASimulationActor;

USTRUCT(BlueprintType)
struct FMinionControlGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FItemStack MinionItemStack;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ASimulationActor>> DeployedMinions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MinionGroupTag;
    
    LOC_API FMinionControlGroup();
};

