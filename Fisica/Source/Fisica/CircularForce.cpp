// Fill out your copyright notice in the Description page of Project Settings.


#include "CircularForce.h"
#include "Solid.h"

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

	for (auto& Elem : SolidForceDirections)
	{
		ASolid* Solid = Elem.Key;
		FVector Direction = Solid->GetActorLocation() - GetActorLocation();
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


	ASolid* Solid = Cast<ASolid>(OtherActor);
	if (Solid)
	{
		FVector Direction = Solid->GetActorLocation() - GetActorLocation();

		if (Reverse)
		{
			Direction = -Direction;
		}
		SolidForceDirections.Add(Solid, Direction);
		Solid->AddCircularForce(this);
	}
}

void ACircularForce::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);


	ASolid* Solid = Cast<ASolid>(OtherActor);
	if (Solid)
	{
		SolidForceDirections.Remove(Solid);
		Solid->RemoveCircularForce(this);
	}
}


FVector ACircularForce::GetForceDirection(ASolid* Particle)
{
	return SolidForceDirections[Particle];
}

