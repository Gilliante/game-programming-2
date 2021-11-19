// Fill out your copyright notice in the Description page of Project Settings.


#include "UActorComponent.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Math/TransformNonVectorized.h"

// Sets default values for this component's properties
UUActorComponent::UUActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.

	// Register component and set it up to recieve ticks
	RegisterComponent();
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}


// Called when the game starts
void UUActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// if it has no parent, then you initialize it to be the transform of the actor on which this component is connect to. 
	//if it has a parent, don't initialize it to anything.

	if (parent == nullptr)
	{
		LocalTransform = GetOwner()->GetTransform();
	}
	else
	{
		LocalTransform = FTransform::Identity; //FTransform(GetOwner()->GetActorLocation()); //- parent->GetActorLocation());
	}
	
	//LocalTransform = GetOwner()->GetTransform();
}


// Called every frame
void UUActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// adjust the FTransform of the children by the parent's FTransform so that you have a scene hierarch

	//mulitply them by the FTransform::Identity if have parent, mulitply up the chain
		/*for (auto& child : children)
		{
			//multiply childs by its parent
			//set actor transform to this
			/*if (parent != nullptr)
			{
				thisChild = child;
				FTransform newTransform;
				FTransform::Multiply(&newTransform, &Cast<UUActorComponent>(thisChild->GetComponentByClass(UUActorComponent::StaticClass()))->LocalTransform, &parent->GetTransform());
				child->SetActorTransform(newTransform);
				//thisChild->SetActorTransform(newTransform);
				//child = thisChild;
			}
			else
			{
				thisChild = child;
				//FTransform newTransform
				FTransform newTransform = Cast<UUActorComponent>(thisChild->GetComponentByClass(UUActorComponent::StaticClass()))->LocalTransform;
				child->SetActorTransform(newTransform);
				//thisChild->SetActorTransform(newTransform);
				//child = thisChild;
			}
		}*/

		for (auto& child : children)
		{
			//multiply children's transform by its parent's

			FTransform newTransform;
			FTransform::Multiply(&newTransform, &Cast<UUActorComponent>(child->GetComponentByClass(UUActorComponent::StaticClass()))->LocalTransform, &LocalTransform);
			child->SetActorTransform(newTransform);
		}

		//set actor transform if no parent exists
		if (parent == nullptr)
		{
			GetOwner()->SetActorTransform(LocalTransform);
		}
}

//change the local transform using these methods
void UUActorComponent::ChangeTranslation(FVector newLocation)
{
	LocalTransform.SetTranslation(newLocation);
}

void UUActorComponent::ChangeRotation(FQuat newRotation)
{
	LocalTransform.SetRotation(newRotation);
}

void UUActorComponent::ChangeScale(FVector newScale)
{
	LocalTransform.SetScale3D(newScale);
}


