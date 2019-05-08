// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BUILDESCAPE_API UGrabber : public UActorComponent
{
  GENERATED_BODY()

public:
  // Sets default values for this component's properties
  UGrabber();

protected:
  // Called when the game starts
  virtual void BeginPlay() override;

public:
  // Called every frame
  virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

private:
  // How far ahead of the player can we reach in cm
  float Reach = 100.f;

  UPhysicsHandleComponent *PhysicsHandle = nullptr;

  UInputComponent *InputComponent = nullptr;

  void Grab();

  void Release();

  void FindPhysicsHandleComponent();

  void SetupInputComponent();

  const FHitResult GetFirstPhysicsBodyInReach();

  FVector GetReachLineStart();

  FVector GetReachLineEnd();
};
