// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
//#include "Camera/CameraComponent.h"
#include "FlyingPawn.generated.h"

UCLASS()
class LABS_API AFlyingPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFlyingPawn();

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* VisualMesh;

	//UPROPERTY(VisibleAnywhere)
	//UCameraComponent* PlayerCamera;

	FQuat HorizontalRotation;
	FQuat VerticalRotation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Input functions
	void MoveForward(float AxisValue);
	void MoveLeft(float AxisValue);
	void MoveUp(float AxisValue);
};
