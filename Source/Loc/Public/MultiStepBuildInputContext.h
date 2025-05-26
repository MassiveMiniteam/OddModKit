#pragma once
#include "CoreMinimal.h"
#include "InputContext.h"
#include "Templates/SubclassOf.h"
#include "MultiStepBuildInputContext.generated.h"

class AGridObject;
class UConstructableConfig;
class UInputContextBuild;

UCLASS(Blueprintable)
class LOC_API UMultiStepBuildInputContext : public UInputContext {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UConstructableConfig*> GridObjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UInputContextBuild> BuildInputContextClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PlaceIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AGridObject*> PlacedGridObjects;
    
public:
    UMultiStepBuildInputContext();

protected:
    UFUNCTION(BlueprintCallable)
    void OnGridObjectPlaced(UInputContextBuild* InputContext, AGridObject* GridObject);
    
    UFUNCTION(BlueprintCallable)
    void OnBuildInputContextCancelled(UInputContextBuild* InputContext);
    
    UFUNCTION(BlueprintCallable)
    void Cancel();
    
};

