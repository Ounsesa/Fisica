// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnerActor.generated.h"

class AParticle;

UCLASS()
class FISICA_API ASpawnerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnerActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Particle)
		int MaxParticleNumbers;	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Particle)
		float TimeBetweenSpawns;

	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Particle)
		TSubclassOf<AParticle> ParticleActor;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	TArray<AParticle*> ParticlePool;

	float SpawnTimer = 0;

	int ParticleIndex = 0;

};
