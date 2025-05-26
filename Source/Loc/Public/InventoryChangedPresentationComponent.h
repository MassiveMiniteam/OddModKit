#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "InventoryChangedPresentationComponent.generated.h"

class UInventoryComponent;
class UItemConfig;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UInventoryChangedPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> Inventory;
    
public:
    UInventoryChangedPresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void Unbind();
    
    UFUNCTION(BlueprintCallable)
    void SetAndBindInventory(UInventoryComponent* InInventory);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnInventoryItemRemoved(UItemConfig* Config, int32 Amount, UObject* Origin);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnInventoryItemAdded(UItemConfig* Config, int32 Amount, UObject* Origin);
    
};

