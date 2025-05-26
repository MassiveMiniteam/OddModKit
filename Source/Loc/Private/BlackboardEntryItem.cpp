#include "BlackboardEntryItem.h"

FBlackboardEntryItem::FBlackboardEntryItem() {
    this->Class = NULL;
    this->Type = EBlackboardEntryItemType::None;
    this->ValueBool = false;
    this->ValueClass = NULL;
    this->ValueEnum = 0;
    this->ValueInt = 0;
    this->ValueObject = NULL;
}

