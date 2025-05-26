// Fill out your copyright notice in the Description page of Project Settings.


#include "FixedCustomization.h"

#include "BlueprintEditor.h"
#include "DetailWidgetRow.h"
#include "PropertyHandle.h"
#include "IDetailChildrenBuilder.h"
#include "LocCore/Public/Fixed.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Math/UnitConversion.h"
#include "Widgets/Input/SNumericEntryBox.h"
#include "UObject/UnrealType.h"
#include "Widgets/Input/NumericTypeInterface.h"
#include "Widgets/Input/NumericUnitTypeInterface.inl"

TSharedRef<IPropertyTypeCustomization> FFixedCustomization::MakeInstance()
{
	return MakeShareable(new FFixedCustomization());
}

void FFixedCustomization::CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	
}

void FFixedCustomization::CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow,
                                          IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	void* Value = nullptr;
	PropertyHandle->GetValueData(Value);
	PropHandle = PropertyHandle;
	
	FFixed* Fixed = static_cast<FFixed*>(Value);
	FixedValue = Fixed;

	const FString& ForcedUnits = PropertyHandle->GetMetaData(TEXT("ForceUnits"));
	auto PropertyUnits = FUnitConversion::UnitFromString(*ForcedUnits);
	if (PropertyUnits.IsSet())
	{
		TypeInterface = MakeShareable(new TNumericUnitTypeInterface<float>(PropertyUnits.GetValue()));
		TypeInterface->FixedDisplayUnits = PropertyUnits.GetValue();
	}
	
	HeaderRow.
		NameContent()
		[
			PropertyHandle->CreatePropertyNameWidget()
		]
		.ValueContent()
		[
			SNew(SNumericEntryBox<float>)
			.Value( this, &FFixedCustomization::GetFixedValue )
			.OnValueChanged( this, &FFixedCustomization::FixedValue_OnValueChanged )
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

void FFixedCustomization::FixedValue_OnValueChanged( float InNewValue )
{
	PropHandle->SetValueFromFormattedString(*FString::Printf(TEXT("%d"), FFixed(InNewValue).RepValue));
	PropHandle->NotifyPostChange(EPropertyChangeType::ValueSet);
}
	
TOptional<float> FFixedCustomization::GetFixedValue() const
{
	if (FixedValue == nullptr)
	{
		return 0;
	}
	
	return static_cast<float>(*FixedValue);
}
