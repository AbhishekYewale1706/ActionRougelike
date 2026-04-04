// Fill out your copyright notice in the Description page of Project Settings.


#include "RougeCharacter.h"

#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ARougeCharacter::ARougeCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SpringArmComponent=CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->bUsePawnControlRotation=true;
	
	CameraComponent=CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void ARougeCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void ARougeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ARougeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* EnhancedInput= Cast<UEnhancedInputComponent>(PlayerInputComponent);
	
	EnhancedInput->BindAction(IA_Move,ETriggerEvent::Triggered,this,&ARougeCharacter::Move);
	EnhancedInput->BindAction(IA_Look,ETriggerEvent::Triggered,this,&ARougeCharacter::Look);
	
}

void ARougeCharacter::Move(const FInputActionValue& Value)
{
	FVector2D InputValue=Value.Get<FVector2D>();
	
	FRotator ControllerRotation=GetControlRotation();
	ControllerRotation.Pitch=0;
	//Move Forward and Backward
	AddMovementInput(ControllerRotation.Vector(),InputValue.X);
	
	FVector	RightDirection=ControllerRotation.RotateVector(FVector::RightVector);
	// Move Right and Left
	AddMovementInput(RightDirection,InputValue.Y);
	
}

void ARougeCharacter::Look(const FInputActionValue& Value)
{
	FVector2D InputValue=Value.Get<FVector2D>();
	AddControllerYawInput(InputValue.X);
	AddControllerPitchInput(InputValue.Y);
}