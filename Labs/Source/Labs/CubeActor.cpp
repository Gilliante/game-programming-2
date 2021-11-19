// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeActor.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Math/Color.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"

// Sets default values
ACubeActor::ACubeActor()
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
void ACubeActor::BeginPlay()
{
	Super::BeginPlay();

	//Spawn the other two objects
	UWorld* world = GetWorld();
	FVector location = FVector(GetActorLocation().X - 230, GetActorLocation().Y, GetActorLocation().Z - 56);
	FVector location2 = FVector(GetActorLocation().X - 230, GetActorLocation().Y, GetActorLocation().Z - 56); 
	FRotator rotation = GetActorRotation();

	actor = world->SpawnActor(SpawnActor1, &location, &rotation);
	actor2 = world->SpawnActor(SpawnActor2, &location2, &rotation);

	//get actor component -> attachToComponent of VisualMesh component
	actor->GetRootComponent()->AttachToComponent(VisualMesh, FAttachmentTransformRules::KeepRelativeTransform);
	//actor2->GetRootComponent()->AttachToComponent(VisualMesh, FAttachmentTransformRules::KeepRelativeTransform);
	actor2->GetRootComponent()->AttachToComponent(actor->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
}

// Called every frame
void ACubeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!IfPaused)
	{
		FVector NewLocation = GetActorLocation();
		FRotator NewRotation = GetActorRotation();
		float RunningTime = GetGameTimeSinceCreation();

		//Make parent bounce
		float DeltaHeight = FMath::Sin((RunningTime * 2.0f)) * 2.0f;
		NewLocation.Z += DeltaHeight * 5.0f;
		if (NewLocation.Z >= 300.0f)
		{
			NewLocation.Z = 300.0f;
		}
		else if (NewLocation.Z <= 20.0f)
		{
			NewLocation.Z = 20.0f;
		}
		SetActorLocationAndRotation(NewLocation, NewRotation);

		Degrees = (Degrees + 0.1f) + RotationSpeed;

		if (Degrees >= 360.0f)
		{
			Degrees = 0.0f;
		}

		//Set up rotations
		FRotator rotationY = FRotator(0, Degrees, 0);
		FRotator rotationX = FRotator(Degrees, 0, 0);
		rotTransformY = FTransform(rotationY);
		rotTransformX = FTransform(rotationX);

		SetActorRotation(rotTransformY.GetRotation());
		//actor->SetActorRelativeTransform(rotTransform);
		actor->SetActorRotation(rotTransformX.GetRotation());
	}
}

void ACubeActor::PauseMovement(bool key)
{
	//if key is pressed, stop movement if its moving. If not moving, make them move again
	if (key)
	{
		if (IfPaused)
		{
			IfPaused = false;
		}
		else if (!IfPaused)
		{
			IfPaused = true;

			float DegreesPause = Degrees;
			float BouncePause = GetActorLocation().Z;

			FRotator rotationY = FRotator(0, DegreesPause, 0);
			FRotator rotationX = FRotator(DegreesPause, 0, 0);
			rotTransformY = FTransform(rotationY);
			rotTransformX = FTransform(rotationX);

			SetActorRotation(rotTransformY.GetRotation());
			SetActorLocation(FVector(0, 0, BouncePause));
			actor->SetActorRotation(rotTransformX.GetRotation());
		}
	}
}



