#include "NoiseGraphAssetEditor/EdGraph_NoiseGraph.h"
#include "NoiseGraphEditorPCH.h"
#include "NoiseGraph.h"
#include "NoiseGraphAssetEditor/EdNode_NoiseGraphNode.h"
#include "NoiseGraphAssetEditor/EdNode_NoiseGraphEdge.h"

UEdGraph_NoiseGraph::UEdGraph_NoiseGraph()
{

}

UEdGraph_NoiseGraph::~UEdGraph_NoiseGraph()
{

}

void UEdGraph_NoiseGraph::RebuildNoiseGraph()
{
	LOG_INFO(TEXT("UNoiseGraphEdGraph::RebuildNoiseGraph has been called"));

	UNoiseGraph* Graph = GetNoiseGraph();

	Clear();

	for (int i = 0; i < Nodes.Num(); ++i)
	{
		if (UEdNode_NoiseGraphNode* EdNode = Cast<UEdNode_NoiseGraphNode>(Nodes[i]))
		{
			if (EdNode->NoiseGraphNode == nullptr)
				continue;

			UNoiseGraphNode* NoiseGraphNode = EdNode->NoiseGraphNode;

			NodeMap.Add(NoiseGraphNode, EdNode);

			Graph->AllNodes.Add(NoiseGraphNode);

			for (int PinIdx = 0; PinIdx < EdNode->Pins.Num(); ++PinIdx)
			{
				UEdGraphPin* Pin = EdNode->Pins[PinIdx];

				if (Pin->Direction != EEdGraphPinDirection::EGPD_Output)
					continue;

				for (int LinkToIdx = 0; LinkToIdx < Pin->LinkedTo.Num(); ++LinkToIdx)
				{
					UNoiseGraphNode* ChildNode = nullptr;
					if (UEdNode_NoiseGraphNode* EdNode_Child = Cast<UEdNode_NoiseGraphNode>(Pin->LinkedTo[LinkToIdx]->GetOwningNode()))
					{
						ChildNode = EdNode_Child->NoiseGraphNode;
					}
					else if (UEdNode_NoiseGraphEdge* EdNode_Edge = Cast<UEdNode_NoiseGraphEdge>(Pin->LinkedTo[LinkToIdx]->GetOwningNode()))
					{
						UEdNode_NoiseGraphNode* Child = EdNode_Edge->GetEndNode();;
						if (Child != nullptr)
						{
							ChildNode = Child->NoiseGraphNode;
						}
					}

					if (ChildNode != nullptr)
					{
						NoiseGraphNode->ChildrenNodes.Add(ChildNode);

						ChildNode->ParentNodes.Add(NoiseGraphNode);
					}
					else
					{
						LOG_ERROR(TEXT("UEdGraph_NoiseGraph::RebuildNoiseGraph can't find child node"));
					}
				}
			}
		}
		else if (UEdNode_NoiseGraphEdge* EdgeNode = Cast<UEdNode_NoiseGraphEdge>(Nodes[i]))
		{
			UEdNode_NoiseGraphNode* StartNode = EdgeNode->GetStartNode();
			UEdNode_NoiseGraphNode* EndNode = EdgeNode->GetEndNode();
			UNoiseGraphEdge* Edge = EdgeNode->NoiseGraphEdge;

			if (StartNode == nullptr || EndNode == nullptr || Edge == nullptr)
			{
				LOG_ERROR(TEXT("UEdGraph_NoiseGraph::RebuildNoiseGraph add edge failed."));
				continue;
			}

			EdgeMap.Add(Edge, EdgeNode);

			Edge->Graph = Graph;
			Edge->Rename(nullptr, Graph, REN_DontCreateRedirectors | REN_DoNotDirty);
			Edge->StartNode = StartNode->NoiseGraphNode;
			Edge->EndNode = EndNode->NoiseGraphNode;
			//Edge->StartNode->Edges.Add(Edge->EndNode, Edge);
			if (Edge->EndNode->Edges.Num() < Edge->EndNode->GetInputs().Num())
			{
				Edge->EndNode->Edges.AddDefaulted(Edge->EndNode->GetInputs().Num());
			}
			int Index = EndNode->Pins.Find(EdgeNode->Pins[1]->LinkedTo[0]);
			Edge->EndNode->Edges[Index] = Edge;
		}
	}

	for (int i = 0; i < Graph->AllNodes.Num(); ++i)
	{
		UNoiseGraphNode* Node = Graph->AllNodes[i];
		if (Node->ParentNodes.Num() == 0)
		{
			Graph->RootNodes.Add(Node);

			SortNodes(Node);
		}

		Node->Graph = Graph;
		Node->Rename(nullptr, Graph, REN_DontCreateRedirectors | REN_DoNotDirty);
	}

	Graph->RootNodes.Sort([&](const UNoiseGraphNode& L, const UNoiseGraphNode& R)
	{
		UEdNode_NoiseGraphNode* EdNode_LNode = NodeMap[&L];
		UEdNode_NoiseGraphNode* EdNode_RNode = NodeMap[&R];
		return EdNode_LNode->NodePosX < EdNode_RNode->NodePosX;
	});
}

