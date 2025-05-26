#include "MinionAssignSlotWidget.h"

UMinionAssignSlotWidget::UMinionAssignSlotWidget() {
    this->MinionConfig = NULL;
    this->NextMinionActionData = NULL;
    this->PrevMinionActionData = NULL;
    this->MinionController = NULL;
    this->InventoryComponent = NULL;
}

void UMinionAssignSlotWidget::Setup(UMinionControllerSimulationBaseComponent* InMinionController, UItemMinionConfig* InMinionConfig, int32 InWidgetIndex) {
}

void UMinionAssignSlotWidget::RefreshUI_Implementation() {
}

void UMinionAssignSlotWidget::PrevIndex() {
}

void UMinionAssignSlotWidget::NextIndex() {
}


