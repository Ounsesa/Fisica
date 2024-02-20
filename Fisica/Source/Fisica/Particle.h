// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particle.generated.h"

class AFieldForce;
class ACircularForce;

UCLASS()
class FISICA_API AParticle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParticle();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Particle)
		float TimeBeforeDespawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Particle)
		int maxSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Particle)
		int maxAceleration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Particle)
		int maxMass;

	

	bool ParticleActive = false;

	void SetActiveParticle();

	void AddForce(FVector newForce);

	int GetMass() { return mass; }

	void AddForceField(AFieldForce* _FieldForce);

	void AddCircularForce(ACircularForce* _CircularForce);

	void RemoveForceField(AFieldForce* _FieldForce);

	void RemoveCircularForce(ACircularForce* _CircularForce);

	void AddImpulse(FVector Impulse);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Init(FVector Position);

protected:

	FVector spawnPosition;

	FVector position;
	FVector speed;
	FVector aceleration;

	float DespawnTimer;
	int mass;

	TArray<AFieldForce*> FieldForces;
	TArray<ACircularForce*> CircularForces;


};
