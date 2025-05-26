#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "ERecipeOutputBehaviour.h"
#include "ItemStack.h"
#include "UnlockableDataAsset.h"
#include "RecipeConfig.generated.h"

class ASimulationActor;
class UTemperatureEfficiencyConfig;
class UTexture2D;

UCLASS(Blueprintable)
class LOC_API URecipeConfig : public UUnlockableDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText RecipeName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText RecipeDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> OverrideTechTreeIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemStack> Inputs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemStack> Outputs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> WeightsForWeightedRandom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNeedsFuel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bConsumesItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Duration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTemperatureEfficiencyConfig* TemperatureEfficiencyOverwrite;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERecipeOutputBehaviour OutputBehaviour;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ASimulationActor>> InjectIntoRecipeProcessors;
    
    URecipeConfig();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool NeedsFuel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumberOfProducedItemTypes() const;
    
};

