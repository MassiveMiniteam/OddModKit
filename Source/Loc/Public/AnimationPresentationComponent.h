#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "PresentationActorComponent.h"
#include "AnimationContainerMapping.h"
#include "AnimationPresentationTagEventDelegate.h"
#include "StaticMeshAnimationRuntimeItem.h"
#include "AnimationPresentationComponent.generated.h"

class UAnimMetaData;
class UAnimMontage;
class USceneComponent;
class USkeletalMeshComponent;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UAnimationPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<USceneComponent>, FTransform> InitialTransforms;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceStaticMeshTickOnce;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationPresentationTagEvent OnAnimationPlayed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationPresentationTagEvent OnAnimationStopped;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationPresentationTagEvent OnPlayAnimationContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SectionBlendValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAnimationContainerMapping> AnimationContainerMappings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStaticMeshAnimationRuntimeItem> StaticMeshRuntimeItems;
    
    UAnimationPresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StopAnimationWithTag(FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    void StopAllAnimations();
    
    UFUNCTION(BlueprintCallable)
    void PlayAnimationWithTag(FGameplayTag Tag, float AnimationRate, float TimeToStartMontage, bool ChooseRandomFromContainer);
    
    UFUNCTION(BlueprintCallable)
    void PlayAnimationWithMetadataTag(FGameplayTag Tag, FGameplayTag MetaTag, float AnimationRate, float TimeToStartMontage);
    
    UFUNCTION(BlueprintCallable)
    void PlayAnimationDirectlyToLastFrame(FGameplayTag Tag, bool ChooseRandomFromContainer);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnStatChanged(UStatsComponent* StatsComponentIn, FGameplayTag Tag, FFixed OldValue, FFixed NewValue);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnimationWithTagPlaying(FGameplayTag Tag) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ImplementsAnimationTag(FGameplayTag Tag) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimMontage* GetAnimMontageByTag(FGameplayTag Tag) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UAnimMetaData*> GetAnimationMetaData(FGameplayTag Tag) const;
    
};

