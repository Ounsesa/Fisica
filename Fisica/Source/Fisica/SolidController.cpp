// Fill out your copyright notice in the Description page of Project Settings.


#include "SolidController.h"
#include "Solid.h"

// Sets default values
ASolidController::ASolidController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASolidController::BeginPlay()
{
	Super::BeginPlay();

	InitSolidObjects();
	
}

// Called every frame
void ASolidController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckColisions();


}

void ASolidController::InitSolidObjects()
{
	FVector Velocity = FVector(FMath::RandRange(-MaxSpeed, MaxSpeed), FMath::RandRange(-MaxSpeed, MaxSpeed), FMath::RandRange(-MaxSpeed, MaxSpeed));
	FVector Position = GetActorLocation();
	FVector Position2 = Position + Velocity * DistanceBetweenSolids;
	for (int index = 0; index < NumSolidObjects; index++)
	{
		ASolid* Solid = GetWorld()->SpawnActor<ASolid>(SolidActor);
		if (index == 0)
		{
			Solid->Init(Position,Velocity,FVector(0,0,0));
		}
		else
		{
			Solid->Init(Position2, -Velocity, FVector(0, 0, 0));
		}
		SolidList.Push(Solid);
	}

}
void ASolidController::CheckColisions()
{

	for (int index = 0; index < SolidList.Num(); index++)
	{
		ASolid* Solid1 = SolidList[index];
		for (int index2 = index + 1; index2 < SolidList.Num(); index2++)
		{
			ASolid* Solid2 = SolidList[index2];

			FVector Director = Solid1->GetActorLocation() - Solid2->GetActorLocation();
			float Distance = (Director).Size();
			float SumOfRadius = Solid1->GetRadius() + Solid2->GetRadius();
			//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("Distance: %f. Sum: %f"), Distance, SumOfRadius));
			if (Distance <= SumOfRadius)
			{
				float Speed1 = Solid1->GetSpeed().Size();
				float Speed2 = Solid2->GetSpeed().Size();
				float mass1 = Solid1->GetMass();
				float mass2 = Solid2->GetMass();

				float newSpeed2 = (-Speed2 * (mass1 - mass2) + 2 * mass1 * Speed1) / (mass1 + mass2);
				float newSpeed1 = (newSpeed2 + Speed2 - Speed1);

				Director.Normalize();
				Solid1->SetSpeed(Director * newSpeed1);

				Solid2->SetSpeed(-Director * newSpeed2);

				GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("A"));
			}
		}
	}

}