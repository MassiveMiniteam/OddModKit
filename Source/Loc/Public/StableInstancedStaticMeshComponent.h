#pragma once
#include "CoreMinimal.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "StableInstancedStaticMeshComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UStableInstancedStaticMeshComponent : public UInstancedStaticMeshComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> FreeInstances;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCreatePhysicsState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnablePooling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> PositionIndexMapping;
    
    UStableInstancedStaticMeshComponent(const FObjectInitializer& ObjectInitializer);

};

