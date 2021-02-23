// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Main_AnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class TRAINING_API UMain_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	virtual void NativeInitializeAnimation() override;

	public:
	UFUNCTION(BlueprintCallable, Category = "Animation Functions")
	void UpdateAnimationProperties();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation Properties")
	float MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation Properties")
	bool bIsInAir;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation Properties")
	APawn* Pawn;
	
};
