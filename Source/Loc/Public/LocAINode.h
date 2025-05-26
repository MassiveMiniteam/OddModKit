#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Fixed.h"
#include "ELocNodeStatus.h"
#include "LocAINode.generated.h"

class ILocAINode;
class ULocAINode;
class UBlackboardComponent;
class USimulationBehaviorTreeComponent;

UINTERFACE(Blueprintable)
class ULocAINode : public UInterface {
    GENERATED_BODY()
};

class ILocAINode : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    ELocNodeStatus RunNode(USimulationBehaviorTreeComponent* Tree, int32 TreeInstanceIndex, UBlackboardComponent* Blackboard, FFixed DeltaTime);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnStart(USimulationBehaviorTreeComponent* Tree, int32 TreeInstanceIndex, UBlackboardComponent* Blackboard, bool bIsLoading);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnEnd(USimulationBehaviorTreeComponent* Tree, int32 TreeInstanceIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnChildNodeRun(USimulationBehaviorTreeComponent* Tree, int32 TreeInstanceIndex, const TScriptInterface<ILocAINode>& Child, ELocNodeStatus Status);
    
};

