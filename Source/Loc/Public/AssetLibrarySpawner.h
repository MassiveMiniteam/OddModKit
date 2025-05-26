#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "AssetLibrarySpawner.generated.h"

UCLASS(Blueprintable)
class LOC_API AAssetLibrarySpawner : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Spacing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> AssetPaths;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> BlacklistedActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector position;
    
    AAssetLibrarySpawner(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SpawnItems();
    
    UFUNCTION(BlueprintCallable)
    void SpawnAssets();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpawnedAsset(AActor* Asset);
    
};

