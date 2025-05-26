#pragma once
#include "CoreMinimal.h"
#include "TreeInstanceSaveInfo.h"
#include "SimulationBehaviorTreeSaveInfo.generated.h"

USTRUCT(BlueprintType)
struct FSimulationBehaviorTreeSaveInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ActiveInstanceIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FTreeInstanceSaveInfo> InstancesInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<uint8> NodeInstanceData;
    
    LOC_API FSimulationBehaviorTreeSaveInfo();
};

