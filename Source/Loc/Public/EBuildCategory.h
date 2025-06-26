#pragma once
#include "CoreMinimal.h"
#include "EBuildCategory.generated.h"

UENUM(BlueprintType)
enum class EBuildCategory : uint8 {
    Harvesters,
    Refiners,
    Assemblers,
    Incubators,
    TemperatureController,
    Supply,
    Logistics,
    PathAddons,
    Storage,
    MagicalStorage,
    Defense,
    Decorations,
    VillageDecorations,
    ForestDecorations,
    StoneDecorations,
    QuartzDecorations,
    AncientDecorations,
    HotDecorations,
    ColdDecorations,
    DebugAndPrototype,
    Shrines,
    TeleporterShrines,
    Logic,
    LogicInput,
    LogicGates,
    LogicOutputs,
    Trains,
    TrainBuildings,
    GroundLayer,
};

