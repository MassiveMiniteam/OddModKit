#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PresentationActorComponent.h"
#include "WorldMapRevealPresentationComponent.generated.h"

class UPositionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UWorldMapRevealPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionSimulationComponent;
    
public:
    UWorldMapRevealPresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void OnGridPositionChanged(UPositionSimulationComponent* PositionComponent, FIntPoint LastGridPosition);
    
};

