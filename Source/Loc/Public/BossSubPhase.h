#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "BossSubPhase.generated.h"

class UEnemySpawnStrategy;
class UMetaSoundSource;
class UTexture2D;

USTRUCT(BlueprintType)
struct FBossSubPhase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StartValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EndValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 VisualDangerLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnemySpawnStrategy> WaveSpawnerStrategy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> SubphaseTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMetaSoundSource> SubphaseMusic;
    
    LOC_API FBossSubPhase();
};

