// Copyright 2021 Massive Miniteam GmbH. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Fixed64.generated.h"

/* todo @Sebastian || @Robert:
 *	Serialize,
 *	FastInverseSquareRoot
 *	Performance tests and optimization
 */

struct FFixed64;

FFixed64 operator+(FFixed64 A, FFixed64 B);
FFixed64 operator-(FFixed64 A, FFixed64 B);
FFixed64 operator*(FFixed64 A, FFixed64 B);
FFixed64 operator/(FFixed64 A, FFixed64 B);

USTRUCT(BlueprintType)
struct MMTFIXED64_API FFixed64
{
	GENERATED_BODY()

	using BaseType = int64;

private:
	UPROPERTY(SaveGame)
	int64 Data = 0;

public:
	static constexpr size_t TotalBits = sizeof(BaseType) * 8;
	static constexpr size_t FractionalBits = 32;
	static constexpr size_t IntegralBits = TotalBits - FractionalBits;

	static constexpr BaseType One = BaseType{1} << FractionalBits;
	static constexpr BaseType Zero = BaseType{0};

	//static constexpr BaseType FractionalMask = ~(static_cast<BaseType>(~Zero) << FractionalBits);
	static constexpr BaseType FractionalMask = One - 1ull;
	static constexpr BaseType SignBitMask = INT64_MIN;
	static constexpr BaseType IntegralMask = ~FractionalMask;

	static const FFixed64 Pi;
	static const FFixed64 PiHalf;
	static const FFixed64 RadToDegree;
	static const FFixed64 DegreeToRad;
	static const FFixed64 SmallestPositiveValue;

public:
	FFixed64()
	{
	}

	// ReSharper disable once CppNonExplicitConvertingConstructor, conversion to int is without loss of information
	FFixed64(int32 Value) { Data = static_cast<BaseType>(Value) << FractionalBits; }
	explicit operator int32() const { return Data >> FractionalBits; }

	explicit FFixed64(int64 Value) : FFixed64(static_cast<int32>(Value))
	{
	}

	explicit operator int64() const { return static_cast<int32>(*this); }

	// ReSharper disable once CppNonExplicitConvertingConstructor, Sebastian: implicit conversion allowed here
	FFixed64(float Value) { Data = static_cast<BaseType>(Value * One); }
	explicit operator float() const { return static_cast<float>(Data) / One; }

	explicit FFixed64(double Value) { Data = static_cast<BaseType>(Value * One); }
	explicit operator double() const { return static_cast<double>(Data) / One; }

	static FFixed64 MakeFromRawData(int64 Bits)
	{
		FFixed64 Fixed;
		Fixed.Data = Bits;
		return Fixed;
	}

	int64 GetRawData() const { return Data; }
	void SetRawData(int64 InData) { Data = InData; }

	explicit operator FString() const { return FString::Printf(TEXT("%f"), static_cast<float>(*this)); }

	FFixed64& operator+=(FFixed64 A)
	{
		Data += A.Data;
		return *this;
	}

	FFixed64& operator-=(FFixed64 A)
	{
		Data -= A.Data;
		return *this;
	}

	FFixed64& operator*=(FFixed64 A)
	{
		int Sign = GetSign();
		int SignA = A.GetSign();

		uint64 Left = static_cast<uint64>(Data * Sign);
		uint64 Right = static_cast<uint64>(A.Data * SignA);

		uint64 Result = MultiplyUnsigned(Left, Right);

		Data = static_cast<int64>(Result) * Sign * SignA;
		return *this;
	}

	FFixed64 Invert() const
	{
		if (Data == 0)
		{
			return FFixed64{0};
		}

		FFixed64 Inverse;
		Inverse.Data = ((One << (FractionalBits - 2)) / Data) << 2;

		return Inverse;
	}

	FFixed64& operator/=(FFixed64 A)
	{
		if (A.Data != 0)
		{
			FFixed64 Inverse = A.Invert();

			*this *= Inverse;
		}

		return *this;
	}

	FFixed64 operator-() const
	{
		return *this * -1;
	}

	template <typename T>
	static T GetMaxValue()
	{
		FFixed64 Max;
		Max.Data = INT64_MAX;

		return static_cast<T>(Max);
	}

	template <typename T>
	static T GetMinValue()
	{
		FFixed64 Min;
		Min.Data = INT64_MIN;

		return static_cast<T>(Min);
	}

	int GetSign() const
	{
		return Data > 0 ? 1 : -1;
	}

	static FFixed64 SquareRoot(FFixed64 A)
	{
		// Using newton's method
		// a is the input.
		// f(x) = x^2 - a is the function, which roots we are looking for
		// f'(x) = 2x
		// update step => x_new = 1/2 * (x_old + a/x_old)

		FFixed64 X0 = A / 2;
		FFixed64 X1 = X0;

		constexpr int MAX_ITERATIONS = 40;

		for (int i = 0; i < MAX_ITERATIONS; ++i)
		{
			auto Step = (X0 + A / X0) / 2;

			if (FMath::Abs(Step) < X0 / 1000)
			{
				break;
			}

			X0 = X1;
			X1 = Step;
		}

		return X0;
	}

	static FFixed64 Ceil(FFixed64 f)
	{
		if ((f.Data & FractionalMask) == 0)
		{
			return f;
		}
		else
		{
			return MakeFromRawData((One + f.Data) & IntegralMask);
		}
	}

	static FFixed64 Floor(FFixed64 f)
	{
		return MakeFromRawData(f.Data & IntegralMask);
	}

	static FFixed64 Round(FFixed64 f)
	{
		return Floor(MakeFromRawData(f.Data + (One >> 1)));
	}

	static FFixed64 Abs(FFixed64 f)
	{
		if(f < 0)
		{
			return -f;
		}
		return f;
	}

	/** Export contents of this struct as a string */
	bool ExportTextItem(FString& ValueStr, FFixed64 const& DefaultValue, UObject* Parent, int32 PortFlags, UObject* ExportRootScope) const
	{
		ValueStr = FString::Printf(TEXT("%lld"), Data);
		return true;
	}

	/** Import string contexts and try to map them into a unique id */
	bool ImportTextItem(const TCHAR*& Buffer, int32 PortFlags, UObject* Parent, FOutputDevice* ErrorText)
	{
		int64 Value = FCString::Atoi64(Buffer);
		Data = Value;
		return true;
	}

private:
	static uint64 MultiplyUnsigned(uint64 A, uint64 B)
	{
		constexpr uint64 FractionMaskUnsigned = (1ull << FractionalBits) - 1ull;

		uint64 A_High = A >> FractionalBits;
		uint64 A_Low = A & FractionMaskUnsigned;

		uint64 B_High = B >> FractionalBits;
		uint64 B_Low = B & FractionMaskUnsigned;

		return ((A_High * B_High) << FractionalBits) + A_High * B_Low + A_Low * B_High + ((A_Low * B_Low) >> FractionalBits);
	}

	friend bool operator==(FFixed64 A, FFixed64 B);
	friend bool operator!=(FFixed64 A, FFixed64 B);
	friend bool operator<(FFixed64 A, FFixed64 B);
	friend bool operator<=(FFixed64 A, FFixed64 B);
	friend bool operator>(FFixed64 A, FFixed64 B);
	friend bool operator>=(FFixed64 A, FFixed64 B);
};

template <>
struct TStructOpsTypeTraits<FFixed64> : TStructOpsTypeTraitsBase2<FFixed64>
{
	enum
	{
		WithExportTextItem = true,
		WithImportTextItem = true
	};
};


inline FFixed64 operator+(FFixed64 A, FFixed64 B) { return A += B; }
inline FFixed64 operator-(FFixed64 A, FFixed64 B) { return A -= B; }
inline FFixed64 operator*(FFixed64 A, FFixed64 B) { return A *= B; }
inline FFixed64 operator/(FFixed64 A, FFixed64 B) { return A /= B; }

inline bool operator==(FFixed64 A, FFixed64 B) { return A.Data == B.Data; }
inline bool operator!=(FFixed64 A, FFixed64 B) { return A.Data != B.Data; }
inline bool operator<(FFixed64 A, FFixed64 B) { return A.Data < B.Data; }
inline bool operator<=(FFixed64 A, FFixed64 B) { return A.Data <= B.Data; }
inline bool operator>(FFixed64 A, FFixed64 B) { return A.Data > B.Data; }
inline bool operator>=(FFixed64 A, FFixed64 B) { return A.Data >= B.Data; }
