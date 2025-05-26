#pragma once
#include "CoreMinimal.h"
#include "BuildToolAssignable.h"
#include "ConstructablePriceOverride.h"
#include "EBuildCategory.h"
#include "ECopyToolPasteOrder.h"
#include "ItemStack.h"
#include "Templates/SubclassOf.h"
#include "UnlockableDataAsset.h"
#include "ConstructableConfig.generated.h"

class ASimulationActor;
class UBuildToolPresetExecutionStrategy;
class UGlossaryGameplayData;
class UInputContext;
class UObject;
class UTexture2D;

UCLASS(Blueprintable)
class LOC_API UConstructableConfig : public UUnlockableDataAsset, public IBuildToolAssignable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FText DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FText HoverInformation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> ConstructableTypeIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ASimulationActor> SimulationActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UInputContext> InputContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ASimulationActor> FollowUpConstructableActorClass;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemStack> Price;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConstructablePriceOverride> PriceOverrides;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanBeRelocated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanBeDeconstructed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanBeCopied;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBuildCategory Category;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CategoryUIOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EditPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideBuildInitialRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OverrideBuildInitialRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHiddenInBuildMenu;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGlossaryGameplayData* GlossaryGameplayUnlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECopyToolPasteOrder CopyToolPasteOrder;
    
    UConstructableConfig();

    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool IsAssigningToPresetBarPossible(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    TArray<FItemStack> GetPrice(const UObject* WorldContext) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSoftObjectPtr<UTexture2D> GetBuildToolAssignableIcon();
    

    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void HandleExecutionStrategy(UObject* WorldContext) override PURE_VIRTUAL(HandleExecutionStrategy,);
    
    UFUNCTION(BlueprintCallable)
    TSubclassOf<UBuildToolPresetExecutionStrategy> GetBuildToolExecutionStrategy() override PURE_VIRTUAL(GetBuildToolExecutionStrategy, return NULL;);
    
};

