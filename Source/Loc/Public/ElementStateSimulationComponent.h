#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "ElementState.h"
#include "OnElementStateChangedDelegateDelegate.h"
#include "SimulationTimerComponent.h"
#include "Templates/SubclassOf.h"
#include "ElementStateSimulationComponent.generated.h"

class UElementDataAsset;
class UElementMaterialDataAsset;
class UGE_ApplyNaturalElement;
class UGameplayEffect;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UElementStateSimulationComponent : public USimulationTimerComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnElementStateChangedDelegate OnElementStateChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FElementState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UElementMaterialDataAsset* ElementMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatsComponent* Stats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UGameplayEffect* GameplayEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UGE_ApplyNaturalElement* ApplyNaturalElementEffect;
    
public:
    UElementStateSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetElementState(FElementState NewState);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAtAtMaxStacksOfElement(const UElementDataAsset* Element) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAtAtMaxStacks() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UElementDataAsset* GetNaturalElement() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FElementState GetElementState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UElementMaterialDataAsset* GetElementMaterial() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UGameplayEffect> GetElementalGameplayEffect(const UElementDataAsset* ElementDataAsset) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UGameplayEffect* GetCurrentGameplayEffect() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentElementStackAmount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCurrentElementRelativeStackAmount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentElementMaxStacks() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CurrentElementIsNaturalElement() const;
    
    UFUNCTION(BlueprintCallable)
    void ApplyElement(FElementState Element);
    
};

