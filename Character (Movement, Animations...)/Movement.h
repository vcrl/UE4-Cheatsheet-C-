// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"

#include "Main.generated.h"

UCLASS()
class TRAINING_API AMain : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	USpringArmComponent* SpringArm;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	UCameraComponent* Camera;

	UFUNCTION(BlueprintCallable, Category = "Movement Functions")
	void MoveForward(float Input);

	UFUNCTION(BlueprintCallable, Category = "Movement Functions")
	void MoveSide(float Input);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
	float MovementMultiplier;

	

};
