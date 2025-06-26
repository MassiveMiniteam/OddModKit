#include "LocStatics.h"
#include "Templates/SubclassOf.h"

ULocStatics::ULocStatics() {
}

void ULocStatics::UnlockWithoutCommand(UObject* WorldContext, UUnlockableDataAsset* UnlockableDataAsset) {
}

void ULocStatics::UnlockAllPlayerUpgrades(const UObject* WorldContext) {
}

void ULocStatics::UnlockAllPlayerActions(const UObject* WorldContext) {
}

AGridObject* ULocStatics::TryToAddItemsIntoGridObjectAtPositionWithTag(const UObject* WorldContext, const TArray<FItemStack>& Items, FIntPoint GridPosition, TArray<FName> Tags, AGridObject* IgnoreActor, bool bAllowPartialAdding) {
    return NULL;
}

AGridObject* ULocStatics::TryToAddItemsIntoGridObjectAtPosition(const UObject* WorldContext, const TArray<FItemStack>& Items, FIntPoint GridPosition, AGridObject* IgnoreActor, bool bAllowPartialAdding) {
    return NULL;
}

UObject* ULocStatics::TryLoadObject(const FString& SaveToFolderPath, const FString& Prefix, const FString& Filename) {
    return NULL;
}

void ULocStatics::SwitchInputDataType(const UObject* WorldContext, UInputActionData* InputAction, EInputDefaultActionType& OutActionType, bool bWasPressed, bool bWasReleased) {
}

FString ULocStatics::StripRichtextFromString(const FString& String) {
    return TEXT("");
}

TArray<AActor*> ULocStatics::StableSortActorArrayByClassListOrder_BlueprintVersion(const TArray<AActor*>& ActorArray, const TArray<TSubclassOf<AActor>>& SortOrderList) {
    return TArray<AActor*>();
}

bool ULocStatics::SphereOverlapActorsSorted(const UObject* WorldContextObject, const FVector SpherePos, float SphereRadius, const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes, UClass* ActorClassFilter, const TArray<AActor*>& ActorsToIgnore, TArray<AActor*>& OutActors) {
    return false;
}

TArray<UObject*> ULocStatics::SortUObjectArrayByName(TArray<UObject*> inArray) {
    return TArray<UObject*>();
}

TArray<ASimulationActor*> ULocStatics::SortActorArrayByDistance(TArray<ASimulationActor*> Actors, const FIntVector& position) {
    return TArray<ASimulationActor*>();
}

FVector ULocStatics::SnapWorldPositionToGrid(FVector InWorldPosition) {
    return FVector{};
}

int32 ULocStatics::SimpleHashGridPositionFromLocation(FVector Location) {
    return 0;
}

int32 ULocStatics::SimpleHashGridPosition(FIntPoint GridPosition) {
    return 0;
}

void ULocStatics::ShowFriendsUI() {
}

void ULocStatics::SetUIScale(float UIScale) {
}

void ULocStatics::SetPlayerInteractionOnActor(ASimulationActor* SimulationActor, FPlayerInteractionData PlayerInteractionData) {
}

void ULocStatics::SetLocalPlayerInteractionOnActor(ASimulationActor* SimulationActor, bool bBlockOtherInteractions) {
}

void ULocStatics::ScheduleUnlockCommand(const UObject* WorldContext, UUnlockableDataAsset* UnlockableDataAsset) {
}

int32 ULocStatics::RoundRotationToDirections(int32 ZRotation) {
    return 0;
}

FIntVector ULocStatics::RotateIntVector(FIntVector Vector, FFixed Angle) {
    return FIntVector{};
}

FIntPoint ULocStatics::RotateGridPosition(FIntPoint Point, FFixed Angle) {
    return FIntPoint{};
}

FString ULocStatics::ReturnStrippedRichtext(const FString& String, int32 MaxLettercount) {
    return TEXT("");
}

UActorComponent* ULocStatics::ResolveComponentReference(const FComponentReference& Reference, AActor* Owner) {
    return NULL;
}

FGameplayTagContainer ULocStatics::RequestGameplayTagChildrenRecursive(FGameplayTag ParentTag) {
    return FGameplayTagContainer{};
}

FGameplayTagContainer ULocStatics::RequestGameplayTagChildren(FGameplayTag ParentTag) {
    return FGameplayTagContainer{};
}

void ULocStatics::RenameComponent(UActorComponent* Component, FName NewName) {
}

void ULocStatics::RemoveLocalPlayerInteractionOnActor(ASimulationActor* SimulationActor) {
}

FVector ULocStatics::RaycastTerrainLine(const UObject* WorldContext, FVector Start, FVector End) {
    return FVector{};
}

