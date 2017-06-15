// Fill out your copyright notice in the Description page of Project Settings.

#include "JimCpp.h"
#include "GoldPickUp.h"
#include "JimCharacter.h"
#include "JimCppGameMode.h"

AGoldPickUp::AGoldPickUp()
{
	/** PickUpMesh  */
	PickUpMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickUp Mesh"));
	PickUpMesh->SetupAttachment(RootComponent);

	/** RotationMovement  */
	RotationMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("Rotation Movement"));
	RotationMovement->RotationRate = FRotator(0.f, 180.f, 0.f);

	ScoreAmount = 100;
}

void AGoldPickUp::OnInteract_Implementation(AActor* Caller)
{
	AJimCharacter* JimCharacter= Cast<AJimCharacter>(Caller);
	if(JimCharacter)
	{
		if (JimCharacter->GetCanMove())
		{
			// add score
			AJimCppGameMode* GameMode = Cast<AJimCppGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
			if (GameMode)
			{
				GameMode->AddScore(ScoreAmount);
			}

			// play sound
			PlayInteractSound();

			// destroy pickup
			Destroy();
		} 
		else
		{
			// spawn collision handle 
			// prevents two actor's spawning at one tile
			Destroy();
		}
	}
}