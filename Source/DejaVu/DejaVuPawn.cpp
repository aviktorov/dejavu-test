// Copyright (C) 2013-2014, Fate Studio. All rights reserved.

#include "DejaVu.h"
#include "DejaVuPawn.h"


ADejaVuPawn::ADejaVuPawn(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{
	mesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	RootComponent = mesh;
	
	constraint = PCIP.CreateDefaultSubobject<UPhysicsConstraintComponent>(this, TEXT("RotationLock"));
	constraint->AttachParent = mesh;
	
	constraint->SetConstrainedComponents(mesh, TEXT(""), NULL, TEXT(""));
	
	constraint->SetLinearXLimit(ELinearConstraintMotion::LCM_Free,0.0f);
	constraint->SetLinearYLimit(ELinearConstraintMotion::LCM_Free,0.0f);
	constraint->SetLinearZLimit(ELinearConstraintMotion::LCM_Free,0.0f);
	
	constraint->SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Locked,0.0f);
	constraint->SetAngularSwing2Limit(EAngularConstraintMotion::ACM_Locked,0.0f);
	constraint->SetAngularTwistLimit(EAngularConstraintMotion::ACM_Locked,0.0f);
	
	camera = PCIP.CreateDefaultSubobject<UCameraComponent>(this, TEXT("OrthoCamera"));
	camera->AttachParent = mesh;
	camera->ProjectionMode = ECameraProjectionMode::Orthographic;
}

void ADejaVuPawn::BeginPlay()
{
	Super::BeginPlay();
	
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("We are using DejaVu character!"));
	}
}
