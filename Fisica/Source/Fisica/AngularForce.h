// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AngularForce.generated.h"

class AParticle;

UCLASS()
class FISICA_API AAngularForce : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAngularForce();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AngularForce")
		float Force = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AngularForce")
		bool Reverse = false;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AngularForce")
	FVector AngularDirection;


	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
