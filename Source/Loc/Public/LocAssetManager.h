#pragma once
#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "LocAssetManager.generated.h"

UCLASS(Blueprintable)
class LOC_API ULocAssetManager : public UAssetManager {
    GENERATED_BODY()
public:
    ULocAssetManager();

};

