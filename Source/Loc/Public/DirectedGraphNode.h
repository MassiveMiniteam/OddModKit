#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DirectedGraphNode.generated.h"

class UDirectedGraph;
class UDirectedGraphEdge;
class UDirectedGraphNode;

UCLASS(Blueprintable)
class UDirectedGraphNode : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDirectedGraph* Graph;
    
    UDirectedGraphNode();

    UFUNCTION(BlueprintCallable)
    void Remove();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UDirectedGraphEdge*> GetAllOutgoingEdges() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UDirectedGraphEdge*> GetAllIncomingEdges() const;
    
    UFUNCTION(BlueprintCallable)
    void CreateOutgoingEdge(UDirectedGraphNode* TargetNode);
    
};

