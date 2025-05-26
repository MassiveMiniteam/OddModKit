#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EventStreamData.h"
#include "LocAnalyticsSubsystem.generated.h"

UCLASS(Blueprintable)
class LOC_API ULocAnalyticsSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    ULocAnalyticsSubsystem();

    UFUNCTION(BlueprintCallable)
    void Disconnect();
    
    UFUNCTION(BlueprintCallable)
    void Connect();
    
    UFUNCTION(BlueprintCallable)
    void CallPlayStreamEventShort(const FString& EventName, TMap<FString, FString> Data);
    
    UFUNCTION(BlueprintCallable)
    void CallPlayStreamEvent(FEventStreamData anyStruct);
    
};

