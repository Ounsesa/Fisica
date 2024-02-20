// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateParticle.h"


void ARotateParticle::Init(FVector Position)
{
	spawnPosition = Position;
	position = spawnPosition;

	AngularPosition = FVector(Roll, Pitch, Yaw);

	AngularSpeed = FVector(FMath::RandRange(-MaxRollSpeed, MaxRollSpeed), FMath::RandRange(-MaxPitchSpeed, MaxPitchSpeed), FMath::RandRange(-MaxYawSpeed, MaxYawSpeed));

	speed = FVector(FMath::RandRange(-maxSpeed, maxSpeed), FMath::RandRange(-maxSpeed, maxSpeed), maxSpeed);

	aceleration = FVector(FMath::RandRange(0, maxAceleration), FMath::RandRange(0, maxAceleration), 0);


	float scale = FMath::FRandRange(0.1f, 2.0f);

	SetActorScale3D(FVector(scale, scale, scale));


	mass = maxMass * scale;

}

void ARotateParticle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (ParticleActive)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("A"));

		AngularPosition += AngularSpeed * DeltaTime;
		AngularSpeed += AngularAcceleration * DeltaTime;

		FRotator newRotation = FRotator(AngularPosition.X,AngularPosition.Y,AngularPosition.Z);
		SetActorRotation(newRotation);

		
	}

}