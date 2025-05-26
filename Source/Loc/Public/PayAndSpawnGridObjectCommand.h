#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "SimulationCommand.h"
#include "GridObjectSpawnedDelegateDelegate.h"
#include "ItemStack.h"
#include "Templates/SubclassOf.h"
#include "PayAndSpawnGridObjectCommand.generated.h"

class AActor;
class AGridObject;
class ASimulationActor;
class ASimulationPlayer;
class UConstructableConfig;
class UInventoryComponent;
class URecipeConfig;

UCLASS(Blueprintable)
class LOC_API UPayAndSpawnGridObjectCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGridObjectSpawnedDelegate OnGridObjectPlaced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UInventoryComponent* PlayerInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FItemStack> ItemStacks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASimulationActor> SimulationActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntVector CenterPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Rotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UConstructableConfig* ConstructableConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    URecipeConfig* RecipeConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AGridObject* IgnoredGridObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AGridObject* PreviousBuiltGridObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* ExecutingSimulationPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FFixed> customData;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* PredictedGridObject;
    
public:
    UPayAndSpawnGridObjectCommand();

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPostSpawn(AGridObject* SpawnedGridObject);
    
};

