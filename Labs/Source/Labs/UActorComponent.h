// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LABS_API UUActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUActorComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scene Hierarchy")
		AActor* parent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scene Hierarchy")
		TArray<AActor*> children;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scene Hierarchy")
	FTransform LocalTransform;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "ChangeTranslation")
		void ChangeTranslation(FVector newLocation);

	UFUNCTION(BlueprintCallable, Category = "ChangeRotation")
		void ChangeRotation(FQuat newRotation);

	UFUNCTION(BlueprintCallable, Category = "ChangeScale")
		void ChangeScale(FVector newScale);
};
