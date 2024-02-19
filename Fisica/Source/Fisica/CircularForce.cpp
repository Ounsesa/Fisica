// Fill out your copyright notice in the Description page of Project Settings.


#include "CircularForce.h"

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

}