FVector ULocStatics::RaycastTerrain(const UObject* WorldContext, FVector position, FVector& OutNormal) {
    return FVector{};
}

FVector ULocStatics::RaycastAllDynamic(const UObject* WorldContext, FVector Start, FVector End) {
    return FVector{};
}

FVector ULocStatics::Raycast(const UObject* WorldContext, FVector position, FVector& OutNormal, TArray<TEnumAsByte<EObjectTypeQuery>> QueryType, TArray<AActor*> ActorsToIgnore) {
    return FVector{};
}

void ULocStatics::QueryEntitlement(UObject* WorldContextObject, UProductEntitlementDataAsset* ProductEntitlementDataAsset) {
}

int32 ULocStatics::NormalizeAngle(int32 InAngle) {
    return 0;
}

float ULocStatics::ModifyTargetAngleForSmallestAbsoluteDifference(float StartingAngle, float TargetAngle) {
    return 0.0f;
}

FTransform ULocStatics::MakeTransformRotateInTheOppositeDirection(const FTransform& InputTransform) {
    return FTransform{};
}

FFixed64 ULocStatics::MakeFixed64FromFixed(const FFixed& X) {
    return FFixed64{};
}

bool ULocStatics::LocalTimeIsInTimeWindow(FFixed LocalTime, FFixed TimeWindowStart, FFixed TimeWindowEnd) {
    return false;
}

bool ULocStatics::LocalTimeIsInFrameToHitSpecificTiming(FFixed LocalTime, FFixed DeltaTimeThisFrame, FFixed SpecificTiming) {
    return false;
}

void ULocStatics::LoadGameplayMap(UObject* WorldContext) {
}

bool ULocStatics::IsWorldTearingDown(const UObject* WorldContext) {
    return false;
}

bool ULocStatics::IsWorldElevationSetToFlat(const UObject* WorldContextObject) {
    return false;
}

bool ULocStatics::IsSimulationActorFullyCorrupted(ASimulationActor* SimulationActor) {
    return false;
}

bool ULocStatics::IsPointInsideBox(const FBox2D& Box, const FVector2D& Point) {
    return false;
}

bool ULocStatics::IsLocalViewportFocussed(const UObject* WorldContext) {
    return false;
}

void ULocStatics::IsInputDataType(const UObject* WorldContext, UInputActionData* InputAction, EInputDefaultActionType Type, EBranchBool& OutBranch, bool bWasPressed, bool bWasReleased, bool bAutoConsume) {
}

bool ULocStatics::IsCurrentlyInSkipProgression(const UObject* WorldContextObject) {
    return false;
}

bool ULocStatics::IsChildClassOfAnyGridObject(const TArray<TSubclassOf<AGridObject>>& Array, const UClass* Class) {
    return false;
}

bool ULocStatics::IsChildClassOfAny(const TArray<UClass*>& Array, const UClass* Class) {
    return false;
}

bool ULocStatics::IsCharacterCustomizationPartUnlocked(UObject* WorldContext, FCharacterCustomizationPart CustomizationPart) {
    return false;
}

bool ULocStatics::IsAnyItemOfBuildCategoryUnlocked(const UObject* WorldContext, EBuildCategory BuildCategory) {
    return false;
}

bool ULocStatics::IsActorOccupiedByPlayer(const ASimulationActor* SimulationActor) {
    return false;
}

bool ULocStatics::IsActorInUseByPlayer(const ASimulationActor* SimulationActor) {
    return false;
}

bool ULocStatics::IsActorFlaggedAsReserved(const ASimulationActor* SimulationActor) {
    return false;
}

void ULocStatics::HostSessionEOS(const UObject* WorldContext) {
}

void ULocStatics::HostSession(const UObject* WorldContext) {
}

int32 ULocStatics::HashStringToSeed(const FString& Str) {
    return 0;
}

bool ULocStatics::HasFreeLineOfSightBetween(const UObject* WorldContext, UPositionSimulationComponent* PositionComp1, UPositionSimulationComponent* PositionComp2, const FGameplayTagContainer& BlockingTags) {
    return false;
}

FIntVector ULocStatics::GetWorldPositionIntVector(FIntPoint position) {
    return FIntVector{};
}

FIntVector ULocStatics::GetWorldPositionFromGridPosition(const UObject* WorldContext, FIntPoint position) {
    return FIntVector{};
}

FVector ULocStatics::GetWorldPosition(FIntPoint position) {
    return FVector{};
}

FVector ULocStatics::GetWorldDirection(FIntPoint position) {
    return FVector{};
}

FVoicelineSensationData ULocStatics::GetVoicelineSensationDataForGameplayTag(FGameplayTag Tag) {
    return FVoicelineSensationData{};
}

UUnlockHandlingSimulationComponent* ULocStatics::GetUnlockHandler(UObject* WorldContext) {
    return NULL;
}

TArray<UItemConfig*> ULocStatics::GetUnlockedGlossaryItemsByTag(FGameplayTagContainer PassFilterIfTagsMatch, FGameplayTagContainer BlocksFilterIfAnyTagMatch, const TArray<UItemConfig*>& UnlockedItems) {
    return TArray<UItemConfig*>();
}

UUnlockableTier* ULocStatics::GetTierForUnlockable(UObject* WorldContext, UUnlockableDataAsset* Unlockable) {
    return NULL;
}

TArray<TSoftClassPtr<UObject>> ULocStatics::GetSoftReferencesToAllSubclassesOf(UClass* ParentClass, const FString& Path, bool ResultIncludesBaseClass) {
    return TArray<TSoftClassPtr<UObject>>();
}

ASimulationScheduler* ULocStatics::GetSimulationScheduler(const UObject* WorldContext) {
    return NULL;
}

ASimulationManager* ULocStatics::GetSimulationManager(const UObject* WorldContext) {
    return NULL;
}

TArray<FVector> ULocStatics::GetScreenCornersAsWorldPosition(UObject* WorldContext) {
    return TArray<FVector>();
}

FName ULocStatics::GetRibbonLogicChannel() {
    return NAME_None;
}

FName ULocStatics::GetRandomUnlockedKeyForCharacterCustomizationPart(UObject* WorldContext, UDataTable* DataTable) {
    return NAME_None;
}

TArray<FIntPoint> ULocStatics::GetRandomPointsFromArray(const UObject* WorldContext, TArray<FIntPoint> Points, int32 MaxPoints) {
    return TArray<FIntPoint>();
}

TArray<FItemStack> ULocStatics::GetRandomLootFromTable(const UObject* WorldContext, UDataTable* LootTable) {
    return TArray<FItemStack>();
}

FVector ULocStatics::GetProjectileCurveDerivative(FVector Start, FVector Target, float Height, float Alpha) {
    return FVector{};
}

FVector ULocStatics::GetProjectileCurve(FVector Start, FVector Target, float Height, float Alpha) {
    return FVector{};
}

TSubclassOf<APresentationActor> ULocStatics::GetPresentationActorClass(const UObject* WorldContext, UClass* SimulationActor) {
    return NULL;
}

APresentationActor* ULocStatics::GetPresentationActor(ASimulationActor* SimulationActor) {
    return NULL;
}

FVector ULocStatics::GetParabolaPoint(FVector Start, FVector End, float Height, float T) {
    return FVector{};
}

TArray<FHitResult> ULocStatics::GetObjectsUnderCursor(const UObject* WorldContext, const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypeQueries, float CursorSphereRadius) {
    return TArray<FHitResult>();
}

TMap<FIntPoint, FIntPoint> ULocStatics::GetNeighbouringTilesFourDirections(UObject* WorldContext, FIntPoint CenterTile) {
    return TMap<FIntPoint, FIntPoint>();
}

UStatsComponent* ULocStatics::GetNativeCachedComponent_StatsComponent(const AActor* Actor) {
    return NULL;
}

UPositionSimulationComponent* ULocStatics::GetNativeCachedComponent_PositionComponent(const AActor* Actor) {
    return NULL;
}

UPathAddOnSimulationComponent* ULocStatics::GetNativeCachedComponent_PathAddonComponent(const AActor* Actor) {
    return NULL;
}

FIntPoint ULocStatics::GetMinionOnPathInitialHeading(ASimulationActor* Minion, FIntVector ThrowStartPosition, FIntVector ThrowTargetPosition) {
    return FIntPoint{};
}

int32 ULocStatics::GetLootTableTotalWeight(UDataTable* LootTable) {
    return 0;
}

bool ULocStatics::GetLootFromTable(UDataTable* LootTable, int32 RolledWeight, TArray<FItemStack>& OutItemStack) {
    return false;
}

ULootDropTrackerSimulationComponent* ULocStatics::GetLootDropTracker(UObject* WorldContext) {
    return NULL;
}

ULocGameViewportClient* ULocStatics::GetLocGameViewportClient(const UObject* WorldContext) {
    return NULL;
}

ALocGameState* ULocStatics::GetLocGameState(const UObject* WorldContext) {
    return NULL;
}

