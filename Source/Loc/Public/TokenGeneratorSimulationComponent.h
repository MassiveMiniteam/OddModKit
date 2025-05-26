#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SimulationActorComponent.h"
#include "TokenGeneratorEventDelegate.h"
#include "TokenGeneratorSimulationComponent.generated.h"

class UInventoryComponent;
class UItemConfig;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTokenGeneratorSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTokenGeneratorEvent OnProgressChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference TokenInventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemConfig* ShopTokenItemConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* TokenInventory;
    
public:
    UTokenGeneratorSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetTokenInventory(UInventoryComponent* InventoryComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemConfig* GetTokenConfig() const;
    
    UFUNCTION(BlueprintPure)
    int64 GetTargetScore() const;
    
    UFUNCTION(BlueprintPure)
    int64 GetCurrentScore() const;
    
};

