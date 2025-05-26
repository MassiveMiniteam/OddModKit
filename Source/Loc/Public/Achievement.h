#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "Achievement.generated.h"

class UObject;
class UTexture2D;

UCLASS(Blueprintable)
class LOC_API UAchievement : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag TypeTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AchievementOrderInUI;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> IconLocked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowNeededAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsUnlocked;
    
public:
    UAchievement();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void Unlock(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void Reset(UObject* WorldContext, bool bSave);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool IsUnlocked(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    float GetPercentage(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    int32 GetNeededAmount(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    int32 GetCurrentAmount(UObject* WorldContext);
    
protected:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    bool GetAreAchievementsAllowed(const UObject* WorldContext);
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    bool CanUnlock(UObject* WorldContext);
    
};

