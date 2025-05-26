using UnrealBuildTool;

public class Loc : ModuleRules {
    public Loc(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AIModule",
            "Core",
            "CoreUObject",
            "DeveloperSettings",
            "Engine",
            "GameplayTags",
            "Gauntlet",
            "InputCore",
            "LocCore",
            "MMTFixed64",
            "MMTNoise",
            "MMTPhysicsEngine",
            "MMTTween",
            "MetasoundEngine",
            "Niagara",
            "NoiseGraphRuntime",
            "ProceduralMeshComponent",
            "Slate",
            "SlateCore",
            "UMG",
        });
    }
}
