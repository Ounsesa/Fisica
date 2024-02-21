// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Solid.generated.h"

class AFieldForce;
class ACircularForce;

class AAngularForce;

UCLASS()
class FISICA_API ASolid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASolid();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Particle)
		int maxSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Particle)
		int maxAceleration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Particle)
		int maxMass;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Particle)
	float radius;

	


	
	int GetMass() { return mass; }

	float GetRadius() { return radius; }

	void AddForceField(AFieldForce* _FieldForce);

	void AddCircularForce(ACircularForce* _CircularForce);

	void RemoveForceField(AFieldForce* _FieldForce);

	void RemoveCircularForce(ACircularForce* _CircularForce);

	void AddImpulse(FVector Impulse);
	
	void Init(FVector Position, FVector Speed, FVector Aceleration);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;	

	FVector position;
	FVector speed;
	FVector aceleration;

	int mass;

	float EditorRadius = 50;

	
	TArray<AFieldForce*> FieldForces;
	TArray<ACircularForce*> CircularForces;
};
