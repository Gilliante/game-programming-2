// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChildActor.generated.h"

UCLASS()
class LABS_API AChildActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChildActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

	/*UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> SpawnActor2;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChildActor")
	float RotationSpeed = 2.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
