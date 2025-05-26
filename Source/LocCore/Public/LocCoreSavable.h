#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LocCoreSavable.generated.h"

UINTERFACE(Blueprintable)
class LOCCORE_API ULocCoreSavable : public UInterface {
    GENERATED_BODY()
};

class LOCCORE_API ILocCoreSavable : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnBeforeSerialisationSave();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnBeforeSerialisationLoad();
    
    UFUNCTION()
    virtual void OnAllSaveGameActorsLoadedAndRegistered() PURE_VIRTUAL(OnAllSaveGameActorsLoadedAndRegistered,);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnAfterSerialisationSave();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnAfterSerialisationLoad();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnAfterSaveGameLoaded();
    
};

