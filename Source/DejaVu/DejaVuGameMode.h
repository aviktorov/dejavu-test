// Copyright (C) 2013-2014, Fate Studio. All rights reserved.

#pragma once

#include "GameFramework/GameMode.h"
#include "DejaVuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class DEJAVU_API ADejaVuGameMode : public AGameMode
{
	GENERATED_UCLASS_BODY()
	
	virtual void BeginPlay() override;
};