ALocPlayerController* ULocStatics::GetLocalLocPlayerController(const UObject* WorldContext) {
    return NULL;
}

FIntPoint ULocStatics::GetGridPositionIntVector(FIntVector position) {
    return FIntPoint{};
}

FIntPoint ULocStatics::GetGridPositionFromFixedVector(FFixed64Vector position) {
    return FIntPoint{};
}

FIntPoint ULocStatics::GetGridPosition(FVector position) {
    return FIntPoint{};
}

UPathAddOnSimulationComponent* ULocStatics::GetGridObjectWithComponentAt_PathAddonSimulationComponent(const UObject* WorldContext, FIntPoint position, AGridObject*& OutGridObject) {
    return NULL;
}

UActorComponent* ULocStatics::GetGridObjectWithComponentAt(const UObject* WorldContext, TSubclassOf<UActorComponent> ComponentClass, FIntPoint position, AGridObject*& OutGridObject) {
    return NULL;
}

AGrid* ULocStatics::GetGridInstance(const UObject* WorldContext) {
    return NULL;
}

TArray<FIntPoint> ULocStatics::GetGridCoordinatesInCrossShape(UObject* WorldContext, FIntPoint Origin, int32 Length) {
    return TArray<FIntPoint>();
}

UGlossaryCategoryData* ULocStatics::GetGlossaryDataAssetBySimulationActor(const UObject* WorldContext, TSubclassOf<ASimulationActor> GlossaryActor) {
    return NULL;
}

TArray<FGameplayTag> ULocStatics::GetGameplayTagArrayFromContainer(FGameplayTagContainer GameplayTagContainer) {
    return TArray<FGameplayTag>();
}

FIntVector ULocStatics::GetForwardFromAngle(int32 Angle, int32 Scale) {
    return FIntVector{};
}

FFixed ULocStatics::GetDistance(FIntVector PointA, FIntVector PointB) {
    return FFixed{};
}

UObject* ULocStatics::GetDefaultObjectOfClass(UClass* Class) {
    return NULL;
}

FName ULocStatics::GetDefaultLogicChannel() {
    return NAME_None;
}

FGameplayTagContainer ULocStatics::GetDamageResistanceTagsFromStatsComponent(const UStatsComponent* StatsComponent) {
    return FGameplayTagContainer{};
}

FGameplayTagContainer ULocStatics::GetDamageResistanceTagsFromSimulationActor(const ASimulationActor* Actor) {
    return FGameplayTagContainer{};
}

FGameplayTagContainer ULocStatics::GetDamageResistanceTagsFromGlossaryAsset(const UGlossaryCategoryData* GlossaryData) {
    return FGameplayTagContainer{};
}

TArray<UConstructableConfig*> ULocStatics::GetConstructableConfigsByCategory(const UObject* WorldContext, EBuildCategory BuildCategory) {
    return TArray<UConstructableConfig*>();
}

UConstructableConfig* ULocStatics::GetConstructableConfigForClass(const TSubclassOf<AGridObject> GridObjectClass, UObject* WorldContext) {
    return NULL;
}

ASimulationActor* ULocStatics::GetClosestUnitTargetableByAbilityFromSpecificTiles(TSubclassOf<UGameplayAbility> Ability, const ASimulationActor* AbilityUser, const TArray<FIntPoint>& Tiles, const TArray<EFactionType>& FactionFilter) {
    return NULL;
}

UBiomeCellConfig* ULocStatics::GetBiomeCellConfigAt(const UObject* WorldContext, FIntPoint GridPosition) {
    return NULL;
}

UBiomeConfig* ULocStatics::GetBiomeAt(const UObject* WorldContext, FIntPoint GridPosition) {
    return NULL;
}

TArray<UUnlockableDataAsset*> ULocStatics::GetAllUnlockableConfigs(const UObject* WorldContext) {
    return TArray<UUnlockableDataAsset*>();
}

TArray<UUnlockableAction*> ULocStatics::GetAllUnlockableActions(const UObject* WorldContext) {
    return TArray<UUnlockableAction*>();
}

TArray<UClass*> ULocStatics::GetAllSubclassesOf(UClass* ParentClass, TArray<FString> PathsToLookAt) {
    return TArray<UClass*>();
}

TArray<URecipeConfig*> ULocStatics::GetAllRecipes(const UObject* WorldContext) {
    return TArray<URecipeConfig*>();
}

TArray<UItemConfig*> ULocStatics::GetAllItemsByTag(const UObject* WorldContext, FGameplayTagContainer PassFilterIfAllTagsMatch, FGameplayTagContainer BlocksFilterIfAnyTagMatch) {
    return TArray<UItemConfig*>();
}

