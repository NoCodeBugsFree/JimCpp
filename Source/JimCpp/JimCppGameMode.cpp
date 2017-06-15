// Fill out your copyright notice in the Description page of Project Settings.

#include "JimCpp.h"
#include "JimCppGameMode.h"
#include "MyPlatformActor.h"
#include "Blueprint/UserWidget.h"

AJimCppGameMode::AJimCppGameMode()
{
	bIsGameStart = false;
}

void AJimCppGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	// Set score timer
	UWorld* World = GetWorld();
	if (World)
	{
		World->GetTimerManager().SetTimer(ScoreTimerHandler, this, &AJimCppGameMode::AddOneScorePoint, 1.f, true);
	}

	// Create specified number platforms
	for (int32 i = 0; i < InitialPlatformNumber; i++)
	{
		CreateNewPlatform();
	}
	
	// create widget and add it to viewport
	if (HUDWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}

	UGameplayStatics::SetGamePaused(GetWorld(), true);
}

void AJimCppGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// simple move this frame by CameraSpeed value
	MoveCamera();
}

int32 AJimCppGameMode::GetScore() const
{
	return Score;
}

void AJimCppGameMode::SetIsGameStart(bool NewIsGameStart)
{
	bIsGameStart = NewIsGameStart;
}

void AJimCppGameMode::SetCameraReference(AActor* CameraToSet)
{
	Camera = CameraToSet;
}

void AJimCppGameMode::AddScore(int32 ScoreAmount)
{
	Score += ScoreAmount;
}

void AJimCppGameMode::SetNextSpawnPoint(FTransform NewNextSpawnPoint)
{
	NextSpawnPoint = NewNextSpawnPoint;
}

void AJimCppGameMode::CreateNewPlatform()
{
	UWorld* const World = GetWorld();
	if(World)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = Instigator;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
		AMyPlatformActor* NewPlatform = World->SpawnActor<AMyPlatformActor>(PlatformType, NextSpawnPoint, SpawnParams);
		if (NewPlatform)
		{
			NewPlatform->SetNextAttachPointInGameMode();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("New Platform NOT CREATED !!!"));
		}
	}
}

void AJimCppGameMode::MoveCamera()
{
	if (bIsGameStart)
	{
		if (Camera)
		{
			FVector OldLocation = Camera->GetActorLocation();
			FVector NewLocation = OldLocation + CameraSpeed;
			Camera->SetActorLocation(NewLocation);
		}
	}
}

void AJimCppGameMode::AddOneScorePoint()
{
	if (bIsGameStart)
	{
		Score += 1;
	}
}
