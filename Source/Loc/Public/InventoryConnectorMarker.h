#pragma once
#include "CoreMinimal.h"
#include "ChildPresentationActor.h"
#include "Templates/SubclassOf.h"
#include "InventoryConnectorMarker.generated.h"

class UInputContextDragPlacement;

UCLASS(Blueprintable)
class LOC_API AInventoryConnectorMarker : public AChildPresentationActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UInputContextDragPlacement>> InputContextsThatMakeThisVisible;
    
public:
    AInventoryConnectorMarker(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetConnectorVisibility(bool bVisible);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnDragToolStateChanged(UInputContextDragPlacement* InputContext, bool bIsInDragMode, bool bIsInDestructionMode);
    
    UFUNCTION(BlueprintCallable)
    void OnBuildContextStarted();
    
    UFUNCTION(BlueprintCallable)
    void OnBuildContextEnded();
    
};

