#pragma once
#include <EdGraphUtilities.h>
#include <EdGraph/EdGraphNode.h>

class FGraphPanelNodeFactory_NoiseGraph : public FGraphPanelNodeFactory
{
	virtual TSharedPtr<class SGraphNode> CreateNode(UEdGraphNode* Node) const override;
};