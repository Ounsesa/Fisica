// Fill out your copyright notice in the Description page of Project Settings.


#include "AngularForce.h"
#include "RotationParticle.h"

// Sets default values
AAngularForce::AAngularForce()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAngularForce::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAngularForce::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAngularForce::NotifyActorBeginOverlap(AActor* OtherActor)
{
	ARotationParticle* Particle = Cast<ARotationParticle>(OtherActor);
	if (Particle)
	{
		Particle->AddAngularForce(this);
	}
}

void AAngularForce::NotifyActorEndOverlap(AActor* OtherActor)
{
	ARotationParticle* Particle = Cast<ARotationParticle>(OtherActor);
	if (Particle)
	{
		Particle->RemoveAngularField(this);
	}
}
