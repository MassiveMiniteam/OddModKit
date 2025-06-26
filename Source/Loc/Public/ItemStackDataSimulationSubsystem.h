#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "LocSimulationSubsystem.h"
#include "ItemStack.h"
#include "ItemStackDataSimulationSubsystem.generated.h"

class UItemStackData;

UCLASS(Blueprintable)
class LOC_API UItemStackDataSimulationSubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UItemStackData*> ItemStackDataArray;
    
public:
    UItemStackDataSimulationSubsystem();

    UFUNCTION(BlueprintCallable)
    void SetGameplayTagDataOnItemStack(UPARAM(Ref) FItemStack& Stack, const FGameplayTagContainer& Tags);
    
};

