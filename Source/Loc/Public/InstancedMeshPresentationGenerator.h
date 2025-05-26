#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "BiomePresentationGenerator.h"
#include "InstancedMeshPresentationGenerator.generated.h"

class AActor;
class UBiomeCellConfig;
class UInstancedStaticMeshComponent;

UCLASS(Blueprintable)
class LOC_API UInstancedMeshPresentationGenerator : public UBiomePresentationGenerator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoGenerateToAnotherBiome;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBiomeCellConfig*> CellsToGenerateWallsTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer CellTagsToGenerateTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Offset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeightOverwrite;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> MeshActor;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* InstancedStaticMeshComponent;
    
public:
    UInstancedMeshPresentationGenerator();

};

