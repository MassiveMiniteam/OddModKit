#pragma once
#include "CoreMinimal.h"
#include "SerializedSimulationObject.h"
#include "EnemySpawnStrategy.generated.h"

class UDataTable;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class LOC_API UEnemySpawnStrategy : public USerializedSimulationObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKeepSpawningForEverOnceStarted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* EnemyTable;
    
    UEnemySpawnStrategy();

};

