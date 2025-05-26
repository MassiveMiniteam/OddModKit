#pragma once
#include "CoreMinimal.h"
#include "UnlockableDataAsset.h"
#include "UnlockableDataAsset_OrCondition.generated.h"

class UObject;

UCLASS(Blueprintable)
class LOC_API UUnlockableDataAsset_OrCondition : public UUnlockableDataAsset {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UUnlockableDataAsset*> Prerequisites;
    
public:
    UUnlockableDataAsset_OrCondition();

    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool CanUnlock(UObject* WorldContext);
    
};

