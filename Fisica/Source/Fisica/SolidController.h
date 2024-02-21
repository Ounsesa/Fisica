// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SolidController.generated.h"

class ASolid;

UCLASS()
class FISICA_API ASolidController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASolidController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Solid)
		TSubclassOf<ASolid> SolidActor;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Solid)
		float DistanceBetweenSolids;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Solid)
		float MaxSpeed;





	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TArray<ASolid*> SolidList;

	int NumSolidObjects = 2;


	void InitSolidObjects();
	void CheckColisions();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
