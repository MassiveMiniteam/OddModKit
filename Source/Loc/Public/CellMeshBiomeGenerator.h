#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BiomeGenerator.h"
#include "CellMeshBiomeGenerator.generated.h"

class AActor;
class UMaterialInstance;

UCLASS(Blueprintable)
class LOC_API UCellMeshBiomeGenerator : public UBiomeGenerator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstance* Material;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> MeshActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Offset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasGenerated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Scale;
    
public:
    UCellMeshBiomeGenerator();

};

