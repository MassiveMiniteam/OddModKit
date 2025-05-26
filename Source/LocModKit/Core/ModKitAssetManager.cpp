#include "ModKitAssetManager.h"

#if WITH_EDITOR
#include "ModKitEditorSettings.h"
#endif

UModKitAssetManager::UModKitAssetManager() {
}

#if WITH_EDITOR
FName UModKitAssetManager::GetUniqueAssetRegistryName(int32 InChunkIndex) const
{
	if (InChunkIndex != 0)
	{
		const TArray<FModKitModDefinition> ModKitChunkMappings = GetDefault<UModKitEditorSettings>()->ModDefinitions;
		for (const FModKitModDefinition& Mapping : ModKitChunkMappings)
		{
			if (Mapping.ChunkId == InChunkIndex)
			{
				return FName(Mapping.ModId);
			}
		}

		UE_LOG(LogTemp, Warning, TEXT("Failed to find modid in developer settings, cannot choose asset registry unique name for chunk %d"), InChunkIndex);
	}
	return Super::GetUniqueAssetRegistryName(InChunkIndex);
}
#endif

