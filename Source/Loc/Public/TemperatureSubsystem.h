#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ArrayOfTemperatureEmitters.h"
#include "ComponentRegistrationSubsystem.h"
#include "TemperatureTileEventDelegate.h"
#include "TemperatureSubsystem.generated.h"

UCLASS(Blueprintable)
class LOC_API UTemperatureSubsystem : public UComponentRegistrationSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, int32> CachedTemperatureMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, FArrayOfTemperatureEmitters> CachedEmitters;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTemperatureTileEvent OnTemperatureChangedAtGridPosition;
    
    UTemperatureSubsystem();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasEmitterInfluenceAt(FIntPoint GridPosition) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTemperatureAt(FIntPoint GridPosition) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<FIntPoint, int32> GetCachedTemperatureMap() const;
    
};

