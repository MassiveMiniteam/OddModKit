#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SerializedSimulationObject.h"
#include "BiomeInstanceDelegateDelegate.h"
#include "BiomeInstance.generated.h"

class UBiomeCellInstance;
class UBiomeConfig;
class UWorldGenerator;

UCLASS(Blueprintable)
class UBiomeInstance : public USerializedSimulationObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UBiomeConfig* BiomeConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorldGenerator* WorldGenerator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 BiomeSeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UBiomeCellInstance*> Cells;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBiomeInstanceDelegate OnBiomeInstanceGotRenamed;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Name;
    
public:
    UBiomeInstance();

    UFUNCTION(BlueprintCallable)
    void SetBiomeInstanceName(const FText& NewName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetCenterAsGridPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetBiomeInstanceName() const;
    
};

