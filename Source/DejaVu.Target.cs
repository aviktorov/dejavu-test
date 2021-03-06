// Copyright (C) 2013-2014, Fate Studio. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class DejaVuTarget : TargetRules
{
	public DejaVuTarget(TargetInfo Target)
	{
		Type = TargetType.Game;
	}

	//
	// TargetRules interface.
	//

	public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.AddRange( new string[] { "DejaVu" } );
	}
}
