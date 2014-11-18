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
	
	virtual void BeginPlay() override;
	
public:
	
	UPROPERTY(Category = Cube, BlueprintReadWrite)
	float radius;
	
	UPROPERTY(Category = Cube, BlueprintReadWrite)
	float alpha;
	
	UPROPERTY(Category = Cube, BlueprintReadWrite)
	float phi;
	
protected:
	
	UPROPERTY(Category = Cube, VisibleAnywhere, BlueprintReadOnly)
	TSubobjectPtr<UStaticMeshComponent> mesh;
	
	UPROPERTY(Category = Cube, BlueprintReadOnly)
	TSubobjectPtr<UPhysicsConstraintComponent> constraint;
	
	UPROPERTY(Category = Cube, BlueprintReadOnly)
	TSubobjectPtr<UCameraComponent> camera;
};
