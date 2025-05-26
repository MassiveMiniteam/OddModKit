#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PresentationActor.h"
#include "FlockEntity.h"
#include "FlockModifier.h"
#include "Flock.generated.h"

class UInstancedStaticMeshComponent;

UCLASS(Blueprintable)
class AFlock : public APresentationActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumEntities;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval SpawnHeight;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval SpawnRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerceptionRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AvoidanceRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AlignmentWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CohesionWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SeparationWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GravitationImpact;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CloseTooGroundThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpperLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* InstancedStaticMeshComponent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFlockEntity> Entities;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFlockModifier> Modifiers;
    
public:
    AFlock(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void InitiateLanding();
    
    UFUNCTION(BlueprintCallable)
    void InitiateFlying();
    
};

