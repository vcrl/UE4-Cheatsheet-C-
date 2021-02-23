// Fill out your copyright notice in the Description page of Project Settings.


#include "Main_AnimInstance.h"

#include "GameFramework/PawnMovementComponent.h"

void UMain_AnimInstance::NativeInitializeAnimation()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}
}

void UMain_AnimInstance::UpdateAnimationProperties()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}
	if (Pawn)
	{
		FVector Speed = Pawn->GetVelocity();
		FVector VerticalSpeed = FVector(Speed.X, Speed.Y, Speed.Z);
		MovementSpeed = VerticalSpeed.Size();

		bIsInAir = Pawn->GetMovementComponent()->IsFalling();
	}
}

