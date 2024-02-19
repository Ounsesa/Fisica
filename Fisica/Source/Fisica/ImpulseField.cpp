// Fill out your copyright notice in the Description page of Project Settings.


#include "ImpulseField.h"
#include "Particle.h"

// Sets default values
AImpulseField::AImpulseField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AImpulseField::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AImpulseField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AImpulseField::NotifyActorBeginOverlap(AActor* OtherActor)
{
	AParticle* Particle = Cast<AParticle>(OtherActor);
	if (Particle)
	{
		Particle->AddImpulse(Impulse*Direction);
	}
}

