// Fill out your copyright notice in the Description page of Project Settings.


#include "GameState/BSGameState.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerController/BSPlayerController.h"


void ABSGameState::MulticastRPCBroadcastLoginMessage_Implementation(const FString& InNameString)
{
	if (HasAuthority() == false)
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		if (IsValid(PC) == true)
		{
			ABSPlayerController* BSPC = Cast<ABSPlayerController>(PC);
			if (IsValid(BSPC) == true)
			{
				FString NotificationString = InNameString + TEXT(" has joined the game.");
				BSPC->PrintChatMessageString(NotificationString);
			}
		}
	}
}