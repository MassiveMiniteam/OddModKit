#include "NavFocusPath.h"
#include "Templates/SubclassOf.h"

UNavFocusPath::UNavFocusPath() {
    this->bLastInteractionByMouse = false;
    this->bOnGoingMouseInteraction = false;
}

int32 UNavFocusPath::Num() {
    return 0;
}

bool UNavFocusPath::HasElementOfType(TArray<TSubclassOf<UNavUserWidget>> WidgetClass) {
    return false;
}

int32 UNavFocusPath::GetIndexForElement(TScriptInterface<INavElementInterface> Element) {
    return 0;
}

TScriptInterface<INavElementInterface> UNavFocusPath::GetFirstElementOfType(TSubclassOf<UNavUserWidget> WidgetClass) {
    return NULL;
}

TScriptInterface<INavElementInterface> UNavFocusPath::GetElementAtIndex(int32 Index) {
    return NULL;
}


