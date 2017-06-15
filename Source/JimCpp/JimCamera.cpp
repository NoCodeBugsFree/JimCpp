// Fill out your copyright notice in the Description page of Project Settings.

#include "JimCpp.h"
#include "JimCamera.h"
#include "JimCppGameMode.h"
#include "JimCharacter.h"
#include "MyPlatformActor.h"
#include "InteractableActor.h"

AJimCamera::AJimCamera()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	UpDeathBox = CreateDefaultSubobject<UBoxComponent>(TEXT("UpDeathBox"));
	UpDeathBox->SetupAttachment(RootComponent);

	DownDeathBox = CreateDefaultSubobject<UBoxComponent>(TEXT("DownDeathBox"));
	DownDeathBox->SetupAttachment(RootComponent);
}

void AJimCamera::BeginPlay()
{
	Super::BeginPlay();

	// set reference in GameMode
	AJimCppGameMode* GameMode = Cast<AJimCppGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		GameMode->SetCameraReference(this);
	}

	// Garbage collector for all spawned actors
	UpDeathBox->OnComponentEndOverlap.AddDynamic(this, &AJimCamera::OnUpBoxOverlapEnd);
	
}

/** GC  */
void AJimCamera::OnUpBoxOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor)
	{
		AInteractableActor* InteractableActor = Cast<AInteractableActor>(OtherActor);
		if(InteractableActor)
		{
			InteractableActor->SetLifeSpan(1.f);
		}
	}
}

