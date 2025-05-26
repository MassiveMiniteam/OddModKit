#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UnlockConditionWrapper.generated.h"

class UAchievement;
class UObject;
class UProductEntitlementDataAsset;
class UUnlockableDataAsset;

UCLASS(Blueprintable)
class LOC_API UUnlockConditionWrapper : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UProductEntitlementDataAsset* EntitlementDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAchievement* Achievement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUnlockableDataAsset* Unlockable;
    
    UUnlockConditionWrapper();

    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool IsUnlocked(UObject* WorldContext, TArray<UDataAsset*>& FailedConditions);
    
};

