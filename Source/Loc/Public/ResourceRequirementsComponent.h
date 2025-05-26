#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "SimulationActorComponent.h"
#include "ItemStack.h"
#include "OnResourceRequirementsEventDelegate.h"
#include "ResourceRequirementsComponent.generated.h"

class UInventoryComponent;
class UItemConfig;
class UObject;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UResourceRequirementsComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemStack> RequiredItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference StatsComponentReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference DropInventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference InputInventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* DropInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* TargetInventory;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnResourceRequirementsEvent OnRequirementsMet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Tag;
    
    UResourceRequirementsComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void OnTargetInventoryRemoved(UItemConfig* Item, int32 Amount, UObject* Origin);
    
    UFUNCTION(BlueprintCallable)
    void OnTargetInventoryItemAdded(UItemConfig* Item, int32 Amount, UObject* Origin);
    
    UFUNCTION(BlueprintCallable)
    void OnDropInventoryItemRemoved(UItemConfig* Item, int32 Amount, UObject* Origin);
    
    UFUNCTION(BlueprintCallable)
    void OnDropInventoryItemAdded(UItemConfig* Item, int32 Amount, UObject* Origin);
    
};

