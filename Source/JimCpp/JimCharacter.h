// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "JimCharacter.generated.h"

UCLASS()
class JIMCPP_API AJimCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AJimCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	/** Returns can Character move or not  */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	bool GetCanMove() const;

	/** Jim Die BlueprintNativeEvent calls to handle death */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AAA")
	void JimDie();
	virtual void JimDie_Implementation();

	/** Reverse character rotation in opposite direction  */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void ChangeJimRotation();

	/** sets whether character able to move or not  */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void SetCanMove(bool NewCanMove);

	/** Calls when character overlaps Kill boxes to kill the character  */
	UFUNCTION()
	void OnKillBoxesOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:


private:
	
	/** Click/touch event will be handle in  ClickOrTouchHandle() function */
	UFUNCTION()
	void OnJimClicked(AActor* TouchedActor, FKey ButtonPressed);

	/** Click/touch event will be handle in  ClickOrTouchHandle() function  */
	UFUNCTION()
	void OnJimTouched(ETouchIndex::Type FingerIndex, AActor* TouchedActor);

	/** Calls when you click or touch the character  */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void ClickOrTouchHandle();

	/** Calls in Begin Play, Initialize two variables 
	* sets the @ForwardRotator to character current rotation
	* sets the @BackwardRotator to opposite direction
	*/
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void SetCharacterRotators();

	/** Current character's forward rotation  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	FRotator ForwardRotator;

	/** Current character's backward rotation  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	FRotator BackwardRotator;

	/** Forward/Backward rotator flag  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	uint32 bRotateForward : 1;

	/** Sound which plays when character was clicked/touched  */
	UPROPERTY(EditDefaultsOnly, Category = "AAA", Meta = (BlueprintProtected = "true"))
	USoundBase* ClickTouchSound;

	/** Calls when need to play click/touch FX  */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void PlayClickTouchSound();

	/** Add specified value to character's movement speed  */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void AddSpeed();

	/** Timer to increase character's speed  */
	FTimerHandle SpeedTimer;

	/** Simple character movement this frame */
	void MoveTick();

	/** Can character move or not flag  */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	uint32 bCanMove : 1;
	
	/** Max Available Speed for this character  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	float MaxAvailableSpeed = 375.f;

	/**  Current Speed for this character */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	float CurrentSpeed = 160.f;

	/** value that will be added to character's movement speed by means of SpeedTimer  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	float SpeedIncrease = 0.5f;
};
