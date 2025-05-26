#pragma once
#include "CoreMinimal.h"
#include "Achievement.h"
#include "Achievement_MultipleUnlockables.generated.h"

class UObject;
class UUnlockableDataAsset;

UCLASS(Blueprintable)
class LOC_API UAchievement_MultipleUnlockables : public UAchievement {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UUnlockableDataAsset*> NeededUnlockables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UUnlockableDataAsset*> UnlockedUnlockables;
    
public:
    UAchievement_MultipleUnlockables();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void TryAddUnlockable(UObject* WorldContext, UUnlockableDataAsset* UnlockableDataAsset);
    
};

