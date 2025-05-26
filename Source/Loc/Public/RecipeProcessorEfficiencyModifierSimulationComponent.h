#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "RecipeProcessorEfficiencyModifierSimulationComponent.generated.h"

class ASimulationPlayer;
class UConstructionAssemblySimulationComponent;
class UCraftedRecipesCounterSimulationComponent;
class UPositionSimulationComponent;
class URecipeProcessorSimulationComponent;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API URecipeProcessorEfficiencyModifierSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed StartValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Modifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinT;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxT;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CountUntilTIncrements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URecipeProcessorSimulationComponent* RecipeProcessor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPositionSimulationComponent* MyPositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UConstructionAssemblySimulationComponent* AssemlyComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatsComponent* StatsComponent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UCraftedRecipesCounterSimulationComponent> CraftedRecipesCounter;
    
public:
    URecipeProcessorEfficiencyModifierSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnPositionChanged(UPositionSimulationComponent* PositionComponent, FIntVector LastPosition);
    
    UFUNCTION(BlueprintCallable)
    void OnGridCellChanged(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable)
    void OnDisassemble(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingSimulationPlayer);
    
    UFUNCTION()
    void OnCrafedRecipesAmountChanged(UCraftedRecipesCounterSimulationComponent* Component, int64 Value);
    
public:
    UFUNCTION(BlueprintCallable)
    void LogDebugValues(int32 From, int32 To);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetPercentage();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCurrentValue();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed CalculateValue(int32 Count);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 CalculateT(int32 Count);
    
};

