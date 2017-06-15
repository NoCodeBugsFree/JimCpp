// Fill out your copyright notice in the Description page of Project Settings.

#include "JimCpp.h"
#include "JimCppPlayerController.h"

AJimCppPlayerController::AJimCppPlayerController()
{
	AutoReceiveInput       = EAutoReceiveInput::Player0;
	bShowMouseCursor	   = true;
	bEnableClickEvents     = true;
	bEnableTouchEvents     = true;
	bEnableMouseOverEvents = true;
	bEnableTouchOverEvents = true;

	DefaultClickTraceChannel = ECollisionChannel::ECC_WorldDynamic;

	bAutoManageActiveCameraTarget = false;

}
