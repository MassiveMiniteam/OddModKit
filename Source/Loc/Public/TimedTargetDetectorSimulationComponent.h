#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "SimulationTimerComponent.h"
#include "Templates/SubclassOf.h"
#include "TimedTargetDetectorTargetsUpdatedDelegate.h"
#include "TimedTargetDetectorSimulationComponent.generated.h"

class UGameplayAbilityTargeting;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTimedTargetDetectorSimulationComponent : public USimulationTimerComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimedTargetDetectorTargetsUpdated OnAvailableTargetsUpdated;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed RefreshInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayAbilityTargeting> TargetingClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer RequiredBiomeCellTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ForbiddenBiomeCellTags;
    
public:
    UTimedTargetDetectorSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void TriggerRetargeting();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGameplayTagContainer GetRequiredBiomeCellTags();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 GetRadius();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGameplayTagContainer GetForbiddenBiomeCellTags();
    
};

