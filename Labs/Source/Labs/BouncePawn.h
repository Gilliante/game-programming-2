// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BouncePawn.generated.h"

UCLASS()
class LABS_API ABouncePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABouncePawn();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BouncePawn")
	float MaxSpeed = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BouncePawn")
	float MaxDistance = 500.0f;

	//FLinearColor color = FLinearColor(1.0f, 0.0f, 0.0f, 1.0f);
	UPROPERTY(VisibleAnywhere)
	UMaterialInstanceDynamic* color;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
