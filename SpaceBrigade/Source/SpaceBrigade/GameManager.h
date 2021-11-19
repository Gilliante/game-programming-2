// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameManager.generated.h"

UCLASS()
class SPACEBRIGADE_API AGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameManager();

	UPROPERTY(EditAnywhere)
	TSubclassOf<APawn> Enemy1;
	/*UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> Enemy2;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int enemyCount;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "IsEnemyHit")
		bool IsEnemyHit(bool isHit);

	UFUNCTION(BlueprintCallable, Category = "GetEnemyCount")
		int GetEnemyCount();

};
