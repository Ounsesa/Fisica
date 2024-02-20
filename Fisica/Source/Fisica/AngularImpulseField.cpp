// Fill out your copyright notice in the Description page of Project Settings.


#include "AngularImpulseField.h"
#include "RotationParticle.h"

// Sets default values
AAngularImpulseField::AAngularImpulseField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAngularImpulseField::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAngularImpulseField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAngularImpulseField::NotifyActorBeginOverlap(AActor* OtherActor)
{
	ARotationParticle* Particle = Cast<ARotationParticle>(OtherActor);
	if (Particle)
	{
		Particle->AddAngularImpulse(Impulse * AngularDirection);
	}
}

