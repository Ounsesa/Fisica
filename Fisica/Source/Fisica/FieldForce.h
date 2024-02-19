// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FieldForce.generated.h"

UCLASS()
class FISICA_API AFieldForce : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFieldForce();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Force)
		float Force;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Force)
		FVector Direction;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

};
