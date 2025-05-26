#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DirectedGraphEdge.generated.h"

class UDirectedGraph;
class UDirectedGraphNode;

UCLASS(Blueprintable)
class UDirectedGraphEdge : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDirectedGraphNode* StartNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDirectedGraphNode* TargetNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDirectedGraph* Graph;
    
    UDirectedGraphEdge();

    UFUNCTION(BlueprintCallable)
    void Remove();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsGoingInto(const UDirectedGraphNode* Node) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsConnectedTo(const UDirectedGraphNode* Node) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsComingOutOf(const UDirectedGraphNode* Node) const;
    
};

