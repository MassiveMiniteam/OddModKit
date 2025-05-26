#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameplayTagContainer.h"
#include "WidgetHookArray.h"
#include "CachedItemRecipeRelationshipArray.h"
#include "InjectedRecipeArray.h"
#include "Templates/SubclassOf.h"
#include "LocGameplaySubsystem.generated.h"

class ASimulationActor;
class UBiomeCellConfig;
class UBiomeConfig;
class UConstructableConfig;
class UGlobalClassMappings;
class UGlossaryCategoryData;
class UGlossaryGameplayData;
class UInputActionCategoryData;
class UItemConfig;
class UObject;
class UObjectLibrary;
class UQuestConfig;
class UQuestOverviewCategory;
class URecipeConfig;
class USingleCustomizationConfig;
class USingleShopItemConfig;
class UUnlockConditionWrapper;
class UUnlockableAction;
class UUnlockableDataAsset;
class UUnlockableTier;
class UWidgetHook;
class UWorldGenerationMod_BiomeConfig;
class UWorldGenerationMod_CellConfig;

UCLASS(Blueprintable)
class LOC_API ULocGameplaySubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObjectLibrary* ItemConfigLibrary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObjectLibrary* ConstructableConfigLibrary;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UClass*, FWidgetHookArray> WidgetHooks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UItemConfig*> AllItemConfigs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UWorldGenerationMod_BiomeConfig*> AllWorldGenerationMods_Biomes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UWorldGenerationMod_CellConfig*> AllWorldGenerationMods_Cells;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UConstructableConfig*> AllConstructableConfigs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USingleCustomizationConfig*> AllSingleCustomizations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USingleShopItemConfig*> AllSingleShopItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UItemConfig*, FCachedItemRecipeRelationshipArray> CachedItemRecipeRelationship;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftClassPtr<ASimulationActor>, UConstructableConfig*> AllConstructableConfigMapping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UUnlockConditionWrapper*> AllCharacterUnlockWrappers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URecipeConfig*> AllRecipeConfigs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftClassPtr<ASimulationActor>, FInjectedRecipeArray> AllInjectedRecipeConfigs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UUnlockableDataAsset*> AllUnlockables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UUnlockableTier*> TierUnlockables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UQuestOverviewCategory*> AllQuestCategories;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UQuestConfig*> QuestDataProjectWide;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UQuestConfig*> MainlineQuests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UQuestConfig*> TutorialQuests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGlossaryGameplayData*> GlossaryGameplayDataAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGlobalClassMappings* GlobalClassMappings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGlossaryCategoryData*> AllSimulationActorGlossaryData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInputActionCategoryData*> AllInputActionCategoryDataAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UUnlockableAction*> AllUnlockableActionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UUnlockableDataAsset*> AllUnlockablePlayerUpgrades;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBiomeConfig*> AllBiomeConfigs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBiomeCellConfig*> AllBiomeCellConfigs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ASimulationActor>> AIPerceptionIgnoreDefaultClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASimulationActor> GrassSimulationActor;
    
    ULocGameplaySubsystem();

    UFUNCTION(BlueprintCallable)
    void UnregisterWidgetHook(UClass* Class, TSubclassOf<UWidgetHook> Hook);
    
    UFUNCTION(BlueprintCallable)
    void RegisterWidgetHook(UClass* Class, TSubclassOf<UWidgetHook> Hook);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnModsChanged();
    
public:
    UFUNCTION(BlueprintCallable)
    TArray<TSubclassOf<UWidgetHook>> GetWidgetHooks(UClass* Class);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UUnlockableDataAsset*> GetAllUnlockableDataAssets(const UObject* WorldContext, FGameplayTagContainer RequiredTags, FGameplayTagContainer ForbiddenTags);
    
};

