// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyingPawn.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Math/Color.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Math/Quat.h"
#include "Components/InputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Camera/CameraComponent.h"

// Sets default values
AFlyingPawn::AFlyingPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (mesh.Succeeded())
	{
		VisualMesh->SetStaticMesh(mesh.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 60.0f));
		VisualMesh->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));

		// Create a camera and a visible object
		UCameraComponent* PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
		// Attach our camera and visible object to our root component. Offset and rotate the camera.
		PlayerCamera->SetupAttachment(VisualMesh);
		PlayerCamera->SetRelativeLocation(FVector(-300.0f, 0.0f, 150.0f));
		PlayerCamera->SetRelativeRotation(FRotator(-20.0f, 0.0f, 0.0f));
	}
}

// Called when the game starts or when spawned
void AFlyingPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFlyingPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//PlayerCamera->SetRelativeLocation(FVector(GetActorLocation()));

	AddActorLocalRotation(HorizontalRotation, false, 0, ETeleportType::None);
	AddActorLocalRotation(VerticalRotation, false, 0, ETeleportType::None);
}

// Called to bind functionality to input
void AFlyingPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// you should really NOT do this in Pawn, but in a Controller for reusability and SE purposes
	Super::SetupPlayerInputComponent(InputComponent);

	// now bind stuff, note that we can simply use InputComponent, because we
	// inherit this from AActor, and it will have been created by now (well we hope)
	check(InputComponent);

	// bind our axis
	InputComponent->BindAxis("Forward", this, &AFlyingPawn::MoveForward);
	InputComponent->BindAxis("LeftRight", this, &AFlyingPawn::MoveLeft);
	InputComponent->BindAxis("UpDown", this, &AFlyingPawn::MoveUp);	
}

void AFlyingPawn::MoveForward(float AxisValue)
{
	UPawnMovementComponent* OurMovementComponent = GetMovementComponent();

	if (AxisValue == 1.0f)
	{
		/*if (OurMovementComponent && (OurMovementComponent->UpdatedComponent == RootComponent))
		{
			OurMovementComponent->AddInputVector(GetActorForwardVector() * AxisValue);
		}*/

		AddActorLocalOffset(FVector(1.0f + (AxisValue * 2.0f), 0.0f, 0.0f)); //GetActorForwardVector().X + AxisValue * 2.0f, GetActorForwardVector().Y, GetActorForwardVector().Z));
	}
}

void AFlyingPawn::MoveLeft(float AxisValue)
{
	FVector LeftAxis = FVector(0.0f, 0.0f, 1.0f);//VisualMesh->GetUpVector();
	if (AxisValue != 0.0f)
	{		
		HorizontalRotation = FQuat(LeftAxis, AxisValue / 30);
	}
	else
	{
		HorizontalRotation = FQuat(FVector(0.0f, 0.0f, 0.0f), 0.0f);
	}
}

void AFlyingPawn::MoveUp(float AxisValue)
{
	FVector UpAxis = FVector(0.0f, 1.0f, 0.0f);//VisualMesh->GetRightVector();
	if (AxisValue != 0.0f)
	{
		VerticalRotation = FQuat(UpAxis, AxisValue / 30);
	}
	else
	{
		VerticalRotation = FQuat(FVector(0.0f, 0.0f, 0.0f), 0.0f);
	}
}


