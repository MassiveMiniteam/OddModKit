#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LocActor.h"
#include "ELockOnMode.h"
#include "Templates/SubclassOf.h"
#include "WorldCursor.generated.h"

class APresentationActor;
class ASimulationActor;

UCLASS(Blueprintable)
class LOC_API AWorldCursor : public ALocActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASimulationActor* HoveredSimulationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APresentationActor* HoveredPresentationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinOffsetRadiusOnHover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CursorWidth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ASimulationActor>> WhiteListClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELockOnMode LockOnMode;
    
    AWorldCursor(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    FVector UpdateAndGetValidThrowTargetPosition(bool bUseRayIntersection);
    
    UFUNCTION(BlueprintCallable)
    void SetHoveredActor(APresentationActor* PresentationActor, ASimulationActor* SimulationActor);
    
};

