// Fill out your copyright notice in the Description page of Project Settings.

#include "JimCpp.h"
#include "Fire.h"
#include "JimCharacter.h"
#include "JimCppGameMode.h"
#include "Engine.h"

AFire::AFire()
{
	PrimaryActorTick.bCanEverTick = false;

	// Particle system
	FireParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Fire"));
	FireParticles->SetupAttachment(RootComponent);

	// Dynamic Input Binding
	CollisionSphere->OnClicked.AddDynamic(this, &AFire::OnCompClicked);
	CollisionSphere->OnInputTouchBegin.AddDynamic(this, &AFire::OnCompTouched);

	/** setup collisions for click/touch events for Collision Sphere  */
	CollisionSphere->SetCollisionResponseToAllChannels(ECR_Block);
	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void AFire::OnInteract_Implementation(AActor* Caller)
{
	AJimCharacter* JimCharacter = Cast<AJimCharacter>(Caller);
	if (JimCharacter)
	{
		if (JimCharacter->GetCanMove())
		{
			JimCharacter->JimDie();
		}
		else
		{
			// spawn collision handle to prevent two spawned actors at one tile
			Destroy();
		}
	}
}

void AFire::PlayTouchSound()
{
	if (TouchSound)
	{
		UGameplayStatics::PlaySound2D(GetWorld(), TouchSound);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("TouchSound == NULL"));
	}
}

void AFire::ClickOrTouchHandle()
{
	if (Clicked == ClickedToDestroy)
	{
		// add score in GameMode
		AJimCppGameMode* GameMode = Cast<AJimCppGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
		if (GameMode)
		{
			GameMode->AddScore(ScoreAmount);
		}

		PlayInteractSound();

		Destroy();
	} 
	else
	{
		Clicked++;
		PlayTouchSound();
	}
}

void AFire::OnCompClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	ClickOrTouchHandle();
}

void AFire::OnCompTouched(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent)
{
	ClickOrTouchHandle();
}
