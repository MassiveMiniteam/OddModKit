#include "MultiStepBuildInputContext.h"

UMultiStepBuildInputContext::UMultiStepBuildInputContext() {
    this->BuildInputContextClass = NULL;
    this->PlaceIndex = 0;
}

void UMultiStepBuildInputContext::OnGridObjectPlaced(UInputContextBuild* InputContext, AGridObject* GridObject) {
}

void UMultiStepBuildInputContext::OnBuildInputContextCancelled(UInputContextBuild* InputContext) {
}

void UMultiStepBuildInputContext::Cancel() {
}


