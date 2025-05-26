#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PresentationActorComponent.h"
#include "IndiciesToMaterials.h"
#include "MaterialAdjustPresentationComponent.generated.h"

class UMaterialInstance;
class UMaterialInterface;
class UMeshComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMaterialAdjustPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutomaticallyAddMeshComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DefaultExcludingTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ExcludingTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstance* InteractionStateIndicatorMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DepthStencilValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UMeshComponent*, FIndiciesToMaterials> OriginalMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMeshComponent*> MeshComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInterface*> MaterialStack;
    
public:
    UMaterialAdjustPresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StoreOriginalMaterialsAndMeshComponents();
    
    UFUNCTION(BlueprintCallable)
    void SetVectorParameterOnAllMaterials(FName ParameterName, FVector Value, bool bIncludeChildActors);
    
    UFUNCTION(BlueprintCallable)
    void SetScalarParameterOnAllMaterials(FName ParameterName, float Value, bool bIncludeChildActors);
    
    UFUNCTION(BlueprintCallable)
    void RemoveMaterial(UMaterialInterface* Material);
    
    UFUNCTION(BlueprintCallable)
    void EnableInteractionStateVisualization(bool bInteractionState);
    
    UFUNCTION(BlueprintCallable)
    void AddMaterial(UMaterialInterface* Material);
    
};

