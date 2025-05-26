#pragma once
#include "CoreMinimal.h"
#include "EDestructionReason.h"
#include "LocActorComponent.h"
#include "PresentationActorComponent.generated.h"

class ASimulationActor;
class IPresentationObjectInterface;
class UPresentationObjectInterface;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOCCORE_API UPresentationActorComponent : public ULocActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseAggregatedTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AggregatedPhaseCounts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TScriptInterface<IPresentationObjectInterface> PresentationActor;
    
    UPresentationActorComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPresentationPreBegin(bool bIsLoading);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPresentationEnd(EDestructionReason Reason);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPresentationBegin(bool bIsLoading);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASimulationActor* GetSimulationActor() const;
    
};

