#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Mappings.generated.h"

UCLASS(Blueprintable)
class UMappings : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UMappings();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float SmoothStep5(float X);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float SmoothStep3(float X);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float SmoothStart4(float X);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float SmoothStart3(float X);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float SmoothStart2(float X);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float SmoothEnd4(float X);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float SmoothEnd3(float X);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float SmoothEnd2(float X);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float Bounce(float X);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float BellCurve(float X, float BellCenter, float BellHalfWidth, float Amplitude);
    
};

