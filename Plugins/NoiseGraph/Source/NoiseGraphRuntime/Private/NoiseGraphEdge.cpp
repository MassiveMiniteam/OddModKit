#include "NoiseGraphEdge.h"

UNoiseGraphEdge::UNoiseGraphEdge()
{

}

UNoiseGraphEdge::~UNoiseGraphEdge()
{

}

UNoiseGraph* UNoiseGraphEdge::GetGraph() const
{
	return Graph;
}

#if WITH_EDITOR
void UNoiseGraphEdge::SetNodeTitle(const FText& NewTitle)
{
	NodeTitle = NewTitle;
}
#endif // #if WITH_EDITOR