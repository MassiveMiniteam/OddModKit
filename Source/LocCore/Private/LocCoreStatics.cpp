#include "LocCoreStatics.h"

ULocCoreStatics::ULocCoreStatics() {
}

FIntVector ULocCoreStatics::Subtract_IntVectorIntVector(FIntVector A, FIntVector B) {
    return FIntVector{};
}

FFixed ULocCoreStatics::Subtract_FixedFixed(FFixed A, FFixed B) {
    return FFixed{};
}

FFixed ULocCoreStatics::Sqrt_Fixed(FFixed A) {
    return FFixed{};
}

int32 ULocCoreStatics::Size_IntVector(const FIntVector& A) {
    return 0;
}

FFixed ULocCoreStatics::sin(FFixed Fixed) {
    return FFixed{};
}

void ULocCoreStatics::SetCurrentCulture(const FString& Culture) {
}

FFixed ULocCoreStatics::Round_Fixed(FFixed A) {
    return FFixed{};
}

FIntVector ULocCoreStatics::Normalize_IntVector(FIntVector A) {
    return FIntVector{};
}

FIntVector ULocCoreStatics::Multiply_IntVectorFixed(FIntVector A, FFixed B) {
    return FIntVector{};
}

FFixed ULocCoreStatics::Multiply_FixedInteger(FFixed A, int32 B) {
    return FFixed{};
}

FFixed ULocCoreStatics::Multiply_FixedFixed(FFixed A, FFixed B) {
    return FFixed{};
}

FFixed ULocCoreStatics::Min_Fixed(FFixed A, FFixed B) {
    return FFixed{};
}

FFixed ULocCoreStatics::Max_Fixed(FFixed A, FFixed B) {
    return FFixed{};
}

FFixed ULocCoreStatics::MakeFixedInt(int32 X) {
    return FFixed{};
}

FFixed ULocCoreStatics::MakeFixedFromFixed64(FFixed64 Fixed64) {
    return FFixed{};
}

FFixed ULocCoreStatics::MakeFixedDefault(FFixed Fixed) {
    return FFixed{};
}

void ULocCoreStatics::LocRandom_SetSeed(FLocRandom& InRandom, int32 Seed) {
}

int32 ULocCoreStatics::LocRandom_GetRandomIntegerInRange(FLocRandom& InRandom, int32 min, int32 max) {
    return 0;
}

bool ULocCoreStatics::LessEqual_FixedInt(FFixed A, int32 B) {
    return false;
}

bool ULocCoreStatics::LessEqual_FixedFixed(FFixed A, FFixed B) {
    return false;
}

bool ULocCoreStatics::Less_FixedInt(FFixed A, int32 B) {
    return false;
}

bool ULocCoreStatics::Less_FixedFixed(FFixed A, FFixed B) {
    return false;
}

bool ULocCoreStatics::IsTextLocalized(FText Text) {
    return false;
}

bool ULocCoreStatics::IsLocServer(const UObject* WorldContext) {
    return false;
}

bool ULocCoreStatics::IsLocClient(const UObject* WorldContext) {
    return false;
}

bool ULocCoreStatics::GreaterEqual_FixedInt(FFixed A, int32 B) {
    return false;
}

bool ULocCoreStatics::GreaterEqual_FixedFixed(FFixed A, FFixed B) {
    return false;
}

bool ULocCoreStatics::Greater_FixedInt(FFixed A, int32 B) {
    return false;
}

bool ULocCoreStatics::Greater_FixedFixed(FFixed A, FFixed B) {
    return false;
}

FLocSaveGameLoadOperation ULocCoreStatics::GetSaveGameLoadOperation() {
    return FLocSaveGameLoadOperation{};
}

FFixed ULocCoreStatics::GetRotationFromVector(FIntVector Vector) {
    return FFixed{};
}

ALocPlayerState* ULocCoreStatics::GetLocalPlayerState(const UObject* WorldContext) {
    return NULL;
}

FLocPlayerId ULocCoreStatics::GetLocalPlayerId(const UObject* WorldContext) {
    return FLocPlayerId{};
}

ALocCorePlayerController* ULocCoreStatics::GetLocalPlayerController(const UObject* WorldContext) {
    return NULL;
}

FLocPlayerId ULocCoreStatics::GetLocalLocPlayerIdFromOnlineIdentity(const UObject* WorldContext) {
    return FLocPlayerId{};
}

int32 ULocCoreStatics::GetIntValue(const FFixed& Fixed) {
    return 0;
}

ALocCoreGameState* ULocCoreStatics::GetGameState(const UObject* WorldContext) {
    return NULL;
}

float ULocCoreStatics::GetFloatValue(const FFixed& Fixed) {
    return 0.0f;
}

FString ULocCoreStatics::GetCurrentCulture() {
    return TEXT("");
}

bool ULocCoreStatics::GetClassBlueprintComponents(UClass* ObjectClass, TArray<UActorComponent*>& OutComponents) {
    return false;
}

FFixed ULocCoreStatics::GetAngleBetweenVectorsInDegree(const FIntVector& VectorA, const FIntVector& VectorB) {
    return FFixed{};
}

AActor* ULocCoreStatics::GetActor(TScriptInterface<IPresentationObjectInterface> PresentationObjectInterface) {
    return NULL;
}

FFixed ULocCoreStatics::Floor_Fixed(FFixed A) {
    return FFixed{};
}

FFixed ULocCoreStatics::FloatToFixed_NonDeterministic(float X) {
    return FFixed{};
}

FString ULocCoreStatics::FixedToString(const FFixed& Fixed) {
    return TEXT("");
}

FFixed ULocCoreStatics::FindDeltaAngleInDegrees(FFixed A, FFixed B) {
    return FFixed{};
}

FFixed ULocCoreStatics::FindDeltaAngleAbsInDegrees(FFixed A, FFixed B) {
    return FFixed{};
}

bool ULocCoreStatics::Equal_FixedFixed(FFixed A, FFixed B) {
    return false;
}

float ULocCoreStatics::EaseInOutCubic(float Alpha) {
    return 0.0f;
}

FFixed ULocCoreStatics::Divide_FixedFixed(FFixed A, FFixed B) {
    return FFixed{};
}

void ULocCoreStatics::DebugToggleLocalization() {
}

void ULocCoreStatics::DebugToggleDebugCulture() {
}

FFixed ULocCoreStatics::cos(FFixed Fixed) {
    return FFixed{};
}

bool ULocCoreStatics::CompareLocPlayerId(FLocPlayerId Id1, FLocPlayerId Id2) {
    return false;
}

FFixed ULocCoreStatics::Clamp_Fixed(FFixed A, FFixed min, FFixed max) {
    return FFixed{};
}

FFixed ULocCoreStatics::Ceil_Fixed(FFixed A) {
    return FFixed{};
}

FFixed ULocCoreStatics::asin(FFixed Fixed) {
    return FFixed{};
}

FIntVector ULocCoreStatics::Add_IntVectorIntVector(FIntVector A, FIntVector B) {
    return FIntVector{};
}

FFixed ULocCoreStatics::Add_FixedFixed(FFixed A, FFixed B) {
    return FFixed{};
}

FFixed ULocCoreStatics::acos(FFixed Fixed) {
    return FFixed{};
}


