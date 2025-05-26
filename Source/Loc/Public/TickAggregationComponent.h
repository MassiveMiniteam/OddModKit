#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "PresentationActorComponent.h"
#include "TickAggregationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTickAggregationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FComponentReference> ComponentsToAggregate;
    
public:
    UTickAggregationComponent(const FObjectInitializer& ObjectInitializer);

};

