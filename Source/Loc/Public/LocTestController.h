#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LocTestController.generated.h"

class ULocGauntletTest;

UCLASS(Blueprintable)
class LOC_API ULocTestController : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ULocGauntletTest*> Tests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasStarted;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LocTest;
    
    ULocTestController();

    UFUNCTION(BlueprintCallable)
    void StartTesting();
    
};

