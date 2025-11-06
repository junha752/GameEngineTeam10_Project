// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameEnTeam10_Project : ModuleRules
{
	public GameEnTeam10_Project(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
// GameEnTeam10_Project.Build.cs
PublicDependencyModuleNames.AddRange(new string[] { 
    "Core", 
    "CoreUObject", 
    "Engine", 
    "InputCore",
    // UMG(위젯) 기능을 사용하기 위해 아래 모듈들을 추가합니다.
    "UMG",
    "Slate",
    "SlateCore",
    "EnhancedInput" //
});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        // VisualStudioTools ����� ���ܽ�Ű�� �ڵ�
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
