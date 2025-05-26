#pragma once
#include "CoreMinimal.h"
#include "ActorPool.h"
#include "LocSimulationSubsystem.h"
#include "Templates/SubclassOf.h"
#include "WidgetPool.h"
#include "PoolingSubsystem.generated.h"

class ASimulationActor;
class UUserWidget;

UCLASS(Blueprintable)
class LOCCORE_API UPoolingSubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActorPool ActorPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActorPool SimulationActorPool;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<ASimulationActor>, uint32> HashOfCleanCDO;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWidgetPool WidgetPool;
    
    UPoolingSubsystem();

    UFUNCTION(BlueprintCallable)
    void ReleaseWidgetToPool(UUserWidget* Widget);
    
    UFUNCTION(BlueprintCallable)
    UUserWidget* CreateWidgetFromPool(TSubclassOf<UUserWidget> WidgetClass);
    
};

