// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "DetailLayoutBuilder.h"
#include "Widgets/Input/NumericTypeInterface.h"

struct FFixed64;

class LOCMODKITEDITOR_API FFixed64Customization  : public IPropertyTypeCustomization
{
	public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	virtual void CustomizeHeader( TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils ) override;
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils) override;

	void FixedValue_OnValueChanged( double InNewValue );
	TOptional<double> GetFixedValue() const;

	TSharedPtr<TNumericUnitTypeInterface<double>> TypeInterface;	
	FFixed64* FixedValue;
	TWeakObjectPtr<UObject> TargetObject;
	TSharedPtr<IPropertyHandle> PropHandle;
};