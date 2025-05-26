#pragma once
#include "CoreMinimal.h"
#include "NodeStackInfo.generated.h"

class ILocAINode;
class ULocAINode;

USTRUCT(BlueprintType)
struct FNodeStackInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TScriptInterface<ILocAINode> Node;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int16 InstanceIndex;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int16 ExecutionIndex;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int16 NodeInstanceIndex;
    
    LOC_API FNodeStackInfo();
};

