// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/EcUserWidget.h"

void UEcUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
