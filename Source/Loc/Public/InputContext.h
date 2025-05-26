#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "EBranchIsLocalPlayerType.h"
#include "EPlayAnimationCommandOptions.h"
#include "InputActionStateChangedEventDelegate.h"
#include "InputAxisStateChangedEventDelegate.h"
#include "Templates/SubclassOf.h"
#include "InputContext.generated.h"

class ALocPlayerController;
class APlayerController;
class UButtonPromptBarItemSet;
class UGameplayEffect;
class UInputActionData;
class UInputContainer;
class UInputContext;

UCLASS(Blueprintable)
class LOC_API UInputContext : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UInputActionData*, FInputActionStateChangedEvent> BoundInputActions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UInputActionData*, FInputAxisStateChangedEvent> BoundInputAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInputContainer> InputContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bConsumeAllInputs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPushButtonPrompts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStopAnimationOnContextEnd;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UButtonPromptBarItemSet* ButtonPrompts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag PlayerAnimationTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGameplayEffect>> GameplayEffectsWhileInThisContext;
    
public:
    UInputContext();

    UFUNCTION(BlueprintCallable)
    void UnBindOnInputAxis(UInputActionData* InputAction);
    
    UFUNCTION(BlueprintCallable)
    void UnBindOnInputAction(UInputActionData* InputAction);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Tick(float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    void StopContext(bool bForce);
    
    UFUNCTION(BlueprintCallable)
    void StartContext(UInputContainer* Container);
    
    UFUNCTION(BlueprintCallable)
    void SchedulePlayAnimationCommand(FGameplayTag Tag, EPlayAnimationCommandOptions Option, bool bChooseRandomAnimation);
    
    UFUNCTION(BlueprintCallable)
    void PopThisInputContainer();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnStop();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnStart();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnLastStopBeforeDestroy();
    
    UFUNCTION(BlueprintCallable)
    bool OnInputAxis(UInputActionData* InputAction, ALocPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable)
    bool OnInputAction(UInputActionData* InputAction, ALocPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFirstStart();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void IsLocalPlayer(const UObject* WorldContext, APlayerController* PlayerController, EBranchIsLocalPlayerType& OutBranches);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasTag(FGameplayTag Tag) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAnyTag(const FGameplayTagContainer& TagsToCheck) const;
    
protected:
    UFUNCTION(BlueprintCallable)
    UInputContext* GetOrCreateInputContextOfType(TSubclassOf<UInputContext> InputContextType, bool bOnlyFromSameContainer, bool bPushIntoThisContainerIfOriginatesFromAnother);
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    bool GetIsLocalPlayer(const UObject* WorldContext, APlayerController* PlayerController) const;
    
    UFUNCTION(BlueprintCallable)
    void BindOnInputAxis(UInputActionData* InputAction, FInputAxisStateChangedEvent Event);
    
    UFUNCTION(BlueprintCallable)
    void BindOnInputAction(UInputActionData* InputAction, FInputActionStateChangedEvent Event);
    
};

