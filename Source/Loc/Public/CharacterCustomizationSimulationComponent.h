#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "CharacterCustomizationSettings.h"
#include "CharacterCustomizationSettingsEventDelegate.h"
#include "CharacterCustomizationSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UCharacterCustomizationSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterCustomizationSettingsEvent OnCharacterCustomizationChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FCharacterCustomizationSettings CharacterSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bUseDefault;
    
public:
    UCharacterCustomizationSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateCharacterSettings(FCharacterCustomizationSettings InCharacterCustomizationSettings);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FCharacterCustomizationSettings GenerateDefaultSettings();
    
};

