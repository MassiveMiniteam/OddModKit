#include "DirectedGraph.h"
#include "DirectedGraphEdge.h"
#include "DirectedGraphNode.h"

UDirectedGraph::UDirectedGraph() {
    this->NodeClass = UDirectedGraphNode::StaticClass();
    this->EdgeClass = UDirectedGraphEdge::StaticClass();
}

void UDirectedGraph::RemoveNode(UDirectedGraphNode* Node) {
}

void UDirectedGraph::RemoveEdge(UDirectedGraphEdge* Edge) {
}

TArray<UDirectedGraphEdge*> UDirectedGraph::GetAllOutgoingEdgesFrom(const UDirectedGraphNode* Node) const {
    return TArray<UDirectedGraphEdge*>();
}

TArray<UDirectedGraphEdge*> UDirectedGraph::GetAllIncomingEdgesTo(const UDirectedGraphNode* Node) const {
    return TArray<UDirectedGraphEdge*>();
}

TArray<UDirectedGraphEdge*> UDirectedGraph::GetAllEdgesConnectedTo(const UDirectedGraphNode* Node) const {
    return TArray<UDirectedGraphEdge*>();
}

bool UDirectedGraph::AreConnectedNodes(const UDirectedGraphNode* NodeA, const UDirectedGraphNode* NodeB) const {
    return false;
}

UDirectedGraphNode* UDirectedGraph::AddNode() {
    return NULL;
}

UDirectedGraphEdge* UDirectedGraph::AddEdge(UDirectedGraphNode* StartNode, UDirectedGraphNode* EndNode) {
    return NULL;
}


