#pragma once
#include "CoreMinimal.h"
#include "ItemDecayComponent.h"
#include "TokenItemCommitter.generated.h"

class UDifficultySettingsSubsystem;
class UItemConfig;
class UTokenGeneratorSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTokenItemCommitter : public UItemDecayComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTokenGeneratorSimulationComponent* TokenGenerator;
    
public:
    UTokenItemCommitter(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetTokenGenerator(UTokenGeneratorSimulationComponent* GeneratorSimulationComponent);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnItemDecayedFunction(UItemDecayComponent* Component, UItemConfig* ItemConfig);
    
    UFUNCTION(BlueprintCallable)
    void OnDifficultySettingsChanged(UDifficultySettingsSubsystem* Subsystem);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTokenGeneratorSimulationComponent* GetTokenGenerator() const;
    
};

