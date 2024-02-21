// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Solid.h"
#include "Particle.generated.h"

class AFieldForce;
class ACircularForce;

UCLASS()
class FISICA_API AParticle : public ASolid
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParticle();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Particle)
		float TimeBeforeDespawn;

	

	bool ParticleActive = false;

	void SetActiveParticle();

	virtual void Init(FVector Position);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	FVector spawnPosition;

	float DespawnTimer;
};
