using UnrealBuildTool;

public class VisualStudioTools : ModuleRules
{
    public VisualStudioTools(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core", "CoreUObject", "Engine", "Projects"
        });
    }
}