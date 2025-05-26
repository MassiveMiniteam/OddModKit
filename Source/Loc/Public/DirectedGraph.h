#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DirectedGraphEventDelegate.h"
#include "Templates/SubclassOf.h"
#include "DirectedGraph.generated.h"

class UDirectedGraphEdge;
class UDirectedGraphNode;

UCLASS(Blueprintable)
class LOC_API UDirectedGraph : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDirectedGraphNode> NodeClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDirectedGraphEdge> EdgeClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UDirectedGraphNode*> Nodes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UDirectedGraphEdge*> Edges;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectedGraphEvent OnGraphUpdated;
    
    UDirectedGraph();

    UFUNCTION(BlueprintCallable)
    void RemoveNode(UDirectedGraphNode* Node);
    
    UFUNCTION(BlueprintCallable)
    void RemoveEdge(UDirectedGraphEdge* Edge);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UDirectedGraphEdge*> GetAllOutgoingEdgesFrom(const UDirectedGraphNode* Node) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UDirectedGraphEdge*> GetAllIncomingEdgesTo(const UDirectedGraphNode* Node) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UDirectedGraphEdge*> GetAllEdgesConnectedTo(const UDirectedGraphNode* Node) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreConnectedNodes(const UDirectedGraphNode* NodeA, const UDirectedGraphNode* NodeB) const;
    
    UFUNCTION(BlueprintCallable)
    UDirectedGraphNode* AddNode();
    
    UFUNCTION(BlueprintCallable)
    UDirectedGraphEdge* AddEdge(UDirectedGraphNode* StartNode, UDirectedGraphNode* EndNode);
    
};

