// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Task_2 : ModuleRules
{
	public Task_2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"UMG",
			"AIModule"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}