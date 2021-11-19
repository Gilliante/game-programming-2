// Fill out your copyright notice in the Description page of Project Settings.


#include "ChildActor.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Math/Color.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

// Sets default values
AChildActor::AChildActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);
	//RootComponent = VisualMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (mesh.Succeeded())
	{
		VisualMesh->SetStaticMesh(mesh.Object);
		VisualMesh->SetRelativeLocation(FVector(20.0f, 20.0f, 20.0f));
	}
}

// Called when the game starts or when spawned
void AChildActor::BeginPlay()
{
	Super::BeginPlay();

	//Spawn the other two objects
	/*UWorld* world = GetWorld();
	FVector location = FVector(GetActorLocation().X - 200, GetActorLocation().Y, GetActorLocation().Z);
	FVector location2 = FVector(GetActorLocation().X - 400, GetActorLocation().Y, GetActorLocation().Z);
	FRotator rotation = GetActorRotation();

	AActor* actor2 = world->SpawnActor(SpawnActor2, &location2, &rotation);

	//get actor component -> attachToComponent of VisualMesh component
	actor2->GetRootComponent()->AttachToComponent(VisualMesh, FAttachmentTransformRules::KeepRelativeTransform);*/
}

// Called every frame
void AChildActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

