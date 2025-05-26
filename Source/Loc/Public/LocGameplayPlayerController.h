#pragma once
#include "CoreMinimal.h"
#include "LocPlayerController.h"
#include "LocGameplayPlayerController.generated.h"

class UInputActionData;

UCLASS(Blueprintable)
class LOC_API ALocGameplayPlayerController : public ALocPlayerController {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* OpenInventoryAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* OpenBuildMenuAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* OpenPathToolAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* OpenTechTreeAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* OpenRelocateToolAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* OpenMapAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* OpenJournalAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* OpenGlossaryAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* OpenCopyToolAction;
    
public:
    ALocGameplayPlayerController(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UnlockAll();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnOpenTechTree(UInputActionData* InputAction, ALocPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnOpenRelocateTool(UInputActionData* InputAction, ALocPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnOpenPauseMenu(UInputActionData* InputAction, ALocPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnOpenPathTool(UInputActionData* InputAction, ALocPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnOpenMap(UInputActionData* InputAction, ALocPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnOpenJournal(UInputActionData* InputAction, ALocPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnOpenInventory(UInputActionData* InputAction, ALocPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnOpenGlossary(UInputActionData* InputAction, ALocPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnOpenCopyTool(UInputActionData* InputAction, ALocPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnOpenBuildMenu(UInputActionData* InputAction, ALocPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EnableInfiniteResources();
    
};

