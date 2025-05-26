#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "ECraftingStatusCode.h"
#include "IncubatorBoolEventDelegate.h"
#include "IncubatorEventDelegate.h"
#include "IncubatorProgressEventDelegate.h"
#include "IncubatorRecipeChangeEventDelegate.h"
#include "IncubatorSimulationComponent.generated.h"

class UIncubationRecipeProcessorSimulationComponent;
class UInventoryComponent;
class URecipeConfig;
class URecipeProcessorSimulationComponent;
class USelectableRecipesSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UIncubatorSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIncubatorProgressEvent OnIncubatorProgressChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIncubatorProgressEvent OnIncubatorCompleted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIncubatorRecipeChangeEvent OnIncubatorRecipeChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIncubatorBoolEvent OnIncubatorCraftingStatusChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIncubatorEvent OnLinkedRecipeProcessorListChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetOnIncubatorDone;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USelectableRecipesSimulationComponent* RecipeSelector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference OutputInventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSupportInputAddon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CurrentAmount;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UIncubationRecipeProcessorSimulationComponent>> RecipeProcessors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* OutputInventory;
    
public:
    UIncubatorSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool SupportsInputAddon() const;
    
    UFUNCTION(BlueprintCallable)
    void ResetProgression();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnSingleRecipeprocessorStatusChanged(URecipeProcessorSimulationComponent* Component, URecipeConfig* Recipe, ECraftingStatusCode ResponseCode);
    
    UFUNCTION(BlueprintCallable)
    void OnRecipeChanged(USelectableRecipesSimulationComponent* Component, URecipeConfig* Recipe);
    
    UFUNCTION(BlueprintCallable)
    void OnIncubationStepCompleted(UIncubationRecipeProcessorSimulationComponent* IncubationProcessor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCurrentlyCrafting();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetProgressInPercent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetProgress() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UIncubationRecipeProcessorSimulationComponent*> GetLinkedRecipeProcessors();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentAmount() const;
    
    UFUNCTION(BlueprintCallable)
    void AddAmount(int32 Amount);
    
};

