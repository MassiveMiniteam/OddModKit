#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ArrayOfHostilityComponents.h"
#include "ComponentRegistrationSubsystem.h"
#include "HostilityTileEventDelegate.h"
#include "HostilitySubsystem.generated.h"

class ASimulationActor;
class UDataTable;

UCLASS(Blueprintable)
class LOC_API UHostilitySubsystem : public UComponentRegistrationSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, int32> CachedBudgetsMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, FArrayOfHostilityComponents> CachedHostilityComponents;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHostilityTileEvent OnHostilityChangedAtGridPosition;
    
protected:
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ASimulationActor>> CorruptionWarningMarkers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* CachedEvolutionBudgetToVisualIndexTable;
    
public:
    UHostilitySubsystem();

    UFUNCTION(BlueprintCallable)
    void UnregisterCorruptionMarker(ASimulationActor* Marker);
    
    UFUNCTION(BlueprintCallable)
    void RegisterCorruptionMarker(ASimulationActor* Marker);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCorruptionMarkerClose(FIntVector PositionToCheck);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetVisualHostilityIndexAtPosition(FIntPoint GridPosition) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<FIntPoint, int32> GetCachedHostilityMap() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCachedAvailableBudgetAtPosition(FIntPoint GridPosition) const;
    
};

