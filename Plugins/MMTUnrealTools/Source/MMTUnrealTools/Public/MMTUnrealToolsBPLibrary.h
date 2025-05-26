#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Layout/Geometry.h"
#include "MMTUnrealToolsBPLibrary.generated.h"

class APlayerController;
class UObject;
class UPackage;
class UUserWidget;

UCLASS(Blueprintable)
class MMTUNREALTOOLS_API UMMTUnrealToolsBPLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UMMTUnrealToolsBPLibrary();

    UFUNCTION(BlueprintCallable)
    static void VisualLogPosition(UObject* Owner, FVector Position, float SphereRadius, FColor Color, const FString& Text);
    
    UFUNCTION(BlueprintCallable)
    static FVector2D SetWidgetScreenPositionFromWorldPosition(UUserWidget* Widget, FVector WorldLocation, FVector2D Alignment, bool ClampToScreen);
    
    UFUNCTION(BlueprintCallable)
    static void SavePackage(const UObject* CreatedAsset, UPackage* PackageNew);
    
    UFUNCTION(BlueprintCallable)
    static void ReSavePackage(const UObject* CreatedAsset);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector2D ProjectWorldToScreenEvenIfBehindCamera(APlayerController* Player, const FVector& WorldPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FVector2D GetNormalizedViewportPositionInGeometry(UObject* WorldContextObject, FGeometry Geometry, FVector2D ViewportPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FVector2D GetNormalizedMousePositionInGeometry(UObject* WorldContextObject, FGeometry Geometry);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FVector2D GetMousePositionInGeometry(UObject* WorldContextObject, FGeometry Geometry);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool FindGameIniEntry(const FString& Section, const FString& Key, FString& FoundValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 ConstructIntegerBitwise(const TArray<bool>& BitConditions);
    
};

