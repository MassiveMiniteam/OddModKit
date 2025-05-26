#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Templates/SubclassOf.h"
#include "DebugObserverComponent.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UDebugObserverComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> CurrentlyObservedActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AActor>> Whitelist;
    
    UDebugObserverComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void ToggleActor(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void RemoveActor(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void AddActor(const AActor* Actor);
    
};

