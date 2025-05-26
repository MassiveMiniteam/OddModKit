#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "LocTestCsv.generated.h"

UCLASS(Blueprintable)
class LOC_API ULocTestCsv : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Header;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector2D> Data;
    
    ULocTestCsv();

    UFUNCTION(BlueprintCallable)
    void SaveToFile(const FString& Filename);
    
    UFUNCTION(BlueprintCallable)
    void AddData(float X, float Y);
    
};

