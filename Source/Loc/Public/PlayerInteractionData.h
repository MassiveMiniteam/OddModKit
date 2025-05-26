#pragma once
#include "CoreMinimal.h"
#include "PlayerInteractionData.generated.h"

class ASimulationPlayer;

USTRUCT(BlueprintType)
struct FPlayerInteractionData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ASimulationPlayer> Player;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsBlockingOtherInteractions;
    
    LOC_API FPlayerInteractionData();
};

