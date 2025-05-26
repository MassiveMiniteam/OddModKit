using UnrealBuildTool;

public class LocModKit : ModuleRules
{
    public LocModKit(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "DeveloperSettings"
            }
        );

        if (Target.bBuildEditor)
        {
            PrivateDependencyModuleNames.Add("LocModKitEditor");
        }

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore"
            }
        );
    }
}