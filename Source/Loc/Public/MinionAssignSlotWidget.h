#pragma once
#include "CoreMinimal.h"
#include "NavUserWidget.h"
#include "OnAssignedMinionChangedDelegate.h"
#include "MinionAssignSlotWidget.generated.h"

class UInputActionData;
class UInventoryComponent;
class UItemMinionConfig;
class UMinionControllerSimulationBaseComponent;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UMinionAssignSlotWidget : public UNavUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemMinionConfig* MinionConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* NextMinionActionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* PrevMinionActionData;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAssignedMinionChanged OnAssignedMinionChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMinionControllerSimulationBaseComponent* MinionController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* InventoryComponent;
    
public:
    UMinionAssignSlotWidget();

    UFUNCTION(BlueprintCallable)
    void Setup(UMinionControllerSimulationBaseComponent* InMinionController, UItemMinionConfig* InMinionConfig, int32 InWidgetIndex);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RefreshUI();
    
    UFUNCTION(BlueprintCallable)
    void PrevIndex();
    
    UFUNCTION(BlueprintCallable)
    void NextIndex();
    
};

