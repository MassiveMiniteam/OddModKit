#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "WorldMapDataComponent.generated.h"

class AGrid;
class UDynamicTexture;
class UTexture2D;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UWorldMapDataComponent : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDynamicTexture* MapTexture_Terrain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDynamicTexture* MapTexture_TerrainIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDynamicTexture* MapTexture_Buildings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDynamicTexture* MapTexture_Paths;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDynamicTexture* MapTexture_Paint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<bool> FogOfWarMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<bool> LoadedMapMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGrid* Grid;
    
public:
    UWorldMapDataComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateAround(const FIntPoint& GridPosition, int32 OverrideRadius);
    
private:
    UFUNCTION(BlueprintCallable)
    void RevealFogOfWarMap();
    
public:
    UFUNCTION(BlueprintCallable)
    void QueueMapUpdateForNextTick(const TArray<FIntPoint>& Points);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetMapTextureSize();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture2D* GetMapTexture_TerrainIDs() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture2D* GetMapTexture_TerrainColors() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture2D* GetMapTexture_Paths() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture2D* GetMapTexture_Paint() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture2D* GetMapTexture_Buildings() const;
    
};

