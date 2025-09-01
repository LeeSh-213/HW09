// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/BSPlayerController.h"
#include "Widget/BSInput.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameMode/BSGameModeBase.h"
#include "Player/BSPlayerState.h"
#include "Net/UnrealNetwork.h"


ABSPlayerController::ABSPlayerController()
{
	bReplicates = true;
}

void ABSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocalController() == false)
	{
		return;
	}
	
	FInputModeUIOnly InputModeUIOnly;
	SetInputMode(InputModeUIOnly);

	if (IsValid(ChatInputWidgetClass) == true)
	{
		ChatInputWidgetInstance = CreateWidget<UBSInput>(this, ChatInputWidgetClass);
		if (IsValid(ChatInputWidgetInstance) == true)
		{
			ChatInputWidgetInstance->AddToViewport();
		}
	}

	if (IsValid(NotificationTextWidgetClass) == true)
	{
		NotificationTextWidgetInstance = CreateWidget<UUserWidget>(this, NotificationTextWidgetClass);
		if (IsValid(NotificationTextWidgetInstance) == true)
		{
			NotificationTextWidgetInstance->AddToViewport();
		}
	}
	
}

void ABSPlayerController::SetChatMessageString(const FString& InChatMessageString)
{

	ChatMessageString = InChatMessageString;
	
	if (IsLocalController() == true)
	{

		ABSPlayerState* PS = GetPlayerState<ABSPlayerState>();
		if (IsValid(PS) == true)
		{
			FString CombinedMessageString = PS->GetPlayerInfoString() + TEXT(": ") + InChatMessageString;

			ServerRPCPrintChatMessageString(CombinedMessageString);
		}
	}
}

void ABSPlayerController::PrintChatMessageString(const FString& InChatMessageString)
{
	UKismetSystemLibrary::PrintString(this, InChatMessageString, true, true, FLinearColor::Red, 5.0f);
}

void ABSPlayerController::ClientRPCPrintChatMessageString_Implementation(const FString& InChatMessageString)
{
	PrintChatMessageString(InChatMessageString);
}

void ABSPlayerController::ServerRPCPrintChatMessageString_Implementation(const FString& InChatMessageString)
{

	AGameModeBase* GM = UGameplayStatics::GetGameMode(this);
	if (IsValid(GM) == true)
	{
		ABSGameModeBase* BSGM = Cast<ABSGameModeBase>(GM);
		if (IsValid(BSGM) == true)
		{
			BSGM->PrintChatMessageString(this, InChatMessageString);
		}
	}
}

void ABSPlayerController::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, NotificationText);
}