// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Widget/BSInput.h"
#include "BSPlayerController.generated.h"

class UBSInput;

/**
 * 
 */
UCLASS()
class HW09_API ABSPlayerController : public APlayerController
{
	GENERATED_BODY()


public:
	virtual void BeginPlay() override;

	void SetChatMessageString(const FString& InChatMessageString);
	
	void PrintChatMessageString(const FString& InChatMessageString);
	
	UFUNCTION(Client, Reliable)
	void ClientRPCPrintChatMessageString(const FString& InChatMessageString);
    
	UFUNCTION(Server, Reliable)
	void ServerRPCPrintChatMessageString(const FString& InChatMessageString);
	
protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UBSInput> ChatInputWidgetClass;
	
	UPROPERTY()
	TObjectPtr<UBSInput> ChatInputWidgetInstance;
	
	FString ChatMessageString;

};
