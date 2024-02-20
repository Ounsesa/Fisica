// Fill out your copyright notice in the Description page of Project Settings.


#include "RotationParticle.h"
#include "FieldForce.h"
#include "CircularForce.h"
#include "AngularForce.h"

void ARotationParticle::Init(FVector Position)
{
	spawnPosition = Position;
	position = spawnPosition;

	AngularPosition = FVector(Roll, Pitch, Yaw);

	AngularSpeed = FVector(FMath::RandRange(-MaxRollSpeed, MaxRollSpeed), FMath::RandRange(-MaxPitchSpeed, MaxPitchSpeed), FMath::RandRange(-MaxYawSpeed, MaxYawSpeed));

	speed = FVector(FMath::RandRange(-maxSpeed, maxSpeed), FMath::RandRange(-maxSpeed, maxSpeed), maxSpeed);
	//speed = FVector(FMath::RandRange(-maxSpeed, maxSpeed), 0, 0);

	aceleration = FVector(FMath::RandRange(0, maxAceleration), FMath::RandRange(0, maxAceleration), 0);


	float scale = FMath::FRandRange(0.1f, 2.0f);

	SetActorScale3D(FVector(scale, scale, scale));


	mass = maxMass * scale;

	Inertia = 2 * mass / 5;

}

void ARotationParticle::AddAngularForce(AAngularForce* _AngularForce)
{
	AngularForces.Add(_AngularForce);
}

void ARotationParticle::RemoveAngularField(AAngularForce* _AngularForce)
{
	AngularForces.Remove(_AngularForce);
}

void ARotationParticle::AddAngularImpulse(FVector AngularImpulse)
{
	AngularSpeed += AngularImpulse;
}

void ARotationParticle::Tick(float DeltaTime)
{
	AActor::Tick(DeltaTime);

	if (ParticleActive)
	{

		AngularPosition += AngularSpeed * DeltaTime;
		AngularSpeed += AngularAcceleration * DeltaTime;

		FRotator newRotation = FRotator(AngularPosition.X, AngularPosition.Y, AngularPosition.Z);


		speed += aceleration * DeltaTime;
		FVector auxSpeed = speed;
		auxSpeed = newRotation.RotateVector(speed);
		SetActorRotation(newRotation);


		position += auxSpeed * DeltaTime;

		SetActorLocation(position);

		for (AFieldForce* fieldForce : FieldForces)
		{
			aceleration += 2 * DeltaTime * fieldForce->Force * fieldForce->Direction / mass;
		}

		for (ACircularForce* circularForce : CircularForces)
		{
			FVector Direction = circularForce->GetForceDirection(this);
			aceleration += 2 * DeltaTime * circularForce->Force * Direction / (mass * Direction.Size());
		}

		for (AAngularForce* angularForce : AngularForces)
		{
			FVector Direction = angularForce->AngularDirection;
			AngularAcceleration += 2 * DeltaTime * angularForce->Force * Direction / Inertia;
		}



		DespawnTimer += DeltaTime;
		if (DespawnTimer >= TimeBeforeDespawn)
		{
			DespawnTimer = 0;
			ParticleActive = false;
			speed = FVector(0, 0, 0);
			aceleration = FVector(0, 0, 0);

			AngularSpeed = FVector(0,0,0);
			AngularAcceleration = FVector(0,0,0);

			SetActorLocation(FVector(0, 0, 0));
		}




	}

}