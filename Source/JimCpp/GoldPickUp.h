// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InteractableActor.h"
#include "GoldPickUp.generated.h"

/**
 * 
 */
UCLASS()
class JIMCPP_API AGoldPickUp : public AInteractableActor
{
	GENERATED_BODY()
	
public:

	AGoldPickUp();

	/** override base class  BlueprintNativeEvent to handle this actor's interaction*/
	virtual void OnInteract_Implementation(AActor* Caller);

private:
	
	/** Represents the  PickUp Mesh */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* PickUpMesh;

	/** Rotation Movement Component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	URotatingMovementComponent* RotationMovement;
};
