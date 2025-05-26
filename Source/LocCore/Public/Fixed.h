#pragma once
#include "CoreMinimal.h"
#include "Fixed.generated.h"

USTRUCT(BlueprintType)
struct FFixed {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RepValue;
	
	using BaseType = typename FPlatformTypes::int32;
	static constexpr size_t FractionalBits = 16;
	static constexpr int One = BaseType(1) << FractionalBits;
    
	FFixed()
	{
		this->RepValue = 0;
	}
	
	FFixed(int Val)
	{
		RepValue = static_cast<BaseType>(Val * One);
	}
	
	FFixed(float Val)
	{
		RepValue = static_cast<BaseType>(Val * One);
	}
    
    friend FArchive& operator<<(FArchive& Ar, FFixed& Fixed)
    {
        Ar << Fixed.RepValue;
        return Ar;
    }

	bool Serialize(FArchive& Ar)
	{
		Ar << *this;
		return true;
	}
	
	bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess)
    {
    	bOutSuccess = true;
    	Ar << *this;
    	return true;
    }

	explicit operator float() const
    {
    	return static_cast<float>(RepValue) / One;
    }

	FString ToString() const;

	FText ToText() const
    {
    	return FText::FromString(ToString());
    }
	
	FString ToCompactString() const
    {
    	return ToString();
    }
	
	FText ToCompactText() const
    {
    	return FText::FromString(ToString());
    }

	/** Export contents of this struct as a string */
	bool ExportTextItem(FString& ValueStr, FFixed const& DefaultValue, UObject* Parent, int32 PortFlags, UObject* ExportRootScope) const
    {
    	ValueStr = FString::Printf(TEXT("%d"), RepValue);
    	return true;
    }

	/** Import string contexts and try to map them into a unique id */
	bool ImportTextItem(const TCHAR*& Buffer, int32 PortFlags, UObject* Parent, FOutputDevice* ErrorText)
    {
    	int Value = FCString::Atoi(Buffer);
    	RepValue = Value;
    	return true;
    }
};

FORCEINLINE FString FFixed::ToString() const
{
	return FString::SanitizeFloat(static_cast<float>(*this), 0);
}

template <> struct TIsPODType<FFixed> { enum { Value = false }; };

template<> struct TStructOpsTypeTraits<FFixed> : TStructOpsTypeTraitsBase2< FFixed >
{
	enum
	{
		WithSerializer = true,
		WithNetSerializer = true,
		WithCopy = true,
		// Export contents of this struct as a string (displayall, obj dump, etc)
		WithExportTextItem = true,
		// Import string contents as a unique id
		WithImportTextItem = true
	};
};