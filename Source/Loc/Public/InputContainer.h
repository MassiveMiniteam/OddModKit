#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AddInputContextItem.h"
#include "Templates/SubclassOf.h"
#include "InputContainer.generated.h"

class ALocPlayerController;
class UInputActionData;
class UInputContext;

UCLASS(Blueprintable)
class LOC_API UInputContainer : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInputContext*> InputContexts;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAddInputContextItem> InputContextsToAdd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInputContext*> InputContextsToRemove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsActive;
    
    UInputContainer();

    UFUNCTION(BlueprintCallable)
    void TickContainer(float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    void StopContainer(bool bForce);
    
    UFUNCTION(BlueprintCallable)
    void StartContainer();
    
    UFUNCTION(BlueprintCallable)
    void PushInputContextBelow(UInputContext* Context, UInputContext* BelowContext);
    
    UFUNCTION(BlueprintCallable)
    void PushInputContext(UInputContext* Context);
    
    UFUNCTION(BlueprintCallable)
    void PopInputContext(UInputContext* Context);
    
    UFUNCTION(BlueprintCallable)
    void OnInputAxis(UInputActionData* InputAction, ALocPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable)
    void OnInputAction(UInputActionData* InputAction, ALocPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputContext* GetFirstInputContextOfType(TSubclassOf<UInputContext> Class) const;
    
};

