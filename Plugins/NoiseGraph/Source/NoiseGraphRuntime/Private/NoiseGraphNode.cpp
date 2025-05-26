#include "NoiseGraphNode.h"
#include "NoiseGraph.h"

#define LOCTEXT_NAMESPACE "NoiseGraphNode"

UNoiseGraphNode::UNoiseGraphNode()
{
#if WITH_EDITORONLY_DATA
	CompatibleGraphType = UNoiseGraph::StaticClass();

	BackgroundColor = FLinearColor::Black;
#endif
}

UNoiseGraphNode::~UNoiseGraphNode()
{
}

FText UNoiseGraphNode::GetDescription_Implementation() const
{
	return LOCTEXT("NodeDesc", "Noise Graph Node");
}

#if WITH_EDITOR

FLinearColor UNoiseGraphNode::GetBackgroundColor() const
{
	return BackgroundColor;
}

#if WITH_EDITOR
FText UNoiseGraphNode::GetNodeTitle() const
{
	FString Text = GetName();
	return FText::FromString(Text);
}
#endif

void UNoiseGraphNode::SetNodeTitle(const FText& NewTitle)
{
	NodeTitle = NewTitle;
}

bool UNoiseGraphNode::CanCreateConnection(UNoiseGraphNode* Other, FText& ErrorMessage)
{	
	return true;
}

bool UNoiseGraphNode::CanCreateConnectionTo(UNoiseGraphNode* Other, int32 NumberOfChildrenNodes, FText& ErrorMessage)
{
	if (ChildrenLimitType == ENodeLimit::Limited && NumberOfChildrenNodes >= ChildrenLimit)
	{
		ErrorMessage = FText::FromString("Children limit exceeded");
		return false;
	}

	return CanCreateConnection(Other, ErrorMessage);
}

bool UNoiseGraphNode::CanCreateConnectionFrom(UNoiseGraphNode* Other, int32 NumberOfParentNodes, FText& ErrorMessage)
{
	if (ParentLimitType == ENodeLimit::Limited && NumberOfParentNodes >= ParentLimit)
	{
		ErrorMessage = FText::FromString("Parent limit exceeded");
		return false;
	}

	return true;
}


#endif

void UNoiseGraphNode::RenderPreviewTexture(UTexture2D* Texture2D, int Seed)
{
	UNoiseModule* NoiseModule = GetNoiseModule(0);
	if (NoiseModule == nullptr)
	{
		return;
	}
	
	FTexture2DMipMap* MipMap = &Texture2D->GetPlatformData()->Mips[0];
	FByteBulkData* ImageData = &MipMap->BulkData;
	uint8* RawImageData = (uint8*)ImageData->Lock(LOCK_READ_WRITE);

	float MinHeight = 0;
	float MaxHeight = 0;
	for (int X = 0; X < Texture2D->GetSizeX(); X++)
	{
		for (int Y = 0; Y < Texture2D->GetSizeY(); Y++)
		{
			float Height = static_cast<float>(NoiseModule->GetHeightAt(NoiseModule, X, Y, Seed));
			if (Height < MinHeight) MinHeight = Height;
			if (Height > MaxHeight) MaxHeight = Height;
		}
	}

	if (MinHeight == MaxHeight)
	{
		MinHeight = 0;
		MaxHeight = 1;
	}
	
	FLinearColor Color;
	FColor SRGBColor;
	for (int X = 0; X < Texture2D->GetSizeX(); X++)
	{
		for (int Y = 0; Y < Texture2D->GetSizeY(); Y++)
		{
			float Height = static_cast<float>(NoiseModule->GetHeightAt(NoiseModule, X, Y, Seed));
			// remap to 0 - 1, square for more contrast
			Height = (Height - MinHeight) / (MaxHeight - MinHeight);
			Height = Height * Height;
			Height = FMath::Clamp(Height, 0.0f, 1.0f);
			Color = FLinearColor::LerpUsingHSV(FLinearColor::Black, FLinearColor::White, Height);
			OnRenderPreviewTexturePixel(NoiseModule, X, Y, Seed, Color);
			SRGBColor = Color.ToFColor(true);
			RawImageData[(Y * Texture2D->GetSizeX() + X) * 4 + 0] = SRGBColor.R;
			RawImageData[(Y * Texture2D->GetSizeX() + X) * 4 + 1] = SRGBColor.G;
			RawImageData[(Y * Texture2D->GetSizeX() + X) * 4 + 2] = SRGBColor.B;
			RawImageData[(Y * Texture2D->GetSizeX() + X) * 4 + 3] = SRGBColor.A;
		}
	}
	
	ImageData->Unlock();
	Texture2D->UpdateResource();	
}

bool UNoiseGraphNode::IsLeafNode() const
{
	return ChildrenNodes.Num() == 0;
}

UNoiseGraph* UNoiseGraphNode::GetGraph() const
{
	return Graph;
}

#undef LOCTEXT_NAMESPACE
