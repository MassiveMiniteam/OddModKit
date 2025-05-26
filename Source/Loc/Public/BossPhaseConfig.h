#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "BossPhaseConfig.generated.h"

class UBossPhase;

USTRUCT(BlueprintType)
struct FBossPhaseConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UBossPhase> BossPhaseClass;
    
    LOC_API FBossPhaseConfig();
};

