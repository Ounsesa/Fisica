// Fill out your copyright notice in the Description page of Project Settings.


#include "Particle.h"
#include "Math/UnrealMathUtility.h"
#include "FieldForce.h"
#include "CircularForce.h"

// Sets default values
AParticle::AParticle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AParticle::SetActiveParticle()
{
	position = spawnPosition;
	ParticleActive = true;

	speed = FVector(FMath::RandRange(-maxSpeed, maxSpeed), FMath::RandRange(-maxSpeed, maxSpeed), maxSpeed);

	aceleration = FVector(FMath::RandRange(0, maxAceleration), FMath::RandRange(0, maxAceleration), 0);
}



// Called when the game starts or when spawned
void AParticle::BeginPlay()
{
	Super::BeginPlay();
	
}

void AParticle::Init(FVector Position)
{
	spawnPosition = Position;
	position = spawnPosition;


	speed = FVector(FMath::RandRange(-maxSpeed, maxSpeed), FMath::RandRange(-maxSpeed, maxSpeed), maxSpeed);

	aceleration = FVector(FMath::RandRange(0, maxAceleration), FMath::RandRange(0, maxAceleration), 0);


	float scale = FMath::FRandRange(0.1f,2.0f);

	SetActorScale3D(FVector(scale, scale, scale));


	mass = maxMass * scale;
	
}

// Called every frame
void AParticle::Tick(float DeltaTime)
{
	if (ParticleActive)
	{

		Super::Tick(DeltaTime);
		
		DespawnTimer += DeltaTime;
		if (DespawnTimer >= TimeBeforeDespawn)
		{
			DespawnTimer = 0;
			ParticleActive = false;
			speed = FVector(0,0,0);
			aceleration = FVector(0,0,0);

			SetActorLocation(FVector(0, 0, 0));
		}
	}
	

	

}

