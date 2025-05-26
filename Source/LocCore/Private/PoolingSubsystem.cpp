#include "PoolingSubsystem.h"
#include "Templates/SubclassOf.h"

UPoolingSubsystem::UPoolingSubsystem() {
}

void UPoolingSubsystem::ReleaseWidgetToPool(UUserWidget* Widget) {
}

UUserWidget* UPoolingSubsystem::CreateWidgetFromPool(TSubclassOf<UUserWidget> WidgetClass) {
    return NULL;
}


