#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "SkeletalMeshOptimizationPresentationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API USkeletalMeshOptimizationPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SetOptimizationAfterSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentDuration;
    
    USkeletalMeshOptimizationPresentationComponent(const FObjectInitializer& ObjectInitializer);

};

