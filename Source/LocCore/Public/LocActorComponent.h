#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LocActorComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOCCORE_API ULocActorComponent : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsDisabledDueToPooling;
    
public:
    ULocActorComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetIsEnabled(bool bInIsEnabled);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnResetFromPooling();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnEnabledChanged();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsEnabled() const;
    
};

