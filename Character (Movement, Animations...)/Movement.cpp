// Fill out your copyright notice in the Description page of Project Settings.


#include "Main.h"

// Sets default values
AMain::AMain()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	MovementMultiplier = 50;

}

// Called when the game starts or when spawned
void AMain::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMain::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (PlayerInputComponent != nullptr)
	{
		PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
		PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
		
		PlayerInputComponent->BindAxis("MoveForward", this, &AMain::MoveForward);
		PlayerInputComponent->BindAxis("MoveSide", this, &AMain::MoveSide);
		
		PlayerInputComponent->BindAxis("CameraUp", this, &APawn::AddControllerPitchInput);
		PlayerInputComponent->BindAxis("CameraSide", this, &APawn::AddControllerYawInput);
	}

}

void AMain::MoveForward(float Input)
{
	if (Controller != nullptr && Input != 0)
	{
		const FRotator ControllerRotation = Controller->GetControlRotation();
		const FRotator YawAxis = FRotator(0.f, ControllerRotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawAxis).GetUnitAxis(EAxis::X);

		AddMovementInput(Direction, Input * MovementMultiplier);
	}
}

void AMain::MoveSide(float Input)
{
	if (Controller != nullptr && Input != 0)
	{
		const FRotator ControllerRotation = Controller->GetControlRotation();
		const FRotator YawAxis = FRotator(0.f, ControllerRotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawAxis).GetUnitAxis(EAxis::Y);

		AddMovementInput(Direction, Input * MovementMultiplier);
	}
}

