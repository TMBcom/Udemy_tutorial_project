// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"
#include "Engine/Engine.h"
#include <Materials/MaterialInstanceDynamic.h>

DEFINE_LOG_CATEGORY_STATIC(ConmiroLog, All, All)

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("ConmiroMesh");
	SetRootComponent(BaseMesh);


}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();
	InitlocationConmiro = GetActorLocation();
	InitRotationConmiro = GetActorRotation();
	SetColor(GeometryDataCon.Color);
	//printTransform();
	//printTypes();
	//printStringTypes();

}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (GeometryDataCon.MoveType)
	{
	case EMovementTypeConmiro::Sin:
	{
		//z = z0 + A * sin(freq * time);
		FVector CurrentLocationConmiro = GetActorLocation();
		FRotator CurrentRotationConmiro = GetActorRotation();
		float time = GetWorld()->GetTimeSeconds();
		CurrentLocationConmiro.Z = InitlocationConmiro.Z + GeometryDataCon.Amplitude *
			FMath::Sin(GeometryDataCon.Frequency * time);
		CurrentRotationConmiro.Yaw = (InitRotationConmiro.Yaw +
			GeometryDataCon.Rotate * time);

		SetActorRotation(CurrentRotationConmiro);
		SetActorLocation(CurrentLocationConmiro);
	}
	break;

	case EMovementTypeConmiro::Static:break;
	default:break;
	}


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
	FString IsDeadStr = "Is dead = " + FString(IsDead ? "true" : "false");

	FString Stat = FString::Printf(TEXT("\n == All Stat == \n %s \n%s \n%s "), *WeaponsNumStr, *HealthStr, *IsDeadStr);
	UE_LOG(ConmiroLog, Warning, TEXT("%s"), *Stat);

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, Name);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Stat, true, FVector2D(1.5f, 1.5f));
}
void ABaseGeometryActor::printTransform() {
	FTransform TransformConmiro = GetActorTransform();
	FVector LocationConmiro = TransformConmiro.GetLocation();
	FRotator RotatorConmiro = TransformConmiro.Rotator();
	FVector ScaleConmiro = TransformConmiro.GetScale3D();

	UE_LOG(ConmiroLog, Warning, TEXT("Actor name %s"), *GetName());
	UE_LOG(ConmiroLog, Warning, TEXT("Actor transform %s"), *TransformConmiro.ToString());
	UE_LOG(ConmiroLog, Warning, TEXT("Actor location %s"), *LocationConmiro.ToString());
	UE_LOG(ConmiroLog, Warning, TEXT("Actor rotation %s"), *RotatorConmiro.ToString());
	UE_LOG(ConmiroLog, Warning, TEXT("Actor scale %s"), *ScaleConmiro.ToString());

	UE_LOG(ConmiroLog, Error, TEXT("Actor another display transform %s"),
		*TransformConmiro.ToHumanReadableString());
}

void ABaseGeometryActor::SetColor(const FLinearColor& Color)
{
	UMaterialInstanceDynamic* DynMaterial = BaseMesh->CreateAndSetMaterialInstanceDynamic(0);
	if (DynMaterial) {
		DynMaterial->SetVectorParameterValue("Conmiro", Color);
	}
}
