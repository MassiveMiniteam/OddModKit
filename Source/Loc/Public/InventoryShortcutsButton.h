#pragma once
#include "CoreMinimal.h"
#include "NavUserWidget.h"
#include "InventoryShortcutsButton.generated.h"

class ASimulationActor;
class UInventoryComponent;
class USoundBase;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UInventoryShortcutsButton : public UNavUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* SourceInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* TargetInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ASimulationActor>> TargetActorBlacklist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowTooltipLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* SuccessSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* FailSound;
    
public:
    UInventoryShortcutsButton();

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateEnableState();
    
public:
    UFUNCTION(BlueprintCallable)
    void SetInventories(UInventoryComponent* InSourceInventory, UInventoryComponent* InTargetInventory);
    
protected:
    UFUNCTION(BlueprintCallable)
    void PlaySuccessSound();
    
    UFUNCTION(BlueprintCallable)
    void PlayFailSound();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTargetInventoryEmpty();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSourceInventoryEmpty();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DoesTargetInventoryContainAnyItemOfSourceInventory();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanAddAnyItemToTargetInventory();
    
};

