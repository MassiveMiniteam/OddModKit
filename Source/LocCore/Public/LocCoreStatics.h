#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Fixed64.h"
#include "Fixed.h"
#include "LocPlayerId.h"
#include "LocRandom.h"
#include "LocSaveGameLoadOperation.h"
#include "LocCoreStatics.generated.h"

class AActor;
class ALocCoreGameState;
class ALocCorePlayerController;
class ALocPlayerState;
class IPresentationObjectInterface;
class UPresentationObjectInterface;
class UActorComponent;
class UObject;

UCLASS(Blueprintable)
class LOCCORE_API ULocCoreStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    ULocCoreStatics();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntVector Subtract_IntVectorIntVector(FIntVector A, FIntVector B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed Subtract_FixedFixed(FFixed A, FFixed B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed Sqrt_Fixed(FFixed A);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 Size_IntVector(const FIntVector& A);
    
    UFUNCTION(BlueprintCallable)
    static FFixed sin(FFixed Fixed);
    
    UFUNCTION(BlueprintCallable)
    static void SetCurrentCulture(const FString& Culture);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed Round_Fixed(FFixed A);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntVector Normalize_IntVector(FIntVector A);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntVector Multiply_IntVectorFixed(FIntVector A, FFixed B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed Multiply_FixedInteger(FFixed A, int32 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed Multiply_FixedFixed(FFixed A, FFixed B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed Min_Fixed(FFixed A, FFixed B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed Max_Fixed(FFixed A, FFixed B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed MakeFixedInt(int32 X);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed MakeFixedFromFixed64(FFixed64 Fixed64);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed MakeFixedDefault(FFixed Fixed);
    
    UFUNCTION(BlueprintCallable)
    static void LocRandom_SetSeed(UPARAM(Ref) FLocRandom& InRandom, int32 Seed);
    
    UFUNCTION(BlueprintCallable)
    static int32 LocRandom_GetRandomIntegerInRange(UPARAM(Ref) FLocRandom& InRandom, int32 min, int32 max);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool LessEqual_FixedInt(FFixed A, int32 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool LessEqual_FixedFixed(FFixed A, FFixed B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool Less_FixedInt(FFixed A, int32 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool Less_FixedFixed(FFixed A, FFixed B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsTextLocalized(FText Text);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static bool IsLocServer(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static bool IsLocClient(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GreaterEqual_FixedInt(FFixed A, int32 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GreaterEqual_FixedFixed(FFixed A, FFixed B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool Greater_FixedInt(FFixed A, int32 B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool Greater_FixedFixed(FFixed A, FFixed B);
    
    UFUNCTION(BlueprintCallable)
    static FLocSaveGameLoadOperation GetSaveGameLoadOperation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed GetRotationFromVector(FIntVector Vector);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static ALocPlayerState* GetLocalPlayerState(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static FLocPlayerId GetLocalPlayerId(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static ALocCorePlayerController* GetLocalPlayerController(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static FLocPlayerId GetLocalLocPlayerIdFromOnlineIdentity(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetIntValue(const FFixed& Fixed);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static ALocCoreGameState* GetGameState(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetFloatValue(const FFixed& Fixed);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetCurrentCulture();
    
    UFUNCTION(BlueprintCallable)
    static bool GetClassBlueprintComponents(UClass* ObjectClass, TArray<UActorComponent*>& OutComponents);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed GetAngleBetweenVectorsInDegree(const FIntVector& VectorA, const FIntVector& VectorB);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static AActor* GetActor(TScriptInterface<IPresentationObjectInterface> PresentationObjectInterface);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed Floor_Fixed(FFixed A);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed FloatToFixed_NonDeterministic(float X);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString FixedToString(const FFixed& Fixed);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed FindDeltaAngleInDegrees(FFixed A, FFixed B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed FindDeltaAngleAbsInDegrees(FFixed A, FFixed B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool Equal_FixedFixed(FFixed A, FFixed B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float EaseInOutCubic(float Alpha);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed Divide_FixedFixed(FFixed A, FFixed B);
    
    UFUNCTION(BlueprintCallable)
    static void DebugToggleLocalization();
    
    UFUNCTION(BlueprintCallable)
    static void DebugToggleDebugCulture();
    
    UFUNCTION(BlueprintCallable)
    static FFixed cos(FFixed Fixed);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool CompareLocPlayerId(FLocPlayerId Id1, FLocPlayerId Id2);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed Clamp_Fixed(FFixed A, FFixed min, FFixed max);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed Ceil_Fixed(FFixed A);
    
    UFUNCTION(BlueprintCallable)
    static FFixed asin(FFixed Fixed);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntVector Add_IntVectorIntVector(FIntVector A, FIntVector B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed Add_FixedFixed(FFixed A, FFixed B);
    
    UFUNCTION(BlueprintCallable)
    static FFixed acos(FFixed Fixed);
    
};

