// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "InteractableActor.generated.h"

UCLASS()
class JIMCPP_API AInteractableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/** Base Interact functionality realized in BlueprintNativeEvent */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AAA")
	void OnInteract(AActor* Caller);
	virtual void OnInteract_Implementation(AActor* Caller);

	/** Calls to handle interaction between actors  */
	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:

	/** Score points to add to a player score when interaction happen  */
	UPROPERTY(EditDefaultsOnly, Category = "AAA")
	int32 ScoreAmount = 50;
	
	/** Interacting Sound which will played during interaction */
	UPROPERTY(EditDefaultsOnly, Category = "AAA", Meta = (BlueprintProtected = "true"))
	USoundBase* InteractSound;

	/** Calls to play sound of interaction  */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void PlayInteractSound();

	/** Actor's Collision Sphere  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	USphereComponent* CollisionSphere;

};