// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NewFirstPerson415PJ : ModuleRules
{
	public NewFirstPerson415PJ(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Niagara", "ProceduralMeshComponent" });
	}
}
