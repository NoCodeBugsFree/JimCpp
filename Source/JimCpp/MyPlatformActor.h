// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyPlatformActor.generated.h"

UCLASS()
class JIMCPP_API AMyPlatformActor : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	AMyPlatformActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/** Calls when camera actor end overlap this platform  */
	UFUNCTION()
	void OnEndOverlapPlatform(AActor* OverlappedActor, AActor* OtherActor);
	
	/** Gets this actor attach point transforms and stores it in game mode  */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void SetNextAttachPointInGameMode();

	/** Create Gaps in Rows by hiding the tile  */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void MakeGaps();

	/** Spawn pickups and obstacles  */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void SpawnItems();

	/** Calls to hide particular tile  */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void HideFloorTile(UStaticMeshComponent* Tile);

	/**  Calls to Spawn the Gold PickUp  */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void SpawnGoldPickUp();

	/** Calls to Spawn the Fire  */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void SpawnFire();

	/** Calls to rotate character when it hits a wall  */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Calls then need to create a new platform  */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void AskGameModeToCreateNewPlatform();

	/** Calls by TimerEnableHit to enable hit events between character and walls */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void EnableWallHitEvents();

private:
	
	/** Timer which activate hit events for walls and character  */
	FTimerHandle TimerEnableHit;
	
	/** Shows can it or can't rotate the character */
	int32 bShouldRotateCharacter : 1;

	/** The amount of fire actors to spawn at this platform  */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	int32 FiresCount = 2;

	/**  The amount of Gold pickups actors to spawn at this platform */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	int32 GoldsCount = 4;

	/**  Gold Spawn FallOff - valid spawn location  */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	FVector GoldSpawnFallOff = FVector(100.f, 50.f, 100.f);

	/** FireSpawnFallOff - valid spawn location  */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	FVector FireSpawnFallOff = FVector(100.f, 50.f, 100.f);

	/** The type of Gold pickups to spawn  */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AGoldPickUp> GoldPickUpTypeToSpawn;

	/** The type of Fire actors to spawn  */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AFire> FireTypeToSpawn;

	// Base components

	/** Background box used for handle Platform end overlap event  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* EndOverlapBox;

	/** Dummy root  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	USceneComponent* MYROOT;

	/** Background wall mesh  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BackWall;

	/** Right wall mesh  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* WallRight;

	/** Left wall mesh  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* WallLeft;

	/** Visual representation of next attach point to attach new platform  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UArrowComponent* NextPlatformAttachPoint;
	
	/** All tiles will be stored here to further use in spawn items logic  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	TArray<UStaticMeshComponent*> SpawnPointsForItems;
	
	// Floor Elements 
	// TODO how to generate them all in OnConstruction() ???
	//01
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement11;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement12;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement13;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement14;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement16;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	TArray<UStaticMeshComponent*> Row01;

	//02
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement21;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement22;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement23;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement24;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement25;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement26;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	TArray<UStaticMeshComponent*> Row02;

	//03
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement31;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement32;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement33;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement34;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement35;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement36;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	TArray<UStaticMeshComponent*> Row03;

	//04
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement41;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement42;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement43;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement44;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement45;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement46;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	TArray<UStaticMeshComponent*> Row04;

	//05
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement51;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement52;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement53;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement54;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement55;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement56;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	TArray<UStaticMeshComponent*> Row05;

	//06
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement61;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement62;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement63;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement64;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement65;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FloorElement66;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	TArray<UStaticMeshComponent*> Row06;
	
};
