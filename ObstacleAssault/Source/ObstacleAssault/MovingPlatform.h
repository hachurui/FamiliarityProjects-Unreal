// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Delcare and initialize class variables and functions
	UPROPERTY(EditAnywhere)
	FVector StartLocation = FVector(-7340,-20710,2460);

	UPROPERTY(EditAnywhere)
	FVector EndLocation = FVector(StartLocation.X, StartLocation.Y, StartLocation.Z);

	UPROPERTY(EditAnywhere)
	int TravelTime = 10; //How long it takes to travel between the two points

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector PlatformVelocity = FVector(100,0,0);

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	float MoveDistance = 100;

	UPROPERTY(EditAnywhere)
	FRotator RotationVelocity;

	void MovePlatform(float pDeltaTime);
	void RotatePlatform(float pDeltaTime);

	bool ShouldPlatformReverse() const;
	float GetDistanceMoved() const;
};
