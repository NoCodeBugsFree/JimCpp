// Fill out your copyright notice in the Description page of Project Settings.

#include "JimCpp.h"
#include "MyPlatformActor.h"
#include "JimCamera.h"
#include "JimCppGameMode.h"
#include "GoldPickUp.h"
#include "Fire.h"
#include "JimCharacter.h"


// Sets default values
AMyPlatformActor::AMyPlatformActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	bShouldRotateCharacter = true;

	// BASE
	MYROOT = CreateDefaultSubobject<USceneComponent>(TEXT("MYROOT"));
	RootComponent = MYROOT;

	NextPlatformAttachPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	NextPlatformAttachPoint->SetupAttachment(RootComponent);

	BackWall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyBackWall"));
	BackWall->SetupAttachment(RootComponent);
	BackWall->SetRelativeRotation(FRotator(0, 0.f, 90.f));

	WallLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallLeft"));
	WallLeft->SetupAttachment(RootComponent);

	WallRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallRight"));
	WallRight->SetupAttachment(RootComponent);
	
	EndOverlapBox = CreateDefaultSubobject<UBoxComponent>(TEXT("EndOverlapBox"));
	EndOverlapBox->SetupAttachment(RootComponent);
	
	// FLOOR
	
	FloorElement11 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement11"));
	FloorElement11->SetupAttachment(RootComponent);

	FloorElement12 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement12"));
	FloorElement12->SetupAttachment(RootComponent);

	FloorElement13 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement13"));
	FloorElement13->SetupAttachment(RootComponent);

	FloorElement14 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement14"));
	FloorElement14->SetupAttachment(RootComponent);

	FloorElement15 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement15"));
	FloorElement15->SetupAttachment(RootComponent);

	FloorElement16 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement16"));
	FloorElement16->SetupAttachment(RootComponent);

	Row01.AddUnique(FloorElement11);
	Row01.AddUnique(FloorElement12);
	Row01.AddUnique(FloorElement13);
	Row01.AddUnique(FloorElement14);
	Row01.AddUnique(FloorElement15);
	Row01.AddUnique(FloorElement16);


	FloorElement21 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement21"));
	FloorElement21->SetupAttachment(RootComponent);

	FloorElement22 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement22"));
	FloorElement22->SetupAttachment(RootComponent);

	FloorElement23 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement23"));
	FloorElement23->SetupAttachment(RootComponent);

	FloorElement24 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement24"));
	FloorElement24->SetupAttachment(RootComponent);

	FloorElement25 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement25"));
	FloorElement25->SetupAttachment(RootComponent);

	FloorElement26 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement26"));
	FloorElement26->SetupAttachment(RootComponent);

	Row02.AddUnique(FloorElement21);
	Row02.AddUnique(FloorElement22);
	Row02.AddUnique(FloorElement23);
	Row02.AddUnique(FloorElement24);
	Row02.AddUnique(FloorElement25);
	Row02.AddUnique(FloorElement26);


	FloorElement31 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement31"));
	FloorElement31->SetupAttachment(RootComponent);

	FloorElement32 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement32"));
	FloorElement32->SetupAttachment(RootComponent);

	FloorElement33 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement33"));
	FloorElement33->SetupAttachment(RootComponent);

	FloorElement34 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement34"));
	FloorElement34->SetupAttachment(RootComponent);

	FloorElement35 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement35"));
	FloorElement35->SetupAttachment(RootComponent);

	FloorElement36 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement36"));
	FloorElement36->SetupAttachment(RootComponent);

	Row03.AddUnique(FloorElement31);
	Row03.AddUnique(FloorElement32);
	Row03.AddUnique(FloorElement33);
	Row03.AddUnique(FloorElement34);
	Row03.AddUnique(FloorElement35);
	Row03.AddUnique(FloorElement36);


	FloorElement41 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement41"));
	FloorElement41->SetupAttachment(RootComponent);

	FloorElement42 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement42"));
	FloorElement42->SetupAttachment(RootComponent);

	FloorElement43 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement43"));
	FloorElement43->SetupAttachment(RootComponent);

	FloorElement44 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement44"));
	FloorElement44->SetupAttachment(RootComponent);

	FloorElement45 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement45"));
	FloorElement45->SetupAttachment(RootComponent);

	FloorElement46 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement46"));
	FloorElement46->SetupAttachment(RootComponent);

	Row04.AddUnique(FloorElement41);
	Row04.AddUnique(FloorElement42);
	Row04.AddUnique(FloorElement43);
	Row04.AddUnique(FloorElement44);
	Row04.AddUnique(FloorElement45);
	Row04.AddUnique(FloorElement46);


	FloorElement51 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement51"));
	FloorElement51->SetupAttachment(RootComponent);

	FloorElement52 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement52"));
	FloorElement52->SetupAttachment(RootComponent);

	FloorElement53 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement53"));
	FloorElement53->SetupAttachment(RootComponent);

	FloorElement54 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement54"));
	FloorElement54->SetupAttachment(RootComponent);

	FloorElement55 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement55"));
	FloorElement55->SetupAttachment(RootComponent);

	FloorElement56 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement56"));
	FloorElement56->SetupAttachment(RootComponent);

	Row05.AddUnique(FloorElement51);
	Row05.AddUnique(FloorElement52);
	Row05.AddUnique(FloorElement53);
	Row05.AddUnique(FloorElement54);
	Row05.AddUnique(FloorElement55);
	Row05.AddUnique(FloorElement56);


	FloorElement61 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement61"));
	FloorElement61->SetupAttachment(RootComponent);

	FloorElement62 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement62"));
	FloorElement62->SetupAttachment(RootComponent);

	FloorElement63 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement63"));
	FloorElement63->SetupAttachment(RootComponent);

	FloorElement64 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement64"));
	FloorElement64->SetupAttachment(RootComponent);

	FloorElement65 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement65"));
	FloorElement65->SetupAttachment(RootComponent);

	FloorElement66 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorElement66"));
	FloorElement66->SetupAttachment(RootComponent);

	Row06.AddUnique(FloorElement61);
	Row06.AddUnique(FloorElement62);
	Row06.AddUnique(FloorElement63);
	Row06.AddUnique(FloorElement64);
	Row06.AddUnique(FloorElement65);
	Row06.AddUnique(FloorElement66);
	
	SpawnPointsForItems.Append(Row01);
	SpawnPointsForItems.Append(Row02);
	SpawnPointsForItems.Append(Row03);
	SpawnPointsForItems.Append(Row04);
	SpawnPointsForItems.Append(Row05);
	SpawnPointsForItems.Append(Row06);
}

// Called when the game starts or when spawned
void AMyPlatformActor::BeginPlay()
{
	Super::BeginPlay();
	
	// binding for create new Platform through GameMode and Destroy self
	OnActorEndOverlap.AddDynamic(this, &AMyPlatformActor::OnEndOverlapPlatform);
	
	// Protect form multi hitting with character
	// Initial activation here
	EnableWallHitEvents();

	MakeGaps();

	SpawnItems();
}

// Called every frame
void AMyPlatformActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AskGameModeToCreateNewPlatform()
{
	AJimCppGameMode* GameMode = Cast<AJimCppGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		GameMode->CreateNewPlatform();
	}
}

void AMyPlatformActor::OnEndOverlapPlatform(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OverlappedActor)
	{
		AJimCamera* JimCamera = Cast<AJimCamera>(OtherActor);
		if (JimCamera)
		{
			// disable dynamic delegate - protect from multi calls
			OnActorEndOverlap.Clear();

			// Create New Tile
			AskGameModeToCreateNewPlatform();

			// Destroy Self
			Destroy();
		}
	}
}

void AMyPlatformActor::SetNextAttachPointInGameMode()
{
	FTransform AttachTransform;
	AttachTransform = NextPlatformAttachPoint->GetComponentTransform();

	AJimCppGameMode* GameMode = Cast<AJimCppGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		GameMode->SetNextSpawnPoint(AttachTransform);
	}
}

int32 GetNumberOfGapsInRow()
{
	int32 MinGaps = 1;
	int32 MaxGaps = 2;
	return FMath::RandRange(MinGaps, MaxGaps);
}

void AMyPlatformActor::MakeGaps()
{
	for (int32 iCount = 0; iCount < GetNumberOfGapsInRow(); iCount++)
	{
		UStaticMeshComponent* RandomTileInRow = Row01[FMath::RandRange(0, 5)]; // TODO Remove this ugly
		HideFloorTile(RandomTileInRow);
	}

	for (int32 iCount = 0; iCount < GetNumberOfGapsInRow(); iCount++)
	{
		UStaticMeshComponent* RandomTileInRow = Row02[FMath::RandRange(0, 5)];  
		HideFloorTile(RandomTileInRow);
	}

	for (int32 iCount = 0; iCount < GetNumberOfGapsInRow(); iCount++)
	{
		UStaticMeshComponent* RandomTileInRow = Row03[FMath::RandRange(0, 5)]; 
		HideFloorTile(RandomTileInRow);
	}

	for (int32 iCount = 0; iCount < GetNumberOfGapsInRow(); iCount++)
	{
		UStaticMeshComponent* RandomTileInRow = Row04[FMath::RandRange(0, 5)]; 
		HideFloorTile(RandomTileInRow);
	}

	for (int32 iCount = 0; iCount < GetNumberOfGapsInRow(); iCount++)
	{
		UStaticMeshComponent* RandomTileInRow = Row05[FMath::RandRange(0, 5)]; 
		HideFloorTile(RandomTileInRow);
	}

	for (int32 iCount = 0; iCount < GetNumberOfGapsInRow(); iCount++)
	{
		UStaticMeshComponent* RandomTileInRow = Row06[FMath::RandRange(0, 5)]; 
	}
}

void AMyPlatformActor::SpawnItems()
{
	/** Golds  */
	for(int32 iCount = 0; iCount < GoldsCount; iCount++)
	{
		SpawnGoldPickUp();
	}

	/** Fires  */
	for (int32 jCount = 0; jCount < FiresCount; jCount++)
	{
		SpawnFire();
	}
}

void AMyPlatformActor::HideFloorTile(UStaticMeshComponent* TileToHide)
{
	if (TileToHide)
	{
		TileToHide->SetVisibility(false);
		TileToHide->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void AMyPlatformActor::SpawnGoldPickUp()
{
	UWorld* const World = GetWorld();
	if (World)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = Instigator;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::DontSpawnIfColliding;

		// find Spawn Location above the random floor tile
		int32 RandomTileIndex = FMath::RandRange(0, SpawnPointsForItems.Num() - 1);

		FVector SpawnLocation;
		
		// Do not spawn in air (without tile)
		SpawnLocation = SpawnPointsForItems[RandomTileIndex]->GetComponentLocation();
		if (!SpawnPointsForItems[RandomTileIndex]->GetCollisionEnabled())
		{
			UE_LOG(LogTemp, Error, TEXT("Gold Doesn't Spawned in AIR ..."));
			return;
		}

		// SpawnFallOff
		SpawnLocation = FVector(SpawnLocation.X + GoldSpawnFallOff.X,
			SpawnLocation.Y - GoldSpawnFallOff.Y, SpawnLocation.Z + GoldSpawnFallOff.Z);
		
		AGoldPickUp* Gold = World->SpawnActor<AGoldPickUp>(GoldPickUpTypeToSpawn, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
	}
}

void AMyPlatformActor::SpawnFire()
{
	UWorld* const World = GetWorld();
	if (World)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = Instigator;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		int32 RandomTileIndex = FMath::RandRange(0, SpawnPointsForItems.Num() - 1);

		// Do not spawn in Air (without tile)
		FVector SpawnLocation;
		SpawnLocation = SpawnPointsForItems[RandomTileIndex]->GetComponentLocation();
		if (!SpawnPointsForItems[RandomTileIndex]->GetCollisionEnabled())
		{
			UE_LOG(LogTemp, Error, TEXT("Fire Doesn't Spawned in AIR ..."));
			return;
		}

		SpawnLocation = FVector(SpawnLocation.X + FireSpawnFallOff.X,
			SpawnLocation.Y - FireSpawnFallOff.Y, SpawnLocation.Z + FireSpawnFallOff.Z);
		
		AFire* FireToSpawn = World->SpawnActor<AFire>(FireTypeToSpawn, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
	}
}

void AMyPlatformActor::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (bShouldRotateCharacter)
	{
		if (OtherActor)
		{
			AJimCharacter* JimCharacter = Cast<AJimCharacter>(OtherActor);
			if (JimCharacter)
			{
				// if character hits Platform - temporarily disable hit handling
				WallLeft->OnComponentHit.Clear();
				WallRight->OnComponentHit.Clear();
				JimCharacter->ChangeJimRotation();

				// Enable hit handling again
				GetWorldTimerManager().SetTimer(TimerEnableHit, this, &AMyPlatformActor::EnableWallHitEvents, 0.5f, false); // false - once
			}
		}
	}
}

void AMyPlatformActor::EnableWallHitEvents()
{
	WallLeft->OnComponentHit.AddDynamic(this, &AMyPlatformActor::OnHit);
	WallRight->OnComponentHit.AddDynamic(this, &AMyPlatformActor::OnHit);
}

