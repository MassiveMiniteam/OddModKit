#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Fixed64.h"
#include "Fixed64Spline.h"
#include "Fixed64SplinePoint.h"
#include "Fixed64SplineBlueprintLibrary.generated.h"

UCLASS(Blueprintable)
class MMTFIXED64_API UFixed64SplineBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFixed64SplineBlueprintLibrary();

    UFUNCTION(BlueprintCallable)
    static void Fixed64Spline_RemovePoint(FFixed64Spline& Spline, int32 Index);
    
    UFUNCTION(BlueprintCallable)
    static void Fixed64Spline_RemoveAllPoints(FFixed64Spline& Spline);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64 Fixed64Spline_GetSplineLength(const FFixed64Spline& Spline);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FFixed64SplinePoint> Fixed64Spline_GetPoints(const FFixed64Spline& Spline);
    
    UFUNCTION(BlueprintCallable)
    static void Fixed64Spline_AddPoints(FFixed64Spline& Spline, const TArray<FFixed64SplinePoint>& NewPoints);
    
    UFUNCTION(BlueprintCallable)
    static void Fixed64Spline_AddPoint(FFixed64Spline& Spline, const FFixed64SplinePoint& Point);
    
};

