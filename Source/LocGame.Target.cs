using UnrealBuildTool;

public class LocGameTarget : TargetRules {
	public LocGameTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Game;
		BuildEnvironment = TargetBuildEnvironment.Shared;
		ExtraModuleNames.AddRange(new string[] {
			"AssetDatabaseModule",
			"Loc",
			"LocCore"
		});

		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
		CppStandard = CppStandardVersion.Cpp20;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		
		RegisterModulesCreatedByRider();
	}

	private void RegisterModulesCreatedByRider()
	{
		ExtraModuleNames.AddRange(new string[] { "LocModKit" });
	}
}
