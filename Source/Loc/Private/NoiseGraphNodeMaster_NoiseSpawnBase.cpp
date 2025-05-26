#include "NoiseGraphNodeMaster_NoiseSpawnBase.h"

void UNoiseGraphNodeMaster_NoiseSpawnBase::OnRenderPreviewTexturePixel(UNoiseModule* Noise, int X, int Y, int InSeed, FLinearColor& Color)
{
	FFixed64 Height = Noise->GetHeightAt(Noise, X, Y, InSeed);
	if (Height >= SpawnBetweenHeightMin && Height <= SpawnBetweenHeightMax)
	{
		Color = FLinearColor::Red;
	}
}
