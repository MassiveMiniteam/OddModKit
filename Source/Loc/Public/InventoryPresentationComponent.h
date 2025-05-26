#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "EquipmentPresentationActorSlot.h"
#include "InventoryPresentationComponent.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UInventoryPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, FEquipmentPresentationActorSlot> EquipmentActorSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UInventoryComponent> InventoryComponent;
    
public:
    UInventoryPresentationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void SetPresentationEnabledForSlot(int32 Index, bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    void OnInventorySlotChanged(int32 Index);
    
};

