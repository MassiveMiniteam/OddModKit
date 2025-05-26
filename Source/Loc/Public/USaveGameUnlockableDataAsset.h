#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "USaveGameUnlockableDataAsset.generated.h"

class UObject;

UCLASS(Blueprintable)
class LOC_API UUSaveGameUnlockableDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsUnlockedByDefault;
    
    UUSaveGameUnlockableDataAsset();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void Unlock(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool IsUnlocked(UObject* WorldContext);
    
};

