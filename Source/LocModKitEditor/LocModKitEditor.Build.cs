using UnrealBuildTool;

public class LocModKitEditor : ModuleRules
{
    public LocModKitEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core", "Blutility", "UMG", "UnrealEd",
                "Steamworks", "JsonUtilities", "UMGEditor", "ImageWrapper"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "MovieScene",
                "UnrealEd",
                "Engine",
                "Slate",
                "SlateCore", 
                "InputCore",
                "Loc",
                "LocCore", "BlueprintGraph",
                "DeveloperSettings", "UATHelper", "Niagara", "NiagaraEditor", "LevelEditor", "ToolMenus", "EditorScriptingUtilities", "NiagaraAnimNotifies", "Niagara", "AnimationCore"
            }
        );
        
        AddEngineThirdPartyPrivateStaticDependencies(Target, "Steamworks");
    }
}