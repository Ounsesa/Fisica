// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CircularForce.generated.h"

class ASolid;

UCLASS()
class FISICA_API ACircularForce : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACircularForce();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CircularForce")
	float Force = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CircularForce")
	bool Reverse = false;


	TMap<ASolid*, FVector> SolidForceDirections;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	FVector GetForceDirection(ASolid* Particle);

};
