#include "EffectOnOverlap.h"

FEffectOnOverlap::FEffectOnOverlap() {
    this->Class = NULL;
    this->bApplyEffectOnStartOverlap = false;
    this->bApplyEffectOnTick = false;
    this->bRemoveEffectOnEndOverlap = false;
    this->bMarkAsDeathOnApplication = false;
}

