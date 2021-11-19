// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Math/Color.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"

// Sets default values
AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	
	//Spawn the other two objects
	UWorld* world = GetWorld();
	FVector location = FVector(1500, -1500, -4000);
	FVector location2 = FVector(-3000, -10000, -3000);
	FVector location3 = FVector(20000, 0, 10000);
	FVector location4 = FVector(-2000, 4000, -6000);
	FVector location5 = FVector(10000, 8000, 9000);
	FRotator rotation = FRotator(0, 0, 0);

	world->SpawnActor(Enemy1, &location, &rotation);
	world->SpawnActor(Enemy1, &location2, &rotation);
	world->SpawnActor(Enemy1, &location3, &rotation);
	world->SpawnActor(Enemy1, &location4, &rotation);
	world->SpawnActor(Enemy1, &location5, &rotation);

	enemyCount = 5;
}

// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//move enemy ships around
	//check if any enemy ships have collisions. If so, decrease enemy count and destroy them

	//FVector newTransform = actor->GetActorLocation();
	//actor->SetActorLocation(rotTransformX.GetRotation());
}

bool AGameManager::IsEnemyHit(bool isHit)
{
	if (isHit == true)
	{
		enemyCount -= 1;
		return true;
	}
	return false;
}

int AGameManager::GetEnemyCount()
{
	return enemyCount;
}

