#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "ComponentOutlineData.h"
#include "CustomDepthStencilWithPriority.h"
#include "OutlinePresentationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UOutlinePresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOcclusionOutlineBlockMode;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FComponentOutlineData> ComponentsToOutline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCustomDepthStencilWithPriority> CustomDepthStencilStack;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStoreComponentsFromChildActors;
    
public:
    UOutlinePresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StoreComponentsToOutline();
    
    UFUNCTION(BlueprintCallable)
    void RemoveCustomDepthStencilValue(int32 CustomDepthStencilValue, FName Tag, FName SourceTag);
    
    UFUNCTION(BlueprintCallable)
    void PushCustomDepthStencilValue(int32 CustomDepthStencilValue, int32 Priority, FName Tag, FName SourceTag);
    
    UFUNCTION(BlueprintCallable)
    void ClearAllCustomDepthStencilData();
    
};

