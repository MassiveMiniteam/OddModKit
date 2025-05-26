#pragma once
#include "CoreMinimal.h"
#include "QuestConfig.h"
#include "Templates/SubclassOf.h"
#include "BossQuestConfig.generated.h"

class UBossPhase;
class USoundBase;

UCLASS(Blueprintable)
class LOC_API UBossQuestConfig : public UQuestConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UBossPhase> BossPhaseClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundBase> BossQuestLocalStartSound;
    
    UBossQuestConfig();

};

