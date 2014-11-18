// Copyright (C) 2013-2014, Fate Studio. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class DejaVuEditorTarget : TargetRules
{
	public DejaVuEditorTarget(TargetInfo Target)
	{
		Type = TargetType.Editor;
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
