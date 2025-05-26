#pragma once
#include "CoreMinimal.h"
#include "InventoryShortcutsInventories.h"
#include "NavUserWidget.h"
#include "Templates/SubclassOf.h"
#include "InventoryShortcutSidebar.generated.h"

class ASimulationActor;
class UInventoryShortcutsButton;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UInventoryShortcutSidebar : public UNavUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ASimulationActor>> BlacklistedActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASimulationActor* MyReferencedActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryShortcutsInventories InventoryReferences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
    UInventoryShortcutsButton* Btn_Sort;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
    UInventoryShortcutsButton* Btn_Trash;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
    UInventoryShortcutsButton* Btn_TransferAll;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
    UInventoryShortcutsButton* Btn_PullSame;
    
public:
    UInventoryShortcutSidebar();

    UFUNCTION(BlueprintCallable)
    void Setup(ASimulationActor* ReferencedSimulationActor, FInventoryShortcutsInventories InInventoryReferences);
    
};

