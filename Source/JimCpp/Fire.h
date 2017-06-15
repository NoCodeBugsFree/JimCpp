// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InteractableActor.h"
#include "Fire.generated.h"

/**
 * 
 */
UCLASS()
class JIMCPP_API AFire : public AInteractableActor
{
	GENERATED_BODY()
	
public:

	AFire();

	/** Override parent's BlueprintNativeEvent for valid interaction handling */
	virtual void OnInteract_Implementation(AActor* Caller);

protected:



private:

	/** Sound FX which plays when you click/touch it to destroy */
	UPROPERTY(EditDefaultsOnly, Category = "AAA", Meta = (BlueprintProtected = "true"))
	USoundBase* TouchSound;

	/** Calls when you need to play touch/click sound FX  */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void PlayTouchSound();

	/** Calls to handle fire actor state after clicking/touching */
	void ClickOrTouchHandle();

	/** calls to handle this event in ClickOrTouchHandle() function  */
	UFUNCTION()
	void OnCompClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);

	/** calls to handle this event in ClickOrTouchHandle() function  */
	UFUNCTION()
	void OnCompTouched(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent);

	/** Current number of times this actor was clicked/touched by player */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	int32 Clicked = 0;

	/** Amount of clicks/touches which needed to destroy this actor    */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	int32 ClickedToDestroy = 2;
	
	/** FireParticles FX  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UParticleSystemComponent* FireParticles;
	
};
