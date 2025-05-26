#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IncubationComponentEventDelegate.h"
#include "RecipeProcessorFloatEventDelegate.h"
#include "RecipeProcessorSimulationComponent.h"
#include "IncubationRecipeProcessorSimulationComponent.generated.h"

class ASimulationPlayer;
class UConstructionAssemblySimulationComponent;
class UIncubatorSimulationComponent;
class UPositionSimulationComponent;
class USelectableRecipesSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UIncubationRecipeProcessorSimulationComponent : public URecipeProcessorSimulationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRecipeProcessorFloatEvent OnIncubationProgressUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIncubationComponentEvent OnIncubationStepDone;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UIncubatorSimulationComponent> Incubator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPositionSimulationComponent* MyPositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UConstructionAssemblySimulationComponent* MyAssemblyComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanSupportExternalIncubator;
    
public:
    UIncubationRecipeProcessorSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnRelocate(UPositionSimulationComponent* PositionComponent, FIntPoint LastGridPosition);
    
    UFUNCTION(BlueprintCallable)
    void OnIncubatorRecipeChanged(USelectableRecipesSimulationComponent* RecipeSelector);
    
    UFUNCTION(BlueprintCallable)
    void OnDisassemble(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingSimulationPlayer);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UIncubatorSimulationComponent* GetIncubator() const;
    
};

