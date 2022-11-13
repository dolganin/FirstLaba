#pragma once
#include <string>
#include <vector>

class BigInt {
public:
	std::string Digits;
	bool isneg;
	BigInt();
	BigInt(int);
	BigInt(std::string); // бросать исключение std::invalid_argument при ошибке
	BigInt(const BigInt&);
	~BigInt();
	BigInt(std::vector<int>);

	BigInt& operator=(const BigInt&);  //возможно присваивание самому себе!

	BigInt operator~() const;

	BigInt& operator++();
	const BigInt operator++(int) const;
	BigInt& operator--();
	const BigInt operator--(int) const;

	BigInt& operator+=(const BigInt&);
	BigInt& operator*=(const BigInt&);
	BigInt& operator-=(const BigInt&);
	BigInt& operator/=(const BigInt&);
	BigInt& operator^=(const BigInt&);
	BigInt& operator%=(const BigInt&);
	BigInt& operator&=(const BigInt&);
	BigInt& operator|=(const BigInt&);

	BigInt operator+() const;  // унарный +
	BigInt operator-() const;  // унарный -

	bool operator==(const BigInt&) const;
	bool operator!=(const BigInt&) const;
	bool operator<(const BigInt&) const;
	bool operator>(const BigInt&) const;
	bool operator<=(const BigInt&) const;
	bool operator>=(const BigInt&) const;

	operator int() const;
	operator std::string() const;

	size_t size() const;  // размер в байтах
};

BigInt operator+(const BigInt&, const BigInt&);
BigInt operator-(const BigInt&, const BigInt&);
BigInt operator*(const BigInt&, const BigInt&);
BigInt operator/(const BigInt&, const BigInt&);
BigInt operator^(BigInt&, BigInt&);
BigInt operator%(const BigInt&, const BigInt&);
BigInt operator&(const BigInt&, const BigInt&);
BigInt operator|(const BigInt&, const BigInt&);
std::ostream& operator<<(std::ostream& o, const BigInt& i);


std::vector<int> ToBinPow(const BigInt& a);
void deleteZero(BigInt&);	//вспомогательные функции
BigInt addZero(const BigInt&, size_t);

