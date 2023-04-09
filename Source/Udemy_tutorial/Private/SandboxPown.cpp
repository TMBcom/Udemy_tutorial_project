// Fill out your copyright notice in the Description page of Project Settings.


#include "SandboxPown.h"
//�������� � �������
#include <Components/InputComponent.h>

DEFINE_LOG_CATEGORY_STATIC(PownLog, All, All)
// Sets default values
ASandboxPown::ASandboxPown()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

}

// Called when the game starts or when spawned
void ASandboxPown::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASandboxPown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//�������� � �������
	if(!VelocityVector.IsZero())
	{ 
		//�������� � �������
		const FVector NewLocation = GetActorLocation() + Velocity * DeltaTime * VelocityVector;
		SetActorLocation(NewLocation);
	}

}

// Called to bind functionality to input
void ASandboxPown::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	//�������� � �������
	PlayerInputComponent->BindAxis("MoveForward", this, &ASandboxPown::MoveForward);
	//�������� � �������
	PlayerInputComponent->BindAxis("MoveRight", this, &ASandboxPown::MoveRight);

}

void ASandboxPown::MoveForward(float Amount)
{
	UE_LOG(PownLog, Display, TEXT("Move forward: %f"), Amount);
	//�������� � �������
	VelocityVector.X = Amount;
}

void ASandboxPown::MoveRight(float Amount)
{
	UE_LOG(PownLog, Display, TEXT("Move right: %f"), Amount);
	VelocityVector.Y = Amount;
}

