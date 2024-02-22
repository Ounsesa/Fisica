// Fill out your copyright notice in the Description page of Project Settings.


#include "Solid.h"
#include "FieldForce.h"
#include "CircularForce.h"
#include "AngularForce.h"

// Sets default values
ASolid::ASolid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASolid::AddForceField(AFieldForce* _FieldForce)
{
	FieldForces.Add(_FieldForce);
}

void ASolid::AddCircularForce(ACircularForce* _CircularForce)
{
	CircularForces.Add(_CircularForce);
}

void ASolid::RemoveForceField(AFieldForce* _FieldForce)
{
	FieldForces.Remove(_FieldForce);
}

void ASolid::RemoveCircularForce(ACircularForce* _CircularForce)
{
	CircularForces.Remove(_CircularForce);
}

void ASolid::AddImpulse(FVector Impulse)
{
	speed += Impulse;
}

void ASolid::Init(FVector Position, FVector Speed, FVector Aceleration)
{

	//speed = FVector(FMath::RandRange(-maxSpeed, maxSpeed), FMath::RandRange(-maxSpeed, maxSpeed), FMath::RandRange(-maxSpeed, maxSpeed));
	position = Position;
	SetActorLocation(position);
	//speed = FVector(FMath::RandRange(-maxSpeed, maxSpeed), 0, 0);
	speed = Speed;

	aceleration = Aceleration;

	float scale = FMath::FRandRange(0.1f, 2.0f);
	radius *= scale;

	SetActorScale3D(FVector(radius, radius, radius)/EditorRadius);



	mass = maxMass * radius;


}

// Called when the game starts or when spawned
void ASolid::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASolid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	speed += aceleration * DeltaTime;
	position += speed * DeltaTime;

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


	
}
