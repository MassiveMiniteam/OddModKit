#pragma once
#include "CoreMinimal.h"
#include "SimulationActor.h"
#include "VillageManager.generated.h"

class AActor;
class UWorld;

UCLASS(Blueprintable)
class LOC_API AVillageManager : public ASimulationActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> VillageLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> VillageEntryActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ForcedEntranceZPosition;
    
public:
    AVillageManager(const FObjectInitializer& ObjectInitializer);

};

