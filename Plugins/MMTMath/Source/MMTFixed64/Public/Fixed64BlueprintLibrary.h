#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Fixed64.h"
#include "Fixed64Vector.h"
#include "Fixed64BlueprintLibrary.generated.h"

UCLASS(Blueprintable)
class MMTFIXED64_API UFixed64BlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFixed64BlueprintLibrary();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64 TwoSectionLerp_Fixed64(FFixed64 Start, FFixed64 Mid, FFixed64 End, FFixed64 MidValueAlpha, FFixed64 Alpha);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64Vector Subtract_FixedVectorFixedVector(const FFixed64Vector& A, const FFixed64Vector& B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64 Subtract_FixedFixed(FFixed64 A, FFixed64 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64 Sqrt_Fixed(FFixed64 A);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool NotEqual_FixedFixed(FFixed64 A, FFixed64 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64Vector Multiply_FixedVectorFixed(const FFixed64Vector& A, FFixed64 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64 Multiply_FixedInteger(FFixed64 A, int32 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64 Multiply_FixedFixed(FFixed64 A, FFixed64 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64 Min_Fixed(FFixed64 A, FFixed64 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64 Max_Fixed(FFixed64 A, FFixed64 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64 MakeFixedFromInt(int32 X);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64 MakeFixed64(FFixed64 X);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool LessEqual_FixedInt(FFixed64 A, int32 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool LessEqual_FixedFixed(FFixed64 A, FFixed64 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool Less_FixedInt(FFixed64 A, int32 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool Less_FixedFixed(FFixed64 A, FFixed64 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64 Lerp_Fixed64(FFixed64 A, FFixed64 B, FFixed64 Alpha);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GreaterEqual_FixedInt(FFixed64 A, int32 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GreaterEqual_FixedFixed(FFixed64 A, FFixed64 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool Greater_FixedInt(FFixed64 A, int32 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool Greater_FixedFixed(FFixed64 A, FFixed64 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetIntValue(FFixed64 A);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetFloatValue(FFixed64 A);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector Fixed64Vector_CastTo_FVector(const FFixed64Vector& Fixed64Vector);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntVector Fixed64Vector_CastTo_FIntVector(const FFixed64Vector& Fixed64Vector);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64Vector FIntVector_CastTo_Fixed64Vector(const FIntVector& IntVector);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool Equal_FixedFixed(FFixed64 A, FFixed64 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64Vector Divide_FixedVectorFixed(const FFixed64Vector& A, FFixed64 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64 Divide_FixedFixed(FFixed64 A, FFixed64 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64 Clamp_Fixed64(FFixed64 Value, FFixed64 Min, FFixed64 Max);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64 AngleInDegree2D_FixedVector(const FFixed64Vector& A, const FFixed64Vector& B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64Vector Add_FixedVectorFixedVector(const FFixed64Vector& A, const FFixed64Vector& B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64 Add_FixedFixed(FFixed64 A, FFixed64 B);
    
};

