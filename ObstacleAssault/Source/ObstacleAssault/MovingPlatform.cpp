// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();

	FString MyString = GetName();
	UE_LOG(LogTemp, Display, TEXT("BeginPlay: %s"), *MyString);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float pDeltaTime)
{
		//If the object has moved the distance, reverse the velocity, making sure to move the object back by any amount of distance it overshot
	if(ShouldPlatformReverse())
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();

			//set the platform to the max distance it should've moved by
		StartLocation = StartLocation + MoveDirection*MoveDistance; 
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity; //switches direction
	}
	else
	{
			//Grab current location of obj, add velocity to it, set new location
		FVector CurrentLocation = GetActorLocation();
		FVector NewLocation = CurrentLocation + (PlatformVelocity * pDeltaTime);
		SetActorLocation(NewLocation);
	}
}

void AMovingPlatform::RotatePlatform(float pDeltaTime)
{
	FRotator CurrentRotation = GetActorRotation();
	AddActorLocalRotation(RotationVelocity * pDeltaTime);
}

bool AMovingPlatform::ShouldPlatformReverse() const
{
	return GetDistanceMoved() >= MoveDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}
