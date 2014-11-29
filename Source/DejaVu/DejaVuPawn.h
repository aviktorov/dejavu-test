// Copyright (C) 2013-2014, Fate Studio. All rights reserved.

#pragma once

#include "GameFramework/Pawn.h"
#include "DejaVuPawn.generated.h"

/**
 * 
 */
UCLASS()
class DEJAVU_API ADejaVuPawn : public APawn
{
	GENERATED_UCLASS_BODY()
	
	virtual void Tick(float deltaTime) override;
	
public:
	
	UPROPERTY(Category = Camera, EditAnywhere, BlueprintReadWrite)
	float radius;
	
	UPROPERTY(Category = Camera, EditAnywhere, BlueprintReadWrite)
	float theta;
	
	UPROPERTY(Category = Camera, EditAnywhere, BlueprintReadWrite)
	float phi;
	
protected:
	
	UPROPERTY(Category = Cube, VisibleDefaultsOnly, BlueprintReadOnly)
	TSubobjectPtr<UBoxComponent> collision;
	
	UPROPERTY(Category = Cube, VisibleDefaultsOnly, BlueprintReadOnly)
	TSubobjectPtr<UStaticMeshComponent> mesh;
	
	//UPROPERTY(Category = Cube, VisibleDefaultsOnly, BlueprintReadOnly)
	//TSubobjectPtr<UPhysicsConstraintComponent> constraint;
	
	UPROPERTY(Category = Cube, VisibleDefaultsOnly, BlueprintReadOnly)
	TSubobjectPtr<UCameraComponent> camera;
};
