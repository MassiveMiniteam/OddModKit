#pragma once
#include "CoreMinimal.h"
#include "TreeInstanceSaveInfo.generated.h"

class UBehaviorTree;

USTRUCT(BlueprintType)
struct FTreeInstanceSaveInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UBehaviorTree* TreeAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<uint8> Memory;
    
    LOC_API FTreeInstanceSaveInfo();
};

