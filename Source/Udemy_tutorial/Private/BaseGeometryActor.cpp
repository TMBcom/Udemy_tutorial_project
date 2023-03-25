// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY_STATIC(ConmiroLog, All, All)

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();
	printTypes();
}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ABaseGeometryActor::printTypes()
{
	UE_LOG(ConmiroLog, Warning, TEXT("Actor name %s"), *GetName());
	UE_LOG(ConmiroLog, Warning, TEXT("Weapons num: %d, kills num: %i"), WeaponsNum, KillsNum);
	UE_LOG(ConmiroLog, Warning, TEXT("Health: %f"), Health);
	UE_LOG(ConmiroLog, Warning, TEXT("IsDead: %d"), IsDead);
	UE_LOG(ConmiroLog, Warning, TEXT("HasWeapon: %d"), static_cast<int>(HasWeapon));
	
}

void ABaseGeometryActor::printStringTypes()
{
	FString Name = "Conmiro";
	UE_LOG(ConmiroLog, Display, TEXT("Hello %s"), *Name);
	FString WeaponsNumStr = "Weapons num = " + FString::FromInt(WeaponsNum);
	FString HealthStr = "Health = " + FString::SanitizeFloat(Health);
	FString IsDeadStr = "Is dead = " + FString(IsDead ? "true": "false");

	FString Stat = FString::Printf(TEXT("\n == All Stat == \n %s \n%s \n%s "), *WeaponsNumStr, *HealthStr, *IsDeadStr);
	UE_LOG(ConmiroLog, Warning, TEXT("%s"), *Stat);

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, Name);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Stat, true, FVector2D(1.5f, 1.5f));
}