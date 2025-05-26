#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PresentationActorComponent.h"
#include "IdleAnimationComponent_EventDelegate.h"
#include "IdleAnimationPresentationComponent.generated.h"

class UAnimMontage;
class UAnimationPresentationComponent;
class USkeletalMeshComponent;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UIdleAnimationPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAnimationPresentationComponent> AnimationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentIdleDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag IdleBreakAnimationTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag IdleForceAnimationTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DurationIdlingBeforePlayingAnimationsMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DurationIdlingBeforePlayingAnimationsMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeBetweenAnimations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWhenNotMoving;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWhenIdleAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameplayTag> IdleBreakBlacklist;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIdleAnimationComponent_Event OnIdleStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIdleAnimationComponent_Event OnIdleEnd;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float DurationIdlingBeforePlayingAnimations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsPlayingIdleBreak;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsForceIdle;
    
public:
    UIdleAnimationPresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetForceIdle(bool bForceIdleIn);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnIdleBreakMontageStop(UAnimMontage* Montage, bool bInterrupted);
    
    UFUNCTION(BlueprintCallable)
    void OnAnimationStopped(UAnimationPresentationComponent* AnimationPresentationComponent, FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    void OnAnimationPlayed(UAnimationPresentationComponent* AnimationPresentationComponent, FGameplayTag Tag);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsIdleing() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsIdleBreakAllowed() const;
    
};

