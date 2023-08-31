// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopCharacter.h"

#include "Blueprint/UserWidget.h"
#include "ShopUI/ShopWidget.h"

// Sets default values
AShopCharacter::AShopCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShopWidget = nullptr;
	ShopWidgetClass = nullptr;
}

// Called when the game starts or when spawned
void AShopCharacter::BeginPlay()
{
	Super::BeginPlay();

	M_PlayerWallet = new PlayerWallet(5000, 5000);
	
	SetupInputs();
}

void AShopCharacter::SetupInputs()
{
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}
}

void AShopCharacter::OpenShop()
{
	UE_LOG(LogTemp, Warning, TEXT("Trying to open shop."))
	if (IsLocallyControlled())
	{
		APlayerController* PlayerController = Cast<APlayerController>(Controller);
		if (ShopWidgetClass)
		{
			check(PlayerController);
			ShopWidget = CreateWidget<UShopWidget>(PlayerController, ShopWidgetClass);
			check(ShopWidget);
			ShopWidget->AddToPlayerScreen();
			ShopWidget->SetVisibility(ESlateVisibility::Visible);
			
			UE_LOG(LogTemp, Warning, TEXT("Opened shop"))

			PlayerController->SetInputMode(FInputModeUIOnly());

			//Create shop system,
			M_ShopSystem = NewObject<UShopSystem>();
			M_ShopSystem->SetWallet(M_PlayerWallet);

			//Setup widget with system.
			ShopWidget->Setup(M_ShopSystem, M_PlayerWallet->GetGold());

		}
	}

	
}

// Called every frame
void AShopCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShopCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(OpenAction, ETriggerEvent::Started, this, &AShopCharacter::OpenShop);
	}

}

PlayerWallet* AShopCharacter::GetPlayerWallet()
{
	return M_PlayerWallet;
}

