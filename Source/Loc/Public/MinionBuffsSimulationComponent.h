#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SimulationActorComponent.h"
#include "MinionBuffComponent_DelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "MinionBuffsSimulationComponent.generated.h"

class ASimulationActor;
class UGameplayEffect;
class UInventoryComponent;
class UItemConfig;
class UMinionControllerSimulationBaseComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMinionBuffsSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMinionBuffComponent_Delegate OnActiveBuffsChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference BuffInventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* BuffInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGameplayEffect>> CachedActiveBuffs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMinionControllerSimulationBaseComponent* MinionController;
    
public:
    UMinionBuffsSimulationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnMinionRemoved(UMinionControllerSimulationBaseComponent* MinionControlComponent, ASimulationActor* Minion);
    
    UFUNCTION(BlueprintCallable)
    void OnMinionAdded(UMinionControllerSimulationBaseComponent* MinionControlComponent, ASimulationActor* Minion);
    
    UFUNCTION(BlueprintCallable)
    void OnInventoryChanged(UInventoryComponent* Inventory, bool bAdded, UItemConfig* Item);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<TSubclassOf<UGameplayEffect>> GetActiveBuffs() const;
    
};

