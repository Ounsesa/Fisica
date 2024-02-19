// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerActor.h"
#include "Particle.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ASpawnerActor::ASpawnerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnerActor::BeginPlay()
{
	Super::BeginPlay();

	for (int index = 0; index < MaxParticleNumbers; index++)
	{
		AParticle* Particle = GetWorld()->SpawnActor<AParticle>(ParticleActor);
		Particle->Init(GetActorLocation());
		ParticlePool.Push(Particle);

	}
	
}

// Called every frame
void ASpawnerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SpawnTimer += DeltaTime;
	if (SpawnTimer >= TimeBetweenSpawns)
	{
		SpawnTimer = 0;
		AParticle* Particle = ParticlePool[ParticleIndex++];
		if (!(Particle->ParticleActive))
		{
			Particle->SetActiveParticle();
		}
		

		if (ParticleIndex >= MaxParticleNumbers)
		{
			ParticleIndex = 0;
		}
		
	}

}

