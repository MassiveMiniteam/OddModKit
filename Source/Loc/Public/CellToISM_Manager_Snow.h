#pragma once
#include "CoreMinimal.h"
#include "CellToISM_Manager.h"
#include "CellToISM_Manager_Snow.generated.h"

class UGroundMeshMappingAsset;

UCLASS(Blueprintable)
class LOC_API ACellToISM_Manager_Snow : public ACellToISM_Manager {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGroundMeshMappingAsset*> GroundMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<uint8, UGroundMeshMappingAsset*> AdditionalGroundMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<uint8, UGroundMeshMappingAsset*> GroundMeshesMap;
    
public:
    ACellToISM_Manager_Snow(const FObjectInitializer& ObjectInitializer);

};