UNoiseGraph* UEdGraph_NoiseGraph::GetNoiseGraph() const
{
	return CastChecked<UNoiseGraph>(GetOuter());
}

bool UEdGraph_NoiseGraph::Modify(bool bAlwaysMarkDirty /*= true*/)
{
	bool Rtn = Super::Modify(bAlwaysMarkDirty);

	GetNoiseGraph()->Modify();

	for (int32 i = 0; i < Nodes.Num(); ++i)
	{
		Nodes[i]->Modify();
	}

	return Rtn;
}

void UEdGraph_NoiseGraph::Clear()
{
	UNoiseGraph* Graph = GetNoiseGraph();

	Graph->ClearGraph();
	NodeMap.Reset();
	EdgeMap.Reset();

	for (int i = 0; i < Nodes.Num(); ++i)
	{
		if (UEdNode_NoiseGraphNode* EdNode = Cast<UEdNode_NoiseGraphNode>(Nodes[i]))
		{
			UNoiseGraphNode* NoiseGraphNode = EdNode->NoiseGraphNode;
			if (NoiseGraphNode)
			{
				NoiseGraphNode->ParentNodes.Reset();
				NoiseGraphNode->ChildrenNodes.Reset();
				NoiseGraphNode->Edges.Reset();
			}
		}
	}
}

void UEdGraph_NoiseGraph::SortNodes(UNoiseGraphNode* RootNode)
{
	int Level = 0;
	TArray<UNoiseGraphNode*> CurrLevelNodes = { RootNode };
	TArray<UNoiseGraphNode*> NextLevelNodes;

	while (CurrLevelNodes.Num() != 0)
	{
		int32 LevelWidth = 0;
		for (int i = 0; i < CurrLevelNodes.Num(); ++i)
		{
			UNoiseGraphNode* Node = CurrLevelNodes[i];

			auto Comp = [&](const UNoiseGraphNode& L, const UNoiseGraphNode& R)
			{
				UEdNode_NoiseGraphNode* EdNode_LNode = NodeMap[&L];
				UEdNode_NoiseGraphNode* EdNode_RNode = NodeMap[&R];
				return EdNode_LNode->NodePosX < EdNode_RNode->NodePosX;
			};

			Node->ChildrenNodes.Sort(Comp);
			Node->ParentNodes.Sort(Comp);

			for (int j = 0; j < Node->ChildrenNodes.Num(); ++j)
			{
				NextLevelNodes.Add(Node->ChildrenNodes[j]);
			}
		}

		CurrLevelNodes = NextLevelNodes;
		NextLevelNodes.Reset();
		++Level;
	}
}

void UEdGraph_NoiseGraph::PostEditUndo()
{
	Super::PostEditUndo();

	NotifyGraphChanged();
}

