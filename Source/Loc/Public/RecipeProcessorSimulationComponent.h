#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "CraftingFinishedEventDelegate.h"
#include "CraftingResponseEventDelegate.h"
#include "ECraftingStatusCode.h"
#include "RecipeChangedEventDelegate.h"
#include "RecipeProcessorFloatEventDelegate.h"
#include "Templates/SubclassOf.h"
#include "RecipeProcessorSimulationComponent.generated.h"

class UDifficultySettingsSubsystem;
class UInventoryComponent;
class UInventoryRuleAllowItem;
class URecipeCondition;
class URecipeConfig;
class USelectableRecipesSimulationComponent;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API URecipeProcessorSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRecipeChangedEvent OnRecipeChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCraftingFinishedEvent OnCraftingFinished;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCraftingResponseEvent OnCraftingStatusChange;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRecipeProcessorFloatEvent OnCraftingProgressChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRecipeProcessorFloatEvent OnProductionRatePerMinuteChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference InputInventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference OutputInventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<URecipeCondition>> CraftingConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> InputInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> OutputInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USelectableRecipesSimulationComponent> RecipeSelectorComponent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInventoryRuleAllowItem*> AllowItemRulesInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInventoryRuleAllowItem*> AllowItemRulesOutput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed CurrentCraftProgress;
    
public:
    URecipeProcessorSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetRecipe(URecipeConfig* InRecipe);
    
    UFUNCTION(BlueprintCallable)
    void SetInputInventory(UInventoryComponent* InputInventoryIn);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRecipeChanged_Internal(USelectableRecipesSimulationComponent* Component, URecipeConfig* Config);
    
    UFUNCTION(BlueprintCallable)
    void OnDifficultySettingsChanged(UDifficultySettingsSubsystem* Subsystem);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCurrentRecipeValid() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCraftingPossible() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URecipeConfig* GetRecipe() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECraftingStatusCode GetCurrentStatusCode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCurrentProductionRate() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCurrentCraftingProgressPercent() const;
    
};

