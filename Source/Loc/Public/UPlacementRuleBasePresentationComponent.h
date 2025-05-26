#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "Templates/SubclassOf.h"
#include "UPlacementRuleBasePresentationComponent.generated.h"

class UGridPlacementRuleConfig;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UUPlacementRuleBasePresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGridPlacementRuleConfig> PlacementRuleListeningClass;
    
public:
    UUPlacementRuleBasePresentationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StopIndicationEvent();
    
    UFUNCTION(BlueprintCallable)
    void StopIndication(TSubclassOf<UGridPlacementRuleConfig> PlacementRuleConfig);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartIndicationEvent();
    
    UFUNCTION(BlueprintCallable)
    void StartIndication(TSubclassOf<UGridPlacementRuleConfig> PlacementRuleConfig);
    
};

