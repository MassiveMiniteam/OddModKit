#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"
#include "InteractionStrategy.generated.h"

class UAchievement;
class UInteractionPresentationComponent;

UCLASS(Abstract, Blueprintable, meta = (ShowWorldContextPin))
class LOC_API UInteractionStrategy : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText InteractionDisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisplayAsHold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLimitInteractionRangeForMouse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxInteractionDistanceForMouse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxInteractionHeightDistanceForMouse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer CurrentInputContextTagsThatPreventThisInteraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ExcludingTagsOnStatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer RequiredTagsOnStatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAchievement* AchievementOnExecute;
    
public:
    UInteractionStrategy();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInteractionExecutionTriggered(UInteractionPresentationComponent* InteractionComponent) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsInteractionCurrentlyPossible(const UInteractionPresentationComponent* InteractionComponent) const;
    
};

