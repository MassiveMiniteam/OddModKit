#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "Fixed64.h"
#include "Fixed64Vector.h"
#include "PhysicsBodyPresentationComponent.generated.h"

class UMMTPhysicsBodyComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPhysicsBodyPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UMMTPhysicsBodyComponent> PhysicsBodySimulation;
    
public:
    UPhysicsBodyPresentationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnSimulationLocationUpdated(UMMTPhysicsBodyComponent* PhysicsBodyComponent, FFixed64Vector Location, FFixed64 DeltaTime);
    
};

