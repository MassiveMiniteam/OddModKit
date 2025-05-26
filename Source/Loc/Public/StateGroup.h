#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SerializedSimulationObject.h"
#include "StateMachineStateWithAdditionalConditions.h"
#include "Templates/SubclassOf.h"
#include "StateGroup.generated.h"

class AActor;
class UGameplayEffect;
class UObject;
class USimulationTimerComponent;

UCLASS(Blueprintable)
class LOC_API UStateGroup : public USerializedSimulationObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> StateOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStateMachineStateWithAdditionalConditions> States;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGameplayEffect>> GameplayEffectsWhileInThisStateGroup;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UGameplayEffect*> ActiveGameplayEffects;
    
public:
    UStateGroup();

    UFUNCTION(BlueprintCallable)
    void SetBlackboardValueObject(FName KeyName, UObject* ObjectValue);
    
    UFUNCTION(BlueprintCallable)
    void SetBlackboardValueIntVector(FName KeyName, FIntVector IntVector);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUtilityTimerFired(USimulationTimerComponent* SimulationTimerComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStateLeft();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStateGroupLeft();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStateGroupEntered(bool bIsLoading);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBehaviourTreeFinished_Event(bool bIsLooping);
    
    UFUNCTION(BlueprintCallable)
    void OnBehaviourTreeFinished(bool bIsLooping);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UObject* GetBlackboardValueObject(FName KeyName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector GetBlackboardValueIntVector(FName KeyName) const;
    
};

