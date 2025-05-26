#pragma once
#include "CoreMinimal.h"
#include "LocSimulationSubsystem.h"
#include "MonsterSpawnerMetaData.h"
#include "MonsterSpawnerTimerSubsystem.generated.h"

UCLASS(Blueprintable)
class LOC_API UMonsterSpawnerTimerSubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FMonsterSpawnerMetaData> SpawnerData;
    
public:
    UMonsterSpawnerTimerSubsystem();

};

