#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "BalloonCarryPresentationComponent.generated.h"

class UBalloonCarrySimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UBalloonCarryPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBalloonCarrySimulationComponent* BalloonCarrySimulationComponent;
    
public:
    UBalloonCarryPresentationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnBalloonRemoved_Event();
    
    UFUNCTION(BlueprintCallable)
    void OnBalloonReleased(UBalloonCarrySimulationComponent* Component);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnBalloonAttached_Event();
    
    UFUNCTION(BlueprintCallable)
    void OnBalloonAttached(UBalloonCarrySimulationComponent* Component);
    
};

