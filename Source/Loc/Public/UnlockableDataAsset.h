#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "UnlockableDataAsset.generated.h"

class UObject;
class UProductEntitlementDataAsset;
class UTexture2D;

UCLASS(Blueprintable)
class LOC_API UUnlockableDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsUnlockedByDefault;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UProductEntitlementDataAsset* Entitlement;
    
    UUnlockableDataAsset();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void Unlock(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool IsUnlocked(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetUnlockableTitle() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSoftObjectPtr<UTexture2D> GetUnlockableIcon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetUnlockableDescription() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetRichTextId() const;
    
};

