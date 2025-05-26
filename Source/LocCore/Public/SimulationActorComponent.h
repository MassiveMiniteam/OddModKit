#pragma once
#include "CoreMinimal.h"
#include "EDestructionReason.h"
#include "LocActorComponent.h"
#include "LocCoreSavable.h"
#include "SimulationActorComponent.generated.h"

class ASimulationActor;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOCCORE_API USimulationActorComponent : public ULocActorComponent, public ILocCoreSavable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ASimulationActor> SimulationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPerformance_OnSimulationBeginImplemented;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPerformance_OnSimulationPreBeginImplemented;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPerformance_OnSimulationEndImplemented;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPredictionKeepAlwaysAlive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsPredictedComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 PredictionTimeoutCounter;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UObject>> PredictionKeepAliveObjects;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanEverTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartTickEnabled;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsTickEnabled;
    
public:
    USimulationActorComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetTickEnabled(bool bShouldTick);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSimulationPreBegin(bool bIsLoading);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSimulationEnd(EDestructionReason Reason);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSimulationBegin(bool bIsLoading);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPresentationActor();
    
    UFUNCTION(BlueprintCallable)
    void OnDestroyingPresentationActor();
    
    UFUNCTION(BlueprintCallable)
    void OnCreatedAsPredictionComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetSupportsPrediction();
    

    // Fix for true pure virtual functions not being implemented
    UFUNCTION()
    void OnAllSaveGameActorsLoadedAndRegistered() override PURE_VIRTUAL(OnAllSaveGameActorsLoadedAndRegistered,);
    
};

