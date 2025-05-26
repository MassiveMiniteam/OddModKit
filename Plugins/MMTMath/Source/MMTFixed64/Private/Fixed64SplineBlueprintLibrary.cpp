#include "Fixed64SplineBlueprintLibrary.h"

UFixed64SplineBlueprintLibrary::UFixed64SplineBlueprintLibrary() {
}

void UFixed64SplineBlueprintLibrary::Fixed64Spline_RemovePoint(FFixed64Spline& Spline, int32 Index) {
}

void UFixed64SplineBlueprintLibrary::Fixed64Spline_RemoveAllPoints(FFixed64Spline& Spline) {
}

FFixed64 UFixed64SplineBlueprintLibrary::Fixed64Spline_GetSplineLength(const FFixed64Spline& Spline) {
    return FFixed64{};
}

TArray<FFixed64SplinePoint> UFixed64SplineBlueprintLibrary::Fixed64Spline_GetPoints(const FFixed64Spline& Spline) {
    return TArray<FFixed64SplinePoint>();
}

void UFixed64SplineBlueprintLibrary::Fixed64Spline_AddPoints(FFixed64Spline& Spline, const TArray<FFixed64SplinePoint>& NewPoints) {
}

void UFixed64SplineBlueprintLibrary::Fixed64Spline_AddPoint(FFixed64Spline& Spline, const FFixed64SplinePoint& Point) {
}


