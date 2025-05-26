#include "NoiseGraphNodeFactory.h"
#include <EdGraph/EdGraphNode.h>
#include "NoiseGraphAssetEditor/SEdNode_NoiseGraphEdge.h"
#include "NoiseGraphAssetEditor/EdNode_NoiseGraphNode.h"
#include "NoiseGraphAssetEditor/SEdNode_NoiseGraphNode.h"
#include "NoiseGraphAssetEditor/EdNode_NoiseGraphEdge.h"

TSharedPtr<class SGraphNode> FGraphPanelNodeFactory_NoiseGraph::CreateNode(UEdGraphNode* Node) const
{
	if (UEdNode_NoiseGraphNode* EdNode_GraphNode = Cast<UEdNode_NoiseGraphNode>(Node))
	{
		return SNew(SEdNode_NoiseGraphNode, EdNode_GraphNode);
	}
	else if (UEdNode_NoiseGraphEdge* EdNode_Edge = Cast<UEdNode_NoiseGraphEdge>(Node))
	{
		return SNew(SEdNode_NoiseGraphEdge, EdNode_Edge);
	}
	return nullptr;
}

