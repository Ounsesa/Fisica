// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Particle.h"
#include "RotationParticle.generated.h"

class AAngularForce;

/**
 * 
 */
UCLASS()
class FISICA_API ARotationParticle : public AParticle
{
	GENERATED_BODY()
public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rotation)
		float Roll;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rotation)
		float Pitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rotation)
		float Yaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rotation)
		float MaxRollSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rotation)
		float MaxPitchSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rotation)
		float MaxYawSpeed;



	void AddAngularForce(AAngularForce* _AngularForce);

	void RemoveAngularField(AAngularForce* _AngularForce);


	void AddAngularImpulse(FVector AngularImpulse);

private:

	FVector AngularPosition;
	FVector AngularSpeed;
	FVector AngularAcceleration;

	float Inertia;

	TArray<AAngularForce*> AngularForces;

	// Torque = Inercia * Aceleracion angular
	// Fuerza angular


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Init(FVector Position) override;
};
