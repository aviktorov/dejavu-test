// Copyright (C) 2013-2014, Fate Studio. All rights reserved.

#include "DejaVu.h"
#include "DejaVuPawn.h"


ADejaVuPawn::ADejaVuPawn(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{
	mesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	mesh->SetSimulatePhysics(true);
	mesh->SetCollisionProfileName(TEXT("Pawn"));
	
	constraint = PCIP.CreateDefaultSubobject<UPhysicsConstraintComponent>(this, TEXT("RotationLock"));
	constraint->AttachParent = mesh;
	
	constraint->SetConstrainedComponents(mesh, TEXT(""), NULL, TEXT(""));
	
	constraint->SetLinearXLimit(ELinearConstraintMotion::LCM_Free, 0.0f);
	constraint->SetLinearYLimit(ELinearConstraintMotion::LCM_Free, 0.0f);
	constraint->SetLinearZLimit(ELinearConstraintMotion::LCM_Free, 0.0f);
	
	constraint->SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Locked, 0.0f);
	constraint->SetAngularSwing2Limit(EAngularConstraintMotion::ACM_Locked, 0.0f);
	constraint->SetAngularTwistLimit(EAngularConstraintMotion::ACM_Locked, 0.0f);
	
	camera = PCIP.CreateDefaultSubobject<UCameraComponent>(this, TEXT("OrthoCamera"));
	camera->AttachParent = mesh;
	camera->ProjectionMode = ECameraProjectionMode::Orthographic;
	camera->SetAbsolute(false, true);
	
	RootComponent = mesh;
}

void ADejaVuPawn::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	const FVector &position_camera = FVector
	(
		radius * FMath::Cos(FMath::DegreesToRadians(theta)) * FMath::Cos(FMath::DegreesToRadians(phi)),
		radius * FMath::Cos(FMath::DegreesToRadians(theta)) * FMath::Sin(FMath::DegreesToRadians(phi)),
		radius * FMath::Sin(FMath::DegreesToRadians(theta))
	);
	
	camera->SetRelativeLocationAndRotation(position_camera + FVector::UpVector * this->BaseEyeHeight, (-position_camera).Rotation());
	
	const FVector &movement = this->ConsumeMovementInputVector();
	const FVector &velocity = mesh->GetPhysicsLinearVelocity();
	
	mesh->SetPhysicsLinearVelocity(FVector(movement.X, movement.Y, velocity.Z));
}
