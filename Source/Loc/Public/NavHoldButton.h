#pragma once
#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "NavButton.h"
#include "NavInteractionEventDelegate.h"
#include "OnInteractionTimeUpdateDelegate.h"
#include "NavHoldButton.generated.h"

class UHoldInteractionData;
class USoundCue;

UCLASS(Blueprintable)
class LOC_API UNavHoldButton : public UNavButton {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* OnHoldStartedSound;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnInteractionTimeUpdate HoldUpdate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNavInteractionEvent OnFailedInteractionAttempt;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UHoldInteractionData* Interaction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle HoldInteractionTimerHandle;
    
public:
    UNavHoldButton();

private:
    UFUNCTION(BlueprintCallable)
    void UpdateHoldInteractions();
    
public:
    UFUNCTION(BlueprintCallable)
    void SetHoldDuration(float Duration);
    
};

