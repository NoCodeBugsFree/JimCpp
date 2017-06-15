// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraActor.h"
#include "JimCamera.generated.h"

/**
 * 
 */
UCLASS()
class JIMCPP_API AJimCamera : public ACameraActor
{
	GENERATED_BODY()
	
public:

	AJimCamera();

	virtual void BeginPlay() override;

private:

	/** use for GC of all missed spawned actors  */
	UFUNCTION()
	void OnUpBoxOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	/** Box Component to handle GC logic */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* UpDeathBox;

	/** Box Component to kill character when it touches it  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* DownDeathBox;
	
};
