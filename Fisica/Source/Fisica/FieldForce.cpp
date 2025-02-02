// Fill out your copyright notice in the Description page of Project Settings.


#include "FieldForce.h"
#include "Solid.h"

// Sets default values
AFieldForce::AFieldForce()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFieldForce::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFieldForce::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFieldForce::NotifyActorBeginOverlap(AActor* OtherActor)
{
	ASolid* Solid = Cast<ASolid>(OtherActor);
	if (Solid)
	{
		Solid->AddForceField(this);
	}
}

void AFieldForce::NotifyActorEndOverlap(AActor* OtherActor)
{
	ASolid* Solid = Cast<ASolid>(OtherActor);
	if (Solid)
	{
		Solid->RemoveForceField(this);
	}
}

