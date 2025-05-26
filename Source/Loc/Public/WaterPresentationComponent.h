#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "WaterPresentationComponent.generated.h"

class UProceduralMeshComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UWaterPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UProceduralMeshComponent> ProceduralMeshComponent;
    
public:
    UWaterPresentationComponent(const FObjectInitializer& ObjectInitializer);

};

