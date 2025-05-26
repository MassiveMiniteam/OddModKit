#pragma once
#include "CoreMinimal.h"
#include "ShopTokenLevelChangedDelegate.h"
#include "ShopTokenScoreChangedDelegate.h"
#include "TokenGeneratorSimulationComponent.h"
#include "ShopTokenGeneratorComponent.generated.h"

class UObject;
class UShopTokenGeneratorComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UShopTokenGeneratorComponent : public UTokenGeneratorSimulationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FShopTokenScoreChanged OnShopTokenScoreChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FShopTokenLevelChanged OnShopTokenLevelChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CurrentLevel;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int64 CurrentScore;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelGrowthModifier;
    
    UShopTokenGeneratorComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static UShopTokenGeneratorComponent* GetShopTokenGenerator(UObject* WorldContext);
    
    UFUNCTION(BlueprintPure)
    int64 CalculateNeededPointsForLevel(int32 Level) const;
    
};

