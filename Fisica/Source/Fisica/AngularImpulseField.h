// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AngularImpulseField.generated.h"

UCLASS()
class FISICA_API AAngularImpulseField : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAngularImpulseField();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Force)
		float Impulse;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Force)
		FVector AngularDirection;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
