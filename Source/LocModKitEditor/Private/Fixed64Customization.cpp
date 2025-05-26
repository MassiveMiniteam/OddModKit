// Fill out your copyright notice in the Description page of Project Settings.


#include "Fixed64Customization.h"
#include "DetailWidgetRow.h"
#include "Fixed64.h"
#include "PropertyHandle.h"
#include "IDetailChildrenBuilder.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Math/UnitConversion.h"
#include "Widgets/Input/SNumericEntryBox.h"
#include "Widgets/Input/NumericTypeInterface.h"
#include "Widgets/Input/NumericUnitTypeInterface.inl"

#define LOCTEXT_NAMESPACE "FixedCustomization"

TSharedRef<IPropertyTypeCustomization> FFixed64Customization::MakeInstance()
{
	return MakeShareable(new FFixed64Customization());
}

void FFixed64Customization::CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	
}

void FFixed64Customization::CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	void* Value = nullptr;
	PropertyHandle->GetValueData(Value);
	PropHandle = PropertyHandle;
	
	FFixed64* Fixed = static_cast<FFixed64*>(Value);
	FixedValue = Fixed;

	const FString& ForcedUnits = PropertyHandle->GetMetaData(TEXT("ForceUnits"));
	auto PropertyUnits = FUnitConversion::UnitFromString(*ForcedUnits);
	if (PropertyUnits.IsSet())
	{
		// Create the type interface and set up the default input units if they are compatible
		TypeInterface = MakeShareable(new TNumericUnitTypeInterface<double>(PropertyUnits.GetValue()));
		TypeInterface->FixedDisplayUnits = PropertyUnits.GetValue();
	}
	
	HeaderRow.
		NameContent()
		[
			PropertyHandle->CreatePropertyNameWidget()
		]
		.ValueContent()
		[
			SNew(SNumericEntryBox<double>)
			.Value( this, &FFixed64Customization::GetFixedValue )
			.OnValueChanged( this, &FFixed64Customization::FixedValue_OnValueChanged )
			.TypeInterface(TypeInterface)
		];

	TArray<UObject*> Objects;
	PropertyHandle->GetOuterObjects(Objects);
	for (UObject* Object : Objects)
	{
		TargetObject = TWeakObjectPtr<UObject>(Object);
		break;
	}
}

void FFixed64Customization::FixedValue_OnValueChanged(double InNewValue )
{
	PropHandle->SetValueFromFormattedString(*FString::Printf(TEXT("%lld"), FFixed64(InNewValue).GetRawData()));
	PropHandle->NotifyPostChange(EPropertyChangeType::ValueSet);
}
	
TOptional<double> FFixed64Customization::GetFixedValue() const
{
	if (FixedValue == nullptr)
	{
		return 0;
	}
	
	return static_cast<double>(*FixedValue);
}

#undef LOCTEXT_NAMESPACE
