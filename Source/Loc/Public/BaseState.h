#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Fixed.h"
#include "SerializedSimulationObject.h"
#include "Templates/SubclassOf.h"
#include "BaseState.generated.h"

class AActor;
class UBehaviorTree;
class UGameplayEffect;
class UObject;
class USimulationTimerComponent;
class UStateConditionStrategy;

UCLASS(Blueprintable)
class LOC_API UBaseState : public USerializedSimulationObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBehaviorTree* BehaviorTree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLoopBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> StateOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGameplayEffect>> GameplayEffectsWhileInThisState;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UGameplayEffect*> ActiveGameplayEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableBehaviorTreeTick;
    
public:
    UBaseState();

    UFUNCTION(BlueprintCallable)
    void SetBlackboardValueObject(FName KeyName, UObject* ObjectValue);
    
    UFUNCTION(BlueprintCallable)
    void SetBlackboardValueIntVector(FName KeyName, FIntVector IntVector);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUtilityTimerFired(USimulationTimerComponent* SimulationTimerComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTick(FFixed DeltaTime);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStateLeft();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStateEntered(bool bIsLoading);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBehaviourTreeFinished_Event(bool bIsLooping);
    
    UFUNCTION(BlueprintCallable)
    void OnBehaviourTreeFinished(bool bIsLooping);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool IsEnterToThisPossible();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Init();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UObject* GetBlackboardValueObject(FName KeyName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector GetBlackboardValueIntVector(FName KeyName) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CheckStateConditionStrategy(TSubclassOf<UStateConditionStrategy> Strategy) const;
    
};

