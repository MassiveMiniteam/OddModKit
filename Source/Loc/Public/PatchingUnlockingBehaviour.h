#pragma once
#include "CoreMinimal.h"
#include "PatchingUnlockingBehaviour.generated.h"

class UUnlockableDataAsset;

USTRUCT(BlueprintType)
struct FPatchingUnlockingBehaviour {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UUnlockableDataAsset> IfUnlocked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBeforeVillage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GenerationVersionToPatch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UUnlockableDataAsset>> UnlockThis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UUnlockableDataAsset>> LockThis;
    
    LOC_API FPatchingUnlockingBehaviour();
};

