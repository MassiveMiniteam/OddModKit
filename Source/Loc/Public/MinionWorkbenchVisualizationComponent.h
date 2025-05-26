#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PresentationActorComponent.h"
#include "ECraftingStatusCode.h"
#include "MinionWorkbenchConfig.h"
#include "WorkerBenchPair.h"
#include "MinionWorkbenchVisualizationComponent.generated.h"

class UInventoryComponent;
class UItemMinionConfig;
class UManpowerSimulationComponent;
class URecipeConfig;
class URecipeProcessorSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMinionWorkbenchVisualizationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMinionWorkbenchConfig> Workbenches;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWorkerBenchPair> WorkerWorkbenchMeshPairs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* MinionInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URecipeProcessorSimulationComponent* RecipeProcessor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UManpowerSimulationComponent> Manpower;
    
public:
    UMinionWorkbenchVisualizationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnWorkSlotChanged(UManpowerSimulationComponent* ManpowerSimulationComponent, int32 Slot);
    
    UFUNCTION(BlueprintCallable)
    void OnInventorySlotChanged(int32 Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnCraftingProcessChanged_Event(URecipeProcessorSimulationComponent* Component, URecipeConfig* Recipe, ECraftingStatusCode ResponseCode);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void MinionInventorySlotChanged_Event(int32 Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetWorldTransformForMinion(FMinionWorkbenchConfig WorkbenchConfig, float DistanceOffsetToWorkstation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetTransformForWorkbench(FMinionWorkbenchConfig WorkbenchConfig);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetRelativeTransformForMinion(FMinionWorkbenchConfig WorkbenchConfig);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemMinionConfig* GetMinionConfigAtInventoryIndex(int32 InventoryIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool bHasPlayerControlledMinions();
    
};

