#pragma once
#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "Templates/SubclassOf.h"
#include "GridNetworkPresetComponent.generated.h"

class UConstructableConfig;
class UGridNetworkManagerSubsystem;
class UGridNetworkSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGridNetworkPresetComponent : public USplineComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGridNetworkSimulationComponent> GridNetworkType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConstructableConfig* ConstructableConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGridNetworkManagerSubsystem> GridNetworkManagerClass;
    
    UGridNetworkPresetComponent(const FObjectInitializer& ObjectInitializer);

};