TArray<UInputActionData*> ULocStatics::GetAllInputActions(const UObject* WorldContext) {
    return TArray<UInputActionData*>();
}

TArray<UGroundMeshMappingAsset*> ULocStatics::GetAllGroundMeshMappingAssets(UObject* WorldContext) {
    return TArray<UGroundMeshMappingAsset*>();
}

TArray<UGlossaryGameplayData*> ULocStatics::GetAllGlossaryGameplayData(UObject* WorldContext) {
    return TArray<UGlossaryGameplayData*>();
}

TArray<UConstructableConfig*> ULocStatics::GetAllConstructableConfigs(const UObject* WorldContext) {
    return TArray<UConstructableConfig*>();
}

TArray<TScriptInterface<INavElementInterface>> ULocStatics::GetAllChildWidgetsRecursive(UWidget* Widget) {
    return TArray<TScriptInterface<INavElementInterface>>();
}

TArray<UUnlockConditionWrapper*> ULocStatics::GetAllCharacterCustomizationUnlockWrappers(const UObject* WorldContext) {
    return TArray<UUnlockConditionWrapper*>();
}

TArray<UBiomeConfig*> ULocStatics::GetAllBiomeConfigs(const UObject* WorldContext) {
    return TArray<UBiomeConfig*>();
}

TArray<UBiomeCellConfig*> ULocStatics::GetAllBiomeCellConfigs(UObject* WorldContext, FGameplayTag FilterTag) {
    return TArray<UBiomeCellConfig*>();
}

UActorComponent* ULocStatics::FindDefaultComponentByClass(const UClass* InActorClass, const TSubclassOf<UActorComponent> InComponentClass) {
    return NULL;
}

AGridObject* ULocStatics::FindClosestGridObject(const TArray<AGridObject*>& GridObjects, FIntVector OriginLocation) {
    return NULL;
}

void ULocStatics::Enable30PercentLanguage() {
}

bool ULocStatics::DistanceBetweenPositionsIsLessThen(const FIntVector& PointA, const FIntVector& PointB, int32 MaxDistance) {
    return false;
}

void ULocStatics::DestroyComponentForced(UActorComponent* Component) {
}

FIntVector ULocStatics::CrossProduct(const FIntVector& A, const FIntVector& B) {
    return FIntVector{};
}

void ULocStatics::CreateTexture2DAsset(const FString& FilePathAndName, const FString& NewAssetPath) {
}

FIntVector ULocStatics::CornerPositionToCenterPosition(FIntPoint ObjectSize, FIntVector InCornerPosition, int32 InRotation) {
    return FIntVector{};
}

int32 ULocStatics::ConvertWorldHeightToGridHeight(int32 WorldHeight) {
    return 0;
}

int32 ULocStatics::ConvertGridHeightToWorldHeight(int32 GridHeight) {
    return 0;
}

bool ULocStatics::ComponentHasAllTags(const UActorComponent* Component, TArray<FName> Tags) {
    return false;
}

FVector ULocStatics::ClampPositionOnZoomLevel(UObject* WorldContext, UCurveFloat* ZoomCurve, FVector InPosition, FVector2D FlexibleGamepadCursorRange) {
    return FVector{};
}

FIntVector ULocStatics::CenterPositionToCornerPosition(FIntPoint ObjectSize, FIntVector InCenterPosition, int32 InRotation) {
    return FIntVector{};
}

bool ULocStatics::CanUnitBeTargetedByAbility(TSubclassOf<UGameplayAbility> Ability, const ASimulationActor* AbilityUser, const ASimulationActor* Target) {
    return false;
}

bool ULocStatics::CanActorBePickedUp(const ASimulationActor* Actor, bool bIgnoreReservedStat) {
    return false;
}

FFixed ULocStatics::CalculateRadiusForObjectSize(FIntPoint ObjectSize) {
    return FFixed{};
}

void ULocStatics::CalculateMinMaxCornerPosition(UObject* WorldContext, FIntPoint GridPositionA, FIntPoint GridPositionB, FVector& OutMin, FVector& OutMax) {
}

UObject* ULocStatics::ArrayGetHighestOccurence(TArray<UObject*> Array) {
    return NULL;
}

bool ULocStatics::AreAnglesEqual(int32 AngleA, int32 AngleB) {
    return false;
}

FIntVector ULocStatics::AdvancePosition(FIntVector OriginPosition, FIntVector Direction, FFixed Distance) {
    return FIntVector{};
}

FRotator ULocStatics::AdjustRotationToNormal(const FRotator& Rotator, const FVector& Normal) {
    return FRotator{};
}


