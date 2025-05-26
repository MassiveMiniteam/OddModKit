#include "DirectedGraphEdge.h"

UDirectedGraphEdge::UDirectedGraphEdge() {
    this->StartNode = NULL;
    this->TargetNode = NULL;
    this->Graph = NULL;
}

void UDirectedGraphEdge::Remove() {
}

bool UDirectedGraphEdge::IsGoingInto(const UDirectedGraphNode* Node) const {
    return false;
}

bool UDirectedGraphEdge::IsConnectedTo(const UDirectedGraphNode* Node) const {
    return false;
}

bool UDirectedGraphEdge::IsComingOutOf(const UDirectedGraphNode* Node) const {
    return false;
}


