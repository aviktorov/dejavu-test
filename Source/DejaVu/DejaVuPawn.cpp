// Copyright (C) 2013-2014, Fate Studio. All rights reserved.

#include "DejaVu.h"
#include "DejaVuPawn.h"


ADejaVuPawn::ADejaVuPawn(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{
	collision = PCIP.CreateDefaultSubobject<UBoxComponent>(this, TEXT("Collision"));
	RootComponent = collision;
	
	collision->SetSimulatePhysics(true);
	collision->SetCollisionProfileName(TEXT("Pawn"));
	
	mesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	mesh->AttachParent = collision;
	mesh->SetSimulatePhysics(false);
	mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	/*
	constraint = PCIP.CreateDefaultSubobject<UPhysicsConstraintComponent>(this, TEXT("RotationLock"));
	constraint->AttachParent = collision;
	
	constraint->SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Locked, 0.0f);
	constraint->SetAngularSwing2Limit(EAngularConstraintMotion::ACM_Locked, 0.0f);
	constraint->SetAngularTwistLimit(EAngularConstraintMotion::ACM_Locked, 0.0f);
	/**/
	
	camera = PCIP.CreateDefaultSubobject<UCameraComponent>(this, TEXT("OrthoCamera"));
	camera->AttachParent = collision;
	camera->ProjectionMode = ECameraProjectionMode::Orthographic;
	camera->SetAbsolute(true, true, true);
}

void ADejaVuPawn::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	
	// physics
	const FVector &movement = this->ConsumeMovementInputVector();
	const FVector &velocity = collision->GetPhysicsLinearVelocity();
	
	collision->SetPhysicsLinearVelocity(FVector(movement.X, movement.Y, velocity.Z));
	
	// camera
	const FVector &position_camera = FVector
	(
		radius * FMath::Cos(FMath::DegreesToRadians(theta)) * FMath::Cos(FMath::DegreesToRadians(phi)),
		radius * FMath::Cos(FMath::DegreesToRadians(theta)) * FMath::Sin(FMath::DegreesToRadians(phi)),
		radius * FMath::Sin(FMath::DegreesToRadians(theta))
	);
	
	camera->SetWorldLocationAndRotation(this->GetActorLocation() + position_camera + FVector::UpVector * this->BaseEyeHeight, (-position_camera).Rotation());
}
