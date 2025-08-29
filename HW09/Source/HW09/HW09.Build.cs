// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HW09 : ModuleRules
{
	public HW09(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			// Initial Dependencies
			"Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" , "UMG", "Slate", "SlateCore", 
			
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.AddRange(new string[] { "ChatX" });
	}
}
