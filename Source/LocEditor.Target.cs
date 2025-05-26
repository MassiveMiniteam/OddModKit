using UnrealBuildTool;

public class LocEditorTarget : TargetRules {
	public LocEditorTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Editor;
		BuildEnvironment = TargetBuildEnvironment.Shared;
		ExtraModuleNames.AddRange(new string[] {
			"AssetDatabaseModule",
			"Loc",
			"LocCore"
		});

		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
		CppStandard = CppStandardVersion.Cpp20;
		
		RegisterModulesCreatedByRider();
	}

	private void RegisterModulesCreatedByRider()
	{
		ExtraModuleNames.AddRange(new string[] { "LocModKitEditor", "LocModKit" });
	}
}
