#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "SomeSimpleDelegateDelegate.h"
#include "SomeThreeParamDelegateDelegate.h"
#include "ClassDesignTemplate.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MMTSTYLEGUIDE_API UClassDesignTemplate : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FText Name;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSomeSimpleDelegate OnSomethingHappenedToThisClass;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSomeThreeParamDelegate OnSomethingElseHappenedToThisClass;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 SomeValue;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Cooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float LocalDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bTimerStarted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UActorComponent> Inventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UActorComponent> OtherInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference InventoryReference1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference InventoryReference2;
    
public:
    UClassDesignTemplate(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void SomeFunctionBoundToSomeDelegate();
    
public:
    UFUNCTION(BlueprintCallable)
    void SecondaryInteraction(const TArray<float>& PossiblyLargeArray);
    
    UFUNCTION(BlueprintCallable)
    void PrimaryInteraction(float Parameter);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<float> GetterThatDoesALotOfCalculations() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLocalDuration() const;
    
};

