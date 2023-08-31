// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

//Input includes
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

#include "ShopCharacter.generated.h"

UCLASS()
class MYPROJECT5_API AShopCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShopCharacter();

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputMappingContext* MappingContext;
	
	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* OpenAction;


	UPROPERTY(EditAnywhere)
	TSubclassOf<class UShopWidget> ShopWidgetClass;

	UPROPERTY()
	class UShopWidget* ShopWidget;
	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SetupInputs();

	void OpenShop();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
