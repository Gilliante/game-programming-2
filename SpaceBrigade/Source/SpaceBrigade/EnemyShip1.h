// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyShip1.generated.h"

UCLASS()
class SPACEBRIGADE_API AEnemyShip1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyShip1();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

	UPROPERTY(VisibleAnywhere)
	UMaterialInstanceDynamic* color;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
