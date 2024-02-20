// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Particle.h"
#include "RotateParticle.generated.h"

/**
 * 
 */
UCLASS()
class FISICA_API ARotateParticle : public AParticle
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



	FVector AngularPosition;
	FVector AngularSpeed;
	FVector AngularAcceleration;

	float Inertia = 2 * mass / 5;






public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Init(FVector Position);
	
};
