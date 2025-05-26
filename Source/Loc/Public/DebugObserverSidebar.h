#pragma once
#include "CoreMinimal.h"
#include "NavUserWidget.h"
#include "OnActorAddedDelegate.h"
#include "OnActorListChangedDelegate.h"
#include "OnActorRemovedDelegate.h"
#include "Templates/SubclassOf.h"
#include "DebugObserverSidebar.generated.h"

class AActor;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UDebugObserverSidebar : public UNavUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActorAdded OnActorAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActorRemoved OnActorRemoved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActorListChanged OnActorListChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> CurrentlyObservedActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AActor>> Whitelist;
    
    UDebugObserverSidebar();

    UFUNCTION(BlueprintCallable)
    void ToggleActor(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void RemoveActor(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void AddActor(const AActor* Actor);
    
};

