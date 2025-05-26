#include "LocQuestStatics.h"
#include "Templates/SubclassOf.h"

ULocQuestStatics::ULocQuestStatics() {
}

TArray<UQuestConfig*> ULocQuestStatics::TopologicalSortQuests(TArray<UQuestConfig*> Quests) {
    return TArray<UQuestConfig*>();
}

TArray<UQuestConfig*> ULocQuestStatics::SortQuestConfigsByVisualSortIndex(TArray<UQuestConfig*> InQuests) {
    return TArray<UQuestConfig*>();
}

TArray<UQuestOverviewCategory*> ULocQuestStatics::SortQuestCategories(TArray<UQuestOverviewCategory*> InQuestCategories) {
    return TArray<UQuestOverviewCategory*>();
}

TArray<UBiomeConfig*> ULocQuestStatics::SortBiomes(TArray<UBiomeConfig*> InBiomeConfigs) {
    return TArray<UBiomeConfig*>();
}

bool ULocQuestStatics::ShouldBiomeBeVisible(UObject* WorldContext, UBiomeConfig* Biome, EQuestOverviewDisplayMode Mode) {
    return false;
}

bool ULocQuestStatics::IsTierUnlocked(UObject* WorldContextObject, EQuestTier Tier) {
    return false;
}

UUnlockableTier* ULocQuestStatics::GetTierUnlockData(EQuestTier Tier, UObject* WorldContext) {
    return NULL;
}

TArray<UUnlockableTier*> ULocQuestStatics::GetTierUnlockables(UObject* WorldContext) {
    return TArray<UUnlockableTier*>();
}

EQuestTierState ULocQuestStatics::GetQuestTierState(UObject* WorldContextObject, EQuestTier Tier, EQuestOverviewDisplayMode Mode) {
    return EQuestTierState::Available;
}

TMap<UQuestOverviewCategory*, FQuestTierCollection> ULocQuestStatics::GetQuestTiersPerOverviewCategory(UObject* WorldContextObject) {
    return TMap<UQuestOverviewCategory*, FQuestTierCollection>();
}

TMap<UQuestOverviewCategory*, FQuestCollection> ULocQuestStatics::GetQuestsPerOverviewCategory(UObject* WorldContext) {
    return TMap<UQuestOverviewCategory*, FQuestCollection>();
}

TMap<TSubclassOf<AActor>, FQuestCollection> ULocQuestStatics::GetQuestsPerNPC(UObject* WorldContext) {
    return TMap<TSubclassOf<AActor>, FQuestCollection>();
}

TArray<UQuestConfig*> ULocQuestStatics::GetQuestsForCategory(UObject* WorldContext, UQuestOverviewCategory* QuestCategory) {
    return TArray<UQuestConfig*>();
}

UQuestManagerSimulationComponent* ULocQuestStatics::GetQuestManager(UObject* WorldContext) {
    return NULL;
}

TArray<UQuestConfig*> ULocQuestStatics::GetQuestDataProjectWide(const UObject* WorldContext) {
    return TArray<UQuestConfig*>();
}

EQuestTier ULocQuestStatics::GetPreviousQuestTier(UObject* WorldContextObject, EQuestTier Tier, bool& bSuccess) {
    return EQuestTier::Tier1;
}

EQuestTier ULocQuestStatics::GetNextQuestTier(EQuestTier Tier, bool& bSuccess) {
    return EQuestTier::Tier1;
}

TArray<UQuestConfig*> ULocQuestStatics::GetAllTutorialQuestData(UObject* WorldContext) {
    return TArray<UQuestConfig*>();
}

TArray<FQuestTierData> ULocQuestStatics::GetAllTiers(UObject* WorldContext) {
    return TArray<FQuestTierData>();
}

TArray<UQuestConfig*> ULocQuestStatics::GetAllQuestsOfTier(UObject* WorldContextObject, EQuestTier Tier, FGameplayTagContainer RequiredTags, FGameplayTagContainer ForbiddenTags) {
    return TArray<UQuestConfig*>();
}

TArray<UQuestOverviewCategory*> ULocQuestStatics::GetAllQuestCategories(const UObject* WorldContext) {
    return TArray<UQuestOverviewCategory*>();
}

TArray<UQuestConfig*> ULocQuestStatics::GetAllMainQuestData(UObject* WorldContext) {
    return TArray<UQuestConfig*>();
}


