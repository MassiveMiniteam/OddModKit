#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UIInventoryNavigatorSubsystem.generated.h"

class UInventoryHolderWidget;

UCLASS(Blueprintable)
class LOC_API UUIInventoryNavigatorSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UInventoryHolderWidget*> InventoryHolderWidgets;
    
public:
    UUIInventoryNavigatorSubsystem();

};

