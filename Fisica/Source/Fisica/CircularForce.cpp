// Fill out your copyright notice in the Description page of Project Settings.


#include "CircularForce.h"
#include "Particle.h"

// Sets default values
ACircularForce::ACircularForce()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACircularForce::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACircularForce::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (auto& Elem : ForceDirections)
	{
		AParticle* Particle = Elem.Key;
		FVector Direction = Particle->GetActorLocation() - GetActorLocation();
		if (Reverse)
		{
			Direction = -Direction;
		}
		Elem.Value = Direction;
	}

}

void ACircularForce::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	AParticle* Particle = Cast<AParticle>(OtherActor);
	if (Particle)
	{
		FVector Direction = Particle->GetActorLocation() - GetActorLocation();

		if (Reverse)
		{
			Direction = -Direction;
		}
		ForceDirections.Add(Particle, Direction);
		Particle->AddCircularForce(this);
	}
}

void ACircularForce::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	AParticle* Particle = Cast<AParticle>(OtherActor);
	if (Particle)
	{
		ForceDirections.Remove(Particle);
		Particle->RemoveCircularForce(this);
	}
}

FVector ACircularForce::GetForceDirection(AParticle* Particle)
{
	return ForceDirections[Particle];
}

