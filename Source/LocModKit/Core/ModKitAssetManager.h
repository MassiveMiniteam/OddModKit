#pragma once
#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "ModKitAssetManager.generated.h"

UCLASS(Blueprintable)
class LOCMODKIT_API UModKitAssetManager : public UAssetManager {
    GENERATED_BODY()
public:
    UModKitAssetManager();

#if WITH_EDITOR
    virtual FName GetUniqueAssetRegistryName(int32 InChunkIndex) const override;
#endif

};

