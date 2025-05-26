#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "CopyToolUseable.h"
#include "SelectedRecipeChangedEventDelegate.h"
#include "SelectableRecipesSimulationComponent.generated.h"

class URecipeConfig;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API USelectableRecipesSimulationComponent : public USimulationActorComponent, public ICopyToolUseable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URecipeConfig*> AvailableRecipes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseAllRecipes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    URecipeConfig* CurrentSelectedRecipe;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URecipeConfig* DefaultRecipe;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSelectedRecipeChangedEvent OnRecipeChanged;
    
    USelectableRecipesSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetRecipe(URecipeConfig* InRecipe);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSelectedRecipeValid() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URecipeConfig* GetSelectedRecipe() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URecipeConfig* GetDefaultRecipe() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<URecipeConfig*> GetAvailableRecipes() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void AutoSelectRecipeIfThereIsOnlyOne();
    

    // Fix for true pure virtual functions not being implemented
};

