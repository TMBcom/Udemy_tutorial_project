// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Udemy_tutorial : ModuleRules
{
	public Udemy_tutorial(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
