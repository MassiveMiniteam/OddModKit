#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "LocCoreStatics.h"
#include "Fixed64.h"
#include "Fixed64Vector.h"
#include "CharacterCustomizationPart.h"
#include "EBranchBool.h"
#include "EBuildCategory.h"
#include "EFactionType.h"
#include "EInputDefaultActionType.h"
#include "ItemStack.h"
#include "PlayerInteractionData.h"
#include "Templates/SubclassOf.h"
#include "VoicelineSensationData.h"
#include "LocStatics.generated.h"

class AActor;
class AGrid;
class AGridObject;
class ALocGameState;
class ALocPlayerController;
class APresentationActor;
class ASimulationActor;
class ASimulationManager;
class ASimulationScheduler;
class INavElementInterface;
class UNavElementInterface;
class UActorComponent;
class UBiomeCellConfig;
class UBiomeConfig;
class UConstructableConfig;
class UCurveFloat;
class UDataTable;
class UGameplayAbility;
class UGlossaryCategoryData;
class UGlossaryGameplayData;
class UInputActionData;
class UInventoryComponent;
class UItemConfig;
class UItemStackData;
class ULocGameViewportClient;
class ULootDropTrackerSimulationComponent;
class UObject;
class UPathAddOnSimulationComponent;
class UPositionSimulationComponent;
class UProductEntitlementDataAsset;
class URecipeConfig;
class UStatsComponent;
class UUnlockConditionWrapper;
class UUnlockHandlingSimulationComponent;
class UUnlockableAction;
class UUnlockableDataAsset;
class UUnlockableTier;
class UWidget;

UCLASS(Blueprintable)
class LOC_API ULocStatics : public ULocCoreStatics {
    GENERATED_BODY()
public:
    ULocStatics();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void UnlockWithoutCommand(UObject* WorldContext, UUnlockableDataAsset* UnlockableDataAsset);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void UnlockAllPlayerUpgrades(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void UnlockAllPlayerActions(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static AGridObject* TryToAddItemsIntoGridObjectAtPositionWithTag(const UObject* WorldContext, const TArray<FItemStack>& Items, FIntPoint GridPosition, TArray<FName> Tags, AGridObject* IgnoreActor, bool bAllowPartialAdding);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static AGridObject* TryToAddItemsIntoGridObjectAtPosition(const UObject* WorldContext, const TArray<FItemStack>& Items, FIntPoint GridPosition, AGridObject* IgnoreActor, bool bAllowPartialAdding);
    
    UFUNCTION(BlueprintCallable)
    static UObject* TryLoadObject(const FString& SaveToFolderPath, const FString& Prefix, const FString& Filename);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void SwitchInputDataType(const UObject* WorldContext, UInputActionData* InputAction, EInputDefaultActionType& OutActionType, bool bWasPressed, bool bWasReleased);
    
    UFUNCTION(BlueprintCallable)
    static FString StripRichtextFromString(const FString& String);
    
    UFUNCTION(BlueprintCallable)
    static TArray<AActor*> StableSortActorArrayByClassListOrder_BlueprintVersion(const TArray<AActor*>& ActorArray, const TArray<TSubclassOf<AActor>>& SortOrderList);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool SphereOverlapActorsSorted(const UObject* WorldContextObject, const FVector SpherePos, float SphereRadius, const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes, UClass* ActorClassFilter, const TArray<AActor*>& ActorsToIgnore, TArray<AActor*>& OutActors);
    
    UFUNCTION(BlueprintCallable)
    static TArray<UObject*> SortUObjectArrayByName(TArray<UObject*> inArray);
    
    UFUNCTION(BlueprintCallable)
    static TArray<ASimulationActor*> SortActorArrayByDistance(TArray<ASimulationActor*> Actors, const FIntVector& position);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector SnapWorldPositionToGrid(FVector InWorldPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 SimpleHashGridPositionFromLocation(FVector Location);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 SimpleHashGridPosition(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable)
    static void ShowFriendsUI();
    
    UFUNCTION(BlueprintCallable)
    static void SetUIScale(float UIScale);
    
    UFUNCTION(BlueprintCallable)
    static void SetPlayerInteractionOnActor(ASimulationActor* SimulationActor, FPlayerInteractionData PlayerInteractionData);
    
    UFUNCTION(BlueprintCallable)
    static void SetLocalPlayerInteractionOnActor(ASimulationActor* SimulationActor, bool bBlockOtherInteractions);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void ScheduleUnlockCommand(const UObject* WorldContext, UUnlockableDataAsset* UnlockableDataAsset);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 RoundRotationToDirections(int32 ZRotation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntVector RotateIntVector(FIntVector Vector, FFixed Angle);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntPoint RotateGridPosition(FIntPoint Point, FFixed Angle);
    
    UFUNCTION(BlueprintCallable)
    static FString ReturnStrippedRichtext(const FString& String, int32 MaxLettercount);
    
    UFUNCTION(BlueprintCallable)
    static UActorComponent* ResolveComponentReference(const FComponentReference& Reference, AActor* Owner);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FGameplayTagContainer RequestGameplayTagChildrenRecursive(FGameplayTag ParentTag);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FGameplayTagContainer RequestGameplayTagChildren(FGameplayTag ParentTag);
    
    UFUNCTION(BlueprintCallable)
    static void RenameComponent(UActorComponent* Component, FName NewName);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveLocalPlayerInteractionOnActor(ASimulationActor* SimulationActor);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static FVector RaycastTerrainLine(const UObject* WorldContext, FVector Start, FVector End);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static FVector RaycastTerrain(const UObject* WorldContext, FVector position, FVector& OutNormal);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static FVector RaycastAllDynamic(const UObject* WorldContext, FVector Start, FVector End);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static FVector Raycast(const UObject* WorldContext, FVector position, FVector& OutNormal, TArray<TEnumAsByte<EObjectTypeQuery>> QueryType, TArray<AActor*> ActorsToIgnore);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void QueryEntitlement(UObject* WorldContextObject, UProductEntitlementDataAsset* ProductEntitlementDataAsset);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 NormalizeAngle(int32 InAngle);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float ModifyTargetAngleForSmallestAbsoluteDifference(float StartingAngle, float TargetAngle);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FTransform MakeTransformRotateInTheOppositeDirection(const FTransform& InputTransform);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed64 MakeFixed64FromFixed(const FFixed& X);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool LocalTimeIsInTimeWindow(FFixed LocalTime, FFixed TimeWindowStart, FFixed TimeWindowEnd);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool LocalTimeIsInFrameToHitSpecificTiming(FFixed LocalTime, FFixed DeltaTimeThisFrame, FFixed SpecificTiming);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static bool LocalPlayerCanCurrentlyAffordConstructionCost(const UObject* WorldContext, const TArray<FItemStack>& ConstructionCost);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void LoadGameplayMap(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static bool IsWorldTearingDown(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsWorldElevationSetToFlat(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSimulationActorFullyCorrupted(ASimulationActor* SimulationActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSimilarConfig(const FItemStack& Item, UItemConfig* ItemConfig, UItemStackData* Data);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSimilar(const FItemStack& ItemA, const FItemStack& ItemB);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPointInsideBox(const FBox2D& Box, const FVector2D& Point);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static bool IsLocalViewportFocussed(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void IsInputDataType(const UObject* WorldContext, UInputActionData* InputAction, EInputDefaultActionType Type, EBranchBool& OutBranch, bool bWasPressed, bool bWasReleased, bool bAutoConsume);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsCurrentlyInSkipProgression(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsChildClassOfAnyGridObject(const TArray<TSubclassOf<AGridObject>>& Array, const UClass* Class);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsChildClassOfAny(const TArray<UClass*>& Array, const UClass* Class);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static bool IsCharacterCustomizationPartUnlocked(UObject* WorldContext, FCharacterCustomizationPart CustomizationPart);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static bool IsAnyItemOfBuildCategoryUnlocked(const UObject* WorldContext, EBuildCategory BuildCategory);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsActorOccupiedByPlayer(const ASimulationActor* SimulationActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsActorInUseByPlayer(const ASimulationActor* SimulationActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsActorFlaggedAsReserved(const ASimulationActor* SimulationActor);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void HostSessionEOS(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void HostSession(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable)
    static int32 HashStringToSeed(const FString& Str);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static bool HasFreeLineOfSightBetween(const UObject* WorldContext, UPositionSimulationComponent* PositionComp1, UPositionSimulationComponent* PositionComp2, const FGameplayTagContainer& BlockingTags);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntVector GetWorldPositionIntVector(FIntPoint position);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static FIntVector GetWorldPositionFromGridPosition(const UObject* WorldContext, FIntPoint position);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetWorldPosition(FIntPoint position);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetWorldDirection(FIntPoint position);
    
    UFUNCTION(BlueprintCallable)
    static FVoicelineSensationData GetVoicelineSensationDataForGameplayTag(FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static UUnlockHandlingSimulationComponent* GetUnlockHandler(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable)
    static TArray<UItemConfig*> GetUnlockedGlossaryItemsByTag(FGameplayTagContainer PassFilterIfTagsMatch, FGameplayTagContainer BlocksFilterIfAnyTagMatch, const TArray<UItemConfig*>& UnlockedItems);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static UUnlockableTier* GetTierForUnlockable(UObject* WorldContext, UUnlockableDataAsset* Unlockable);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetStackSize(const FItemStack& Item);
    
    UFUNCTION(BlueprintCallable)
    static TArray<TSoftClassPtr<UObject>> GetSoftReferencesToAllSubclassesOf(UClass* ParentClass, const FString& Path, bool ResultIncludesBaseClass);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static ASimulationScheduler* GetSimulationScheduler(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static ASimulationManager* GetSimulationManager(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static TArray<FVector> GetScreenCornersAsWorldPosition(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName GetRibbonLogicChannel();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static FName GetRandomUnlockedKeyForCharacterCustomizationPart(UObject* WorldContext, UDataTable* DataTable);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<FIntPoint> GetRandomPointsFromArray(const UObject* WorldContext, TArray<FIntPoint> Points, int32 MaxPoints);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<FItemStack> GetRandomLootFromTable(const UObject* WorldContext, UDataTable* LootTable);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetProjectileCurveDerivative(FVector Start, FVector Target, float Height, float Alpha);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetProjectileCurve(FVector Start, FVector Target, float Height, float Alpha);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static TSubclassOf<APresentationActor> GetPresentationActorClass(const UObject* WorldContext, UClass* SimulationActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static APresentationActor* GetPresentationActor(ASimulationActor* SimulationActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetParabolaPoint(FVector Start, FVector End, float Height, float T);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<FHitResult> GetObjectsUnderCursor(const UObject* WorldContext, const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypeQueries, float CursorSphereRadius);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TMap<FIntPoint, FIntPoint> GetNeighbouringTilesFourDirections(UObject* WorldContext, FIntPoint CenterTile);
    
    UFUNCTION(BlueprintCallable)
    static UStatsComponent* GetNativeCachedComponent_StatsComponent(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static UPositionSimulationComponent* GetNativeCachedComponent_PositionComponent(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static UPathAddOnSimulationComponent* GetNativeCachedComponent_PathAddonComponent(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static FIntPoint GetMinionOnPathInitialHeading(ASimulationActor* Minion, FIntVector ThrowStartPosition, FIntVector ThrowTargetPosition);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetLootTableTotalWeight(UDataTable* LootTable);
    
    UFUNCTION(BlueprintCallable)
    static bool GetLootFromTable(UDataTable* LootTable, int32 RolledWeight, TArray<FItemStack>& OutItemStack);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static ULootDropTrackerSimulationComponent* GetLootDropTracker(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static ULocGameViewportClient* GetLocGameViewportClient(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static ALocGameState* GetLocGameState(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static ALocPlayerController* GetLocalLocPlayerController(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetItemStackHashCode(FItemStack& Stack);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntPoint GetGridPositionIntVector(FIntVector position);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntPoint GetGridPositionFromFixedVector(FFixed64Vector position);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntPoint GetGridPosition(FVector position);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static UPathAddOnSimulationComponent* GetGridObjectWithComponentAt_PathAddonSimulationComponent(const UObject* WorldContext, FIntPoint position, AGridObject*& OutGridObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static UActorComponent* GetGridObjectWithComponentAt(const UObject* WorldContext, TSubclassOf<UActorComponent> ComponentClass, FIntPoint position, AGridObject*& OutGridObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static AGrid* GetGridInstance(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<FIntPoint> GetGridCoordinatesInCrossShape(UObject* WorldContext, FIntPoint Origin, int32 Length);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static UGlossaryCategoryData* GetGlossaryDataAssetBySimulationActor(const UObject* WorldContext, TSubclassOf<ASimulationActor> GlossaryActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntVector GetForwardFromAngle(int32 Angle, int32 Scale);
    
    UFUNCTION(BlueprintCallable)
    static FFixed GetDistance(FIntVector PointA, FIntVector PointB);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UObject* GetDefaultObjectOfClass(UClass* Class);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName GetDefaultLogicChannel();
    
    UFUNCTION(BlueprintCallable)
    static FGameplayTagContainer GetDamageResistanceTagsFromStatsComponent(const UStatsComponent* StatsComponent);
    
    UFUNCTION(BlueprintCallable)
    static FGameplayTagContainer GetDamageResistanceTagsFromSimulationActor(const ASimulationActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static FGameplayTagContainer GetDamageResistanceTagsFromGlossaryAsset(const UGlossaryCategoryData* GlossaryData);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static TArray<UConstructableConfig*> GetConstructableConfigsByCategory(const UObject* WorldContext, EBuildCategory BuildCategory);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static UConstructableConfig* GetConstructableConfigForClass(const TSubclassOf<AGridObject> GridObjectClass, UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable)
    static ASimulationActor* GetClosestUnitTargetableByAbilityFromSpecificTiles(TSubclassOf<UGameplayAbility> Ability, const ASimulationActor* AbilityUser, const TArray<FIntPoint>& Tiles, const TArray<EFactionType>& FactionFilter);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static UBiomeCellConfig* GetBiomeCellConfigAt(const UObject* WorldContext, FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static UBiomeConfig* GetBiomeAt(const UObject* WorldContext, FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UUnlockableDataAsset*> GetAllUnlockableConfigs(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UUnlockableAction*> GetAllUnlockableActions(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable)
    static TArray<UClass*> GetAllSubclassesOf(UClass* ParentClass, TArray<FString> PathsToLookAt);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<URecipeConfig*> GetAllRecipes(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UItemConfig*> GetAllItemsByTag(const UObject* WorldContext, FGameplayTagContainer PassFilterIfAllTagsMatch, FGameplayTagContainer BlocksFilterIfAnyTagMatch);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UInventoryComponent*> GetAllInventoriesUsableToLocalPlayerForConstruction(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UInputActionData*> GetAllInputActions(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UGlossaryGameplayData*> GetAllGlossaryGameplayData(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UConstructableConfig*> GetAllConstructableConfigs(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable)
    static TArray<TScriptInterface<INavElementInterface>> GetAllChildWidgetsRecursive(UWidget* Widget);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UUnlockConditionWrapper*> GetAllCharacterCustomizationUnlockWrappers(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UBiomeConfig*> GetAllBiomeConfigs(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UBiomeCellConfig*> GetAllBiomeCellConfigs(UObject* WorldContext, FGameplayTag FilterTag);
    
    UFUNCTION(BlueprintCallable)
    static UActorComponent* FindDefaultComponentByClass(const UClass* InActorClass, const TSubclassOf<UActorComponent> InComponentClass);
    
    UFUNCTION(BlueprintCallable)
    static AGridObject* FindClosestGridObject(const TArray<AGridObject*>& GridObjects, FIntVector OriginLocation);
    
    UFUNCTION(BlueprintCallable)
    static void Enable30PercentLanguage();
    
    UFUNCTION(BlueprintCallable)
    static bool DistanceBetweenPositionsIsLessThen(const FIntVector& PointA, const FIntVector& PointB, int32 MaxDistance);
    
    UFUNCTION(BlueprintCallable)
    static void DestroyComponentForced(UActorComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    static FIntVector CrossProduct(const FIntVector& A, const FIntVector& B);
    
    UFUNCTION(BlueprintCallable)
    static void CreateTexture2DAsset(const FString& FilePathAndName, const FString& NewAssetPath);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntVector CornerPositionToCenterPosition(FIntPoint ObjectSize, FIntVector InCornerPosition, int32 InRotation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 ConvertWorldHeightToGridHeight(int32 WorldHeight);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 ConvertGridHeightToWorldHeight(int32 GridHeight);
    
    UFUNCTION(BlueprintCallable)
    static bool ComponentHasAllTags(const UActorComponent* Component, TArray<FName> Tags);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static FVector ClampPositionOnZoomLevel(UObject* WorldContext, UCurveFloat* ZoomCurve, FVector InPosition, FVector2D FlexibleGamepadCursorRange);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntVector CenterPositionToCornerPosition(FIntPoint ObjectSize, FIntVector InCenterPosition, int32 InRotation);
    
    UFUNCTION(BlueprintCallable)
    static bool CanUnitBeTargetedByAbility(TSubclassOf<UGameplayAbility> Ability, const ASimulationActor* AbilityUser, const ASimulationActor* Target);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool CanActorBePickedUp(const ASimulationActor* Actor, bool bIgnoreReservedStat);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FFixed CalculateRadiusForObjectSize(FIntPoint ObjectSize);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static void CalculateMinMaxCornerPosition(UObject* WorldContext, FIntPoint GridPositionA, FIntPoint GridPositionB, FVector& OutMin, FVector& OutMax);
    
    UFUNCTION(BlueprintCallable)
    static UObject* ArrayGetHighestOccurence(TArray<UObject*> Array);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AreAnglesEqual(int32 AngleA, int32 AngleB);
    
    UFUNCTION(BlueprintCallable)
    static FIntVector AdvancePosition(FIntVector OriginPosition, FIntVector Direction, FFixed Distance);
    
    UFUNCTION(BlueprintCallable)
    static FRotator AdjustRotationToNormal(const FRotator& Rotator, const FVector& Normal);
    
};

