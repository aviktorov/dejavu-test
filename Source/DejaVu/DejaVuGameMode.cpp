// Copyright (C) 2013-2014, Fate Studio. All rights reserved.

#include "DejaVu.h"
#include "DejaVuGameMode.h"
#include "DejaVuPawn.h"

ADejaVuGameMode::ADejaVuGameMode(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{
	DefaultPawnClass = ADejaVuPawn::StaticClass();
}

void ADejaVuGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("HELLO WORLD"));
	}
}