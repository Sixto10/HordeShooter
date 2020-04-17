// Fill out your copyright notice in the Description page of Project Settings.

#include "SProyectileWeapon.h"

void ASProyectileWeapon::Fire()
{
	AActor* MyOwner = GetOwner();

	if (MyOwner && ProyectileClass)
	{
		FVector EyeLocation;
		FRotator EyeRotation;
		MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

		FVector MuzzleLocation = MeshComp->GetSocketLocation(MuzzleSocketName);
		
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		GetWorld()->SpawnActor<AActor>(ProyectileClass, MuzzleLocation, EyeRotation, SpawnParams);
			

	}
}