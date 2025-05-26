// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Input/NumericTypeInterface.h"

#include "DetailLayoutBuilder.h"

struct FFixed;
/**
 * 
 */
class LOCMODKITEDITOR_API FFixedCustomization  : public IPropertyTypeCustomization
{
	public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	virtual void CustomizeHeader( TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils ) override;
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils) override;

	void FixedValue_OnValueChanged( float InNewValue );
	TOptional<float> GetFixedValue() const;

	TSharedPtr<TNumericUnitTypeInterface<float>> TypeInterface;	
	FFixed* FixedValue;
	TWeakObjectPtr<UObject> TargetObject;
	TSharedPtr<IPropertyHandle> PropHandle;
};