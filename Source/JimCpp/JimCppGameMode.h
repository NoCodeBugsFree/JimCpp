// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "JimCppGameMode.generated.h"

/**
 * 
 */
UCLASS()
class JIMCPP_API AJimCppGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:

	AJimCppGameMode();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	/** Returns current score  */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	int32 GetScore() const;

	/** Sets the should or not start the game flag  */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void SetIsGameStart(bool NewIsGameStart);

	/** Sets the camera actor reference   */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void SetCameraReference(AActor* CameraToSet);

	/** Add some value to current score  */
	void AddScore(int32 ScoreAmount);

	/** Sets next attach point transform   */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void SetNextSpawnPoint(FTransform NewNextSpawnPoint);

	/** Spawn new platform in NextSpawnPoint  */
	UFUNCTION(BlueprintCallable, Category = "AAA")
	void CreateNewPlatform();

protected:

	/** Widget class to create */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Power, Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	/** Current widget reference */
	UPROPERTY()
	class UUserWidget* CurrentWidget;

private:

	/**  Platform type to spawn */
	UPROPERTY(EditAnywhere, Category = "Spawning") 
	TSubclassOf<class AMyPlatformActor> PlatformType;

	/** Attach point to next spawned platform  */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	FTransform NextSpawnPoint;

	/** Simple move camera actor this frame  */
	void MoveCamera();

	/** Current score  */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	int32 Score = 0;

	/** Timer which handle adding score   */
	FTimerHandle ScoreTimerHandler;

	/** Add one point to current score */
	void AddOneScorePoint();

	/** Current camera speed   */
	UPROPERTY(EditDefaultsOnly, Category = "AAA")
	FVector CameraSpeed = FVector(0.f, 0.f, -0.5f);

	/** Shows whether game is started or not  */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	uint32 bIsGameStart : 1;

	/** Camera actor reference   */
	UPROPERTY()
	AActor* Camera;
	
	/** Amount of platforms to spawn at begin play  */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	int32 InitialPlatformNumber = 4;
};
