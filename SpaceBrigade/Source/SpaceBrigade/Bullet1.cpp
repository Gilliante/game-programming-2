// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet1.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Math/Color.h"

// Sets default values
ABullet1::ABullet1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule"));

	if (mesh.Succeeded())
	{
		VisualMesh->SetStaticMesh(mesh.Object);
		//VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		VisualMesh->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
		VisualMesh->SetRelativeScale3D(FVector(0.4, 0.4, 0.4));

		//auto meshMaterial = VisualMesh->GetMaterial(0);

		//color = UMaterialInstanceDynamic::Create(meshMaterial, NULL);
		//color->SetVectorParameterValue(TEXT("Color"), FLinearColor::Green);
		//VisualMesh->SetMaterial(0, color);
	}
}

// Called when the game starts or when spawned
void ABullet1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

