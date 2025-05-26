#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "FoodSeekerComponent.generated.h"

class ASimulationActor;
class UAIPerceptionSimulationComponent;
class UFoodSourceComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UFoodSeekerComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameplayTag> InterestingFoodTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed FoodConsumptionPerSecond;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed MaxFoodFulfillment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAIPerceptionSimulationComponent> PerceptionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed CurrentFoodFulfillment;
    
public:
    UFoodSeekerComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool WantsToEat(const UFoodSourceComponent* FoodSource) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsStuffed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsHungry() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    ASimulationActor* GetClosestDeliciousPerceivedActors() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<ASimulationActor*> GetAllDeliciousPerceivedActors() const;
    
    UFUNCTION(BlueprintCallable)
    void EatUntilStuffed(UFoodSourceComponent* FoodSource);
    
    UFUNCTION(BlueprintCallable)
    void EatOnce(UFoodSourceComponent* FoodSource);
    
};

