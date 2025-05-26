#include "GlobalUIStatsTracker.h"
#include "Templates/SubclassOf.h"

UGlobalUIStatsTracker::UGlobalUIStatsTracker(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UGlobalUIStatsTracker::OnUIShown(TSubclassOf<UNavUserWidget> WidgetType) {
}

UGlobalUIStatsTracker* UGlobalUIStatsTracker::GetUIStatsTracker(const UObject* WorldContext) {
    return NULL;
}


