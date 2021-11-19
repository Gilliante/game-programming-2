// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyShip1.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Math/Color.h"

// Sets default values
AEnemyShip1::AEnemyShip1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone"));

	if (mesh.Succeeded())
	{
		VisualMesh->SetStaticMesh(mesh.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		VisualMesh->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));

		auto meshMaterial = VisualMesh->GetMaterial(0);

		color = UMaterialInstanceDynamic::Create(meshMaterial, NULL);
		color->SetVectorParameterValue(TEXT("Color"), FLinearColor::Red);
		VisualMesh->SetMaterial(0, color);
	}
}

// Called when the game starts or when spawned
void AEnemyShip1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyShip1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

