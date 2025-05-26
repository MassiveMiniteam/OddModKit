#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BiomeGenerator.h"
#include "InstancedMeshBiomeGenerator.generated.h"

class AActor;
class UBiomeCellConfig;
class UInstancedStaticMeshComponent;
class UMaterialInstance;

UCLASS(Blueprintable)
class LOC_API UInstancedMeshBiomeGenerator : public UBiomeGenerator {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstance* Material;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> MeshActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Offset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeightOverwrite;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinDistanceToEdge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInvert;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* InstancedStaticMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoGenerateToAnotherBiome;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBiomeCellConfig*> CellsToGenerateWallsTo;
    
public:
    UInstancedMeshBiomeGenerator();

};

