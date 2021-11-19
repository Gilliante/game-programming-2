// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncePawn.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Math/Color.h"

// Sets default values
ABouncePawn::ABouncePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));

	if (mesh.Succeeded())
	{
		VisualMesh->SetStaticMesh(mesh.Object);
		VisualMesh->SetRelativeLocation(FVector(25.0f, 25.0f, 25.0f));
	}
}

// Called when the game starts or when spawned
void ABouncePawn::BeginPlay()
{
	Super::BeginPlay();
	
	auto meshMaterial = VisualMesh->GetMaterial(0);

	color = UMaterialInstanceDynamic::Create(meshMaterial, NULL);
	color->SetVectorParameterValue(TEXT("Color"), FLinearColor::Blue);
	VisualMesh->SetMaterial(0, color);
}

// Called every frame
void ABouncePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	float RunningTime = GetGameTimeSinceCreation();

	float DeltaHeight = FMath::Sin((RunningTime * MaxSpeed)) * MaxSpeed;
	NewLocation.Z += DeltaHeight * 5.0f;      
	if (NewLocation.Z >= MaxDistance)
	{
		NewLocation.Z = MaxDistance;
	}
	else if (NewLocation.Z <= 20.0f) 
	{
		NewLocation.Z = 20.0f;
	}
	SetActorLocationAndRotation(NewLocation, NewRotation);
	
	//(FMath::Sin((DeltaTime + NewLocation.X) * MaxSpeed)) - FMath::Sin((NewLocation.X) * MaxSpeed); //(FMath::Sin((RunningTime + DeltaTime) * MaxSpeed) - FMath::Sin(RunningTime * MaxSpeed)); 
	//FMath::Sin(DeltaTime * MaxSpeed) - FMath::Sin(MaxSpeed);
	//float DeltaRotation = DeltaTime * 20.0f;    //Rotate by 20 degrees per second
	//NewRotation.Yaw += DeltaRotation;
	
}

// Called to bind functionality to input
void ABouncePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

