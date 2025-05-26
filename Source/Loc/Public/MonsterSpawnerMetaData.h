#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "MonsterSpawnerMetaData.generated.h"

USTRUCT(BlueprintType)
struct FMonsterSpawnerMetaData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString SpawnerName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed TimeElapsed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 MaxMonsterCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed Duration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 MonsterCount;
    
    LOC_API FMonsterSpawnerMetaData();
};

