// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameEnTeam10_Project : ModuleRules
{
	public GameEnTeam10_Project(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        // VisualStudioTools 모듈을 제외시키는 코드
        if (Target.bBuildEditor)
        {
            PrivateDependencyModuleNames.Remove("VisualStudioTools");
        }
        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
