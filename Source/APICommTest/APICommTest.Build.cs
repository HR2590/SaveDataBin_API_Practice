// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class APICommTest : ModuleRules
{
	public APICommTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput","HTTP","Json", "JsonUtilities"  });
    }
}
