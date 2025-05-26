#include "TeleporterStrategy.h"

UTeleporterStrategy::UTeleporterStrategy() {
}


FText UTeleporterStrategy::GetStatusText_Implementation(const UTeleporterSimulationComponent* TeleporterComponent) const {
    return FText::GetEmpty();
}

bool UTeleporterStrategy::AreConditionsFulfilled_Implementation(const UTeleporterSimulationComponent* TeleporterComponent) const {
    return false;
}


