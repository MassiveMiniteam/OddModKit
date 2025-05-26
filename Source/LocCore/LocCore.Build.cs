using UnrealBuildTool;

public class LocCore : ModuleRules {
    public LocCore(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AssetDatabaseModule",
            "Core",
            "CoreUObject",
            "DeveloperSettings",
            "Engine",
            "GameplayTags",
            "Loc",
            "MMTFixed64",
            "NetCore",
            "UMG",
        });
    }
}
