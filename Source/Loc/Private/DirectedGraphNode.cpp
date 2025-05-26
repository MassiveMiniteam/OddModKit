#include "DirectedGraphNode.h"

UDirectedGraphNode::UDirectedGraphNode() {
    this->Graph = NULL;
}

void UDirectedGraphNode::Remove() {
}

TArray<UDirectedGraphEdge*> UDirectedGraphNode::GetAllOutgoingEdges() const {
    return TArray<UDirectedGraphEdge*>();
}

TArray<UDirectedGraphEdge*> UDirectedGraphNode::GetAllIncomingEdges() const {
    return TArray<UDirectedGraphEdge*>();
}

void UDirectedGraphNode::CreateOutgoingEdge(UDirectedGraphNode* TargetNode) {
}


