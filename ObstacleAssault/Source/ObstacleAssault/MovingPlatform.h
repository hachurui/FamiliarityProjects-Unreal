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

	UPROPERTY(EditAnywhere)
	FVector StartLocation = FVector(-7500, -20710, 2460);

	UPROPERTY(EditAnywhere)
	FVector EndLocation = FVector(StartLocation.X, StartLocation.Y+100, StartLocation.Z);

	UPROPERTY(EditAnywhere)
	int TravelTime = 10; //How long it takes to travel between the two points

	UPROPERTY(EditAnywhere, Category="Moving Platform");
	FVector PlatformVelocity = FVector(100,0,0);

	
	int direction = 1;
};
