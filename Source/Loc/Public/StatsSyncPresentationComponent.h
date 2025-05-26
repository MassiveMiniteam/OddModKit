#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "PresentationActorComponent.h"
#include "StatsSyncPresentationComponent.generated.h"

class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UStatsSyncPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameplayTag> TagsToSync;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> FromStatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> TargetStatsComponent;
    
    UStatsSyncPresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void OnGameplayStatChanged(UStatsComponent* StatsComponent, FGameplayTag Tag, FFixed OldValue, FFixed NewValue);
    
};

