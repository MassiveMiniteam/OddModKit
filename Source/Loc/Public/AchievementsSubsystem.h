#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AchievementEventDelegate.h"
#include "AchievementsSubsystem.generated.h"

class UAchievement;

UCLASS(Blueprintable)
class LOC_API UAchievementsSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAchievementEvent AchievementUnlockEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAchievement*> AllAchievements;
    
public:
    UAchievementsSubsystem();

    UFUNCTION(BlueprintCallable)
    void SetAchievementsAllowed(bool bAllowed);
    
    UFUNCTION(BlueprintCallable)
    void ResetAllAchievements_Debug();
    
    UFUNCTION(BlueprintCallable)
    void ResetAllAchievements();
    
protected:
    UFUNCTION(BlueprintCallable)
    void QueryAchievements();
    
public:
    UFUNCTION(BlueprintCallable)
    int32 GetUnlockedAchievementsCount();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAreAchievementsAllowed() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<UAchievement*> GetAllAchievements();
    
};

