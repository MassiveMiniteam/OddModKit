#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputContext.h"
#include "Templates/SubclassOf.h"
#include "DeleteRelocateInputContext.generated.h"

class AActor;
class ALocPlayerController;
class UConstructionAssemblySimulationComponent;
class UInputActionData;
class UInputContextConstructionToolsCursor;

UCLASS(Blueprintable)
class LOC_API UDeleteRelocateInputContext : public UInputContext {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint PreviousHoveredCell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint StartGridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInDestructModeDrag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextConstructionToolsCursor* CursorInputContext;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UConstructionAssemblySimulationComponent* HoveredActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UConstructionAssemblySimulationComponent*> ComponentsMarkedForDelete;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* RelocateAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* DeconstructInputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* CancelInputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> CursorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> GridIndicatorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UInputContext> GamepadMovementInputContextClass;
    
public:
    UDeleteRelocateInputContext();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRelocateSuccess();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRelocateFail();
    
    UFUNCTION(BlueprintCallable)
    void OnRelocateAction(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnRelocate();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnNewCellHovered(FIntPoint Cell, FIntPoint PreviousCell);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnMarkAsBeingDeconstructed(UConstructionAssemblySimulationComponent* AssemblyComponent, bool bIsAboutBeingDeconstructed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLeftDestructMode();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHoveredActorChanged(UConstructionAssemblySimulationComponent* CurrentlyHoveredActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEnteredDestructMode();
    
    UFUNCTION(BlueprintCallable)
    void OnDeconstructAction(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDeconstruct();
    
    UFUNCTION(BlueprintCallable)
    void OnCancelInput(UInputActionData* InputAction, ALocPlayerController* Player);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasCurrentlyMarkedActorsForDelete() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UConstructionAssemblySimulationComponent* GetCurrentlyHoveredActor() const;
    
};

