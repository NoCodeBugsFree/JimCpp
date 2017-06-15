// Fill out your copyright notice in the Description page of Project Settings.

#include "JimCpp.h"
#include "InteractableActor.h"


// Sets default values
AInteractableActor::AInteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	/**  Collision Sphere creation */
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Sphere"));
	RootComponent = CollisionSphere;
	CollisionSphere->SetSphereRadius(80.f);

	/** Dynamic binding to bind Collision Sphere overlapping with OnOverlapBegin function */
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AInteractableActor::OnOverlapBegin);
	InitialLifeSpan = 100.f;
}

// Called when the game starts or when spawned
void AInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractableActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AInteractableActor::OnInteract_Implementation(AActor* Caller)
{
	UE_LOG(LogTemp, Error, TEXT("AInteractableActor::OnInteract_Implementation function was called . . . "));
}

void AInteractableActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// ask the OnInteract function to handle overlapping instigator
	if (OtherActor != nullptr)
	{
		OnInteract(OtherActor);
	}
}

void AInteractableActor::PlayInteractSound()
{
	if (InteractSound)
	{
		UGameplayStatics::PlaySound2D(GetWorld(), InteractSound);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("InteractSound == NULL"));
	}
}
