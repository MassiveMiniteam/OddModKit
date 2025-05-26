#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "PresentationActorComponent.h"
#include "EInteractionCurrentlyDisabledUITreatment.h"
#include "InteractionPresentationComponentDelegate.h"
#include "InteractionWidgetData.h"
#include "OnLookAtStateChangedDelegate.h"
#include "Templates/SubclassOf.h"
#include "InteractionPresentationComponent.generated.h"

class UHighlightPresentationComponent;
class UInteractionRequirementStrategy;
class UInteractionStrategy;
class UOutlinePresentationComponent;
class UPrimitiveComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UInteractionPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInteractionPresentationComponent OnPrimaryInteractionExecuted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInteractionPresentationComponent OnPrimaryInteractionCalled;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInteractionPresentationComponent OnSecondaryInteractionCalled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPrimaryInteractionEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference PrimaryActionOverlapRequirementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPrimitiveComponent> PrimaryActionRequirement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSecondaryInteractionEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference SecondaryActionOverlapRequirementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPrimitiveComponent> SecondaryActionRequirement;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLookAtStateChanged OnLookAtStateChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UInteractionStrategy>> PrimaryInteractions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInteractionCurrentlyDisabledUITreatment PrimaryCurrentlyDisabledUITreatment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UInteractionStrategy>> SecondaryInteractions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInteractionCurrentlyDisabledUITreatment SecondaryCurrentlyDisabledUITreatment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInteractionWidgetData> InteractionWidgets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UInteractionRequirementStrategy>> AdditionalInteractionRequirementStrategies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCurrentlyBeingLookedAt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCurrentlyBeingHovered;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UOutlinePresentationComponent>> OutlineComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOutlineOnHover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOutlineOnLookedAt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAlsoOutlineChildActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UHighlightPresentationComponent*> HighlightComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHighlightOnHover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHighlightOnLookedAt;
    
public:
    UInteractionPresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetOutlineEnabled(bool bOutlineIsCurrentlyActive, FName SourceTag);
    
    UFUNCTION(BlueprintCallable)
    void SetLookAtState(bool bState);
    
    UFUNCTION(BlueprintCallable)
    void SetHoverState(bool bHoverState);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSecondaryInteractionPossible() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSecondaryInteractionGenerallyPossible() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSecondaryInteractionCurrentlyPossible() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPrimaryInteractionPossible() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPrimaryInteractionGenerallyPossible() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPrimaryInteractionCurrentlyPossible() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerInInteractionRangeForMouse_Secondary() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerInInteractionRangeForMouse_Primary() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnyInteractionPossible() const;
    
    UFUNCTION(BlueprintCallable)
    void CallSecondaryAction();
    
    UFUNCTION(BlueprintCallable)
    void CallPrimaryActionIgnoreCondition();
    
    UFUNCTION(BlueprintCallable)
    void CallPrimaryAction();
    
};

