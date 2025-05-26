#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MMTMathBPLibrary.generated.h"

UCLASS(Blueprintable)
class MMTMATH_API UMMTMathBPLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UMMTMathBPLibrary();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector TwoSectionLerpFVector(FVector Start, FVector Mid, FVector End, float MidValueAlpha, float Alpha);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntPoint FIntVector_CastTo_FIntPoint(const FIntVector& IntVector);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntVector FIntPoint_CastTo_FIntVector(const FIntPoint& IntVector);
    
};

