// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.generated.h"

UCLASS()
class LABS_API ARotatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotatingActor();

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* VisualMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotatingActor")
		float RotationSpeed = 0.3f;

	FQuat Rotation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
