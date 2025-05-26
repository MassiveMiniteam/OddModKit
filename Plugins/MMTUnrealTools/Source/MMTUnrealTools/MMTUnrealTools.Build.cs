using UnrealBuildTool;

public class MMTUnrealTools : ModuleRules {
    public MMTUnrealTools(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "GameplayTags",
            "SlateCore",
            "UMG",
        });
    }
}
