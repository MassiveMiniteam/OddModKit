#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ConstructionsCopyData.h"
#include "CopyToolMemoryPresentationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UCopyToolMemoryPresentationComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConstructionsCopyData ConstructionsCopyData;
    
public:
    UCopyToolMemoryPresentationComponent(const FObjectInitializer& ObjectInitializer);

};

