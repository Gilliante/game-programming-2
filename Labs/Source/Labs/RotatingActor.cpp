// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingActor.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Math/Color.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Math/Quat.h"

// Sets default values
ARotatingActor::ARotatingActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	//VisualMesh->SetupAttachment(RootComponent);
	RootComponent = VisualMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (mesh.Succeeded())
	{
		VisualMesh->SetStaticMesh(mesh.Object);
		VisualMesh->SetRelativeLocation(FVector(20.0f, 20.0f, 20.0f));
	}
}

// Called when the game starts or when spawned
void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();
	FVector axis = VisualMesh->GetUpVector();
	Rotation = FQuat(axis, 0.01 * RotationSpeed);
}

// Called every frame
void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(Rotation, false, 0, ETeleportType::None);
}

