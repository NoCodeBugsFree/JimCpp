// Fill out your copyright notice in the Description page of Project Settings.

#include "JimCpp.h"
#include "JimCharacter.h"
#include "Engine.h"
#include "JimCamera.h"
#include "JimCppGameMode.h"

// Sets default values
AJimCharacter::AJimCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bCanMove = false;
	bRotateForward = true;

	// all ControllerRotation must be false
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->MaxWalkSpeed = CurrentSpeed;
}

// Called when the game starts or when spawned
void AJimCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Dynamic binding with KillerBox to kill character on collision
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AJimCharacter::OnKillBoxesOverlapBegin);

	// Dynamic binding with character interaction
	OnClicked.AddDynamic(this, &AJimCharacter::OnJimClicked);
	OnInputTouchBegin.AddDynamic(this, &AJimCharacter::OnJimTouched);
	
	// start timer - every sec increase speed 
	GetWorld()->GetTimerManager().SetTimer(SpeedTimer, this, &AJimCharacter::AddSpeed, 1.f, true);

	// set initial rotators ( ForwardRotator/BackwardRotator )
	SetCharacterRotators();
}

// Called every frame
void AJimCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	/** simple move this frame   */
	MoveTick();
}

// Called to bind functionality to input
void AJimCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	// TODO implement thruster movement ability like in BP tutorials
}

bool AJimCharacter::GetCanMove() const
{
	return bCanMove;
}

void AJimCharacter::JimDie_Implementation()
{
	
}

void AJimCharacter::ChangeJimRotation()
{
	if (bRotateForward)
	{
		SetActorRotation(BackwardRotator);
		bRotateForward = false;
	} 
	else
	{
		SetActorRotation(ForwardRotator);
		bRotateForward = true;
	}
}

void AJimCharacter::SetCanMove(bool NewCanMove)
{
	bCanMove = NewCanMove;
}

void AJimCharacter::OnKillBoxesOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		// Die if collide with AJimCamera
		AJimCamera* Camera = Cast<AJimCamera>(OtherActor);
		if(Camera)
		{
			JimDie();
		}
	}
}

void AJimCharacter::OnJimClicked(AActor* TouchedActor, FKey ButtonPressed)
{
	ClickOrTouchHandle();
}

void AJimCharacter::OnJimTouched(ETouchIndex::Type FingerIndex, AActor* TouchedActor)
{
	ClickOrTouchHandle();
}

void AJimCharacter::ClickOrTouchHandle()
{
	ChangeJimRotation();

	PlayClickTouchSound();
}

void AJimCharacter::SetCharacterRotators()
{
	ForwardRotator = GetActorRotation();
	BackwardRotator = FRotator(ForwardRotator.Pitch, ForwardRotator.Yaw - 180.f, ForwardRotator.Roll);
}

void AJimCharacter::PlayClickTouchSound()
{
	if (ClickTouchSound)
	{
		UGameplayStatics::PlaySound2D(this, ClickTouchSound);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ClickTouchSound [in JimCharacter] == NULL ! "));
	}
}

void AJimCharacter::AddSpeed()
{
	if (bCanMove)
	{
		if (CurrentSpeed < MaxAvailableSpeed)
		{
			CurrentSpeed += SpeedIncrease;
			GetCharacterMovement()->MaxWalkSpeed = CurrentSpeed;
		}
	}
}

void AJimCharacter::MoveTick()
{
	if (bCanMove)
	{
		AddMovementInput(GetActorForwardVector());
	}
}

