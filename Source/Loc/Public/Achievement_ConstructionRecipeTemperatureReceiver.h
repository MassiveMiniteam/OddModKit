#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "Achievement.h"
#include "Achievement_ConstructionRecipeTemperatureReceiver.generated.h"

class ASimulationActor;
class URecipeConfig;

UCLASS(Blueprintable)
class LOC_API UAchievement_ConstructionRecipeTemperatureReceiver : public UAchievement {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ASimulationActor>> AllowedConstructables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URecipeConfig*> AllowedRecipeConfigs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Efficiency;
    
public:
    UAchievement_ConstructionRecipeTemperatureReceiver();

};

