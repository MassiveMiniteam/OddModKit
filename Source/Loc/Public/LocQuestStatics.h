#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "LocCoreStatics.h"
#include "EQuestOverviewDisplayMode.h"
#include "EQuestTier.h"
#include "EQuestTierState.h"
#include "QuestCollection.h"
#include "QuestTierCollection.h"
#include "QuestTierData.h"
#include "Templates/SubclassOf.h"
#include "LocQuestStatics.generated.h"

class AActor;
class UBiomeConfig;
class UObject;
class UQuestConfig;
class UQuestManagerSimulationComponent;
class UQuestOverviewCategory;
class UUnlockableTier;

UCLASS(Blueprintable)
class LOC_API ULocQuestStatics : public ULocCoreStatics {
    GENERATED_BODY()
public:
    ULocQuestStatics();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<UQuestConfig*> TopologicalSortQuests(TArray<UQuestConfig*> Quests);
    
    UFUNCTION(BlueprintCallable)
    static TArray<UQuestConfig*> SortQuestConfigsByVisualSortIndex(TArray<UQuestConfig*> InQuests);
    
    UFUNCTION(BlueprintCallable)
    static TArray<UQuestOverviewCategory*> SortQuestCategories(TArray<UQuestOverviewCategory*> InQuestCategories);
    
    UFUNCTION(BlueprintCallable)
    static TArray<UBiomeConfig*> SortBiomes(TArray<UBiomeConfig*> InBiomeConfigs);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static bool ShouldBiomeBeVisible(UObject* WorldContext, UBiomeConfig* Biome, EQuestOverviewDisplayMode Mode);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsTierUnlocked(UObject* WorldContextObject, EQuestTier Tier);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static UUnlockableTier* GetTierUnlockData(EQuestTier Tier, UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UUnlockableTier*> GetTierUnlockables(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static EQuestTierState GetQuestTierState(UObject* WorldContextObject, EQuestTier Tier, EQuestOverviewDisplayMode Mode);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static TMap<UQuestOverviewCategory*, FQuestTierCollection> GetQuestTiersPerOverviewCategory(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TMap<UQuestOverviewCategory*, FQuestCollection> GetQuestsPerOverviewCategory(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TMap<TSubclassOf<AActor>, FQuestCollection> GetQuestsPerNPC(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UQuestConfig*> GetQuestsForCategory(UObject* WorldContext, UQuestOverviewCategory* QuestCategory);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static UQuestManagerSimulationComponent* GetQuestManager(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UQuestConfig*> GetQuestDataProjectWide(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static EQuestTier GetPreviousQuestTier(UObject* WorldContextObject, EQuestTier Tier, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EQuestTier GetNextQuestTier(EQuestTier Tier, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UQuestConfig*> GetAllTutorialQuestData(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<FQuestTierData> GetAllTiers(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static TArray<UQuestConfig*> GetAllQuestsOfTier(UObject* WorldContextObject, EQuestTier Tier, FGameplayTagContainer RequiredTags, FGameplayTagContainer ForbiddenTags);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UQuestOverviewCategory*> GetAllQuestCategories(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UQuestConfig*> GetAllMainQuestData(UObject* WorldContext);
    
};

