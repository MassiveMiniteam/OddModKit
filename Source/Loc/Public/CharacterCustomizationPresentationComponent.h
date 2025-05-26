#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "CharacterCustomizationSettings.h"
#include "CharacterCustomizationPresentationComponent.generated.h"

class UCharacterCustomizationSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UCharacterCustomizationPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCharacterCustomizationSimulationComponent* CharacterCustomizationSimulationComponent;
    
public:
    UCharacterCustomizationPresentationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnCharacterCustomizationChangedEvent(UCharacterCustomizationSimulationComponent* Component, FCharacterCustomizationSettings NewCharacterCustomizationSettings);
    
};

