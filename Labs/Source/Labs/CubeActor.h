// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeActor.generated.h"

UCLASS()
class LABS_API ACubeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubeActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> SpawnActor1;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> SpawnActor2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CubeActor")
	float RotationSpeed = 1.0f;

	float Degrees = 0.0f;
	AActor* actor;
	AActor* actor2;

	FTransform rotTransformY;
	FTransform rotTransformX;

	bool IfPaused = false;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//blueprint function to stop and start rotation
	UFUNCTION(BlueprintCallable, Category = "PauseMovement")
		void PauseMovement(bool key);
};
