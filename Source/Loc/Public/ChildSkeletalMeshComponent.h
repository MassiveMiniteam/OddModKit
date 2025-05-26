#pragma once
#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "ChildSkeletalMeshComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UChildSkeletalMeshComponent : public USkeletalMeshComponent {
    GENERATED_BODY()
public:
    UChildSkeletalMeshComponent(const FObjectInitializer& ObjectInitializer);

};

