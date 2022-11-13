#include <string>
#include <ctype.h>
#include <iostream>
#include "BigInt.h"
#define CHARSTART 48
bool NonRec; // для исключения возможности бесконечной рекурсии при вызове inc/dec и add/sub

	BigInt::BigInt() {
		isneg = false; 
		Digits = "";
	}
	BigInt::BigInt(int a) {
		if (a < 0) isneg = true;
		else isneg = false;
		if (isneg)Digits = (std::to_string(a)).substr(1, std::to_string(a).size() - 1);
		else Digits = std::to_string(a);
	}
	BigInt::BigInt(std::string a) {
		int j = 0;
		long long int maxsz;
		int i;
		if (a[0] == 45) {
			j++;
			maxsz = a.size() - 1;
			i = 1;
			isneg = true;
		}
		else {
			if (!isdigit(a[0])) throw("std::invalid_argument");
			isneg = false;
			i = 0;
			maxsz = a.size();
		}
		while (a[j] == '0')j++;
		for (; i < maxsz; i++) {
			if (!isdigit(a[i])) {
				throw("std::invalid_argument");
			}
		}
		Digits = a.substr(j, a.size());
	}
	BigInt::BigInt(const BigInt& a){
		this->Digits = a.Digits;
		this->isneg = a.isneg;
	}
	BigInt:: ~BigInt() = default;
	BigInt::BigInt(std::vector<int> a)
	{
		for (auto x : a)
		{
			this->Digits.append(std::to_string(x));
		}
	}

	BigInt BigInt::operator~() const
	{
		BigInt outputValue;
		switch (this->isneg)
		{
		case(true):
			outputValue = (*this);
			outputValue.isneg = false;
			break;

		case(false):
			outputValue = (*this);
			outputValue.isneg = true;
			break;
		}
		outputValue--;
		return outputValue;
	}
	

	BigInt& BigInt::operator++() {
		BigInt ans = *this;
		ans++;
		const_cast<BigInt*>(this)->Digits = ans.Digits;
		return *this;
	}

	const BigInt BigInt::operator++(int) const {
		if (const_cast<BigInt*>(this)->isneg && !NonRec) {
			BigInt a = BigInt();
			a = *const_cast<BigInt*>(this);
			NonRec = true;
			a--;
			const_cast<BigInt*>(this)->Digits = a.Digits;
			NonRec = false;
			return *this;
		}
		for (long long i = this->Digits.size()-1; i >= 0; i--) {
			if (const_cast<BigInt*>(this)->Digits[i]-CHARSTART+1 > 9) {
				const_cast<BigInt*>(this)->Digits[i] = '0';
				const_cast<BigInt*>(this)->Digits[i - 1]++;
			}
			else {
				if ((i != 0 || const_cast<BigInt*>(this)->size() == 1))(const_cast<BigInt*>(this)->Digits[i])++;
				break;
			}
		}
		return *this;
	}

	const BigInt BigInt::operator--(int) const {
		if ((const_cast<BigInt*>(this)->isneg || const_cast<BigInt*>(this)->Digits == "0") && !NonRec) {
			BigInt a = BigInt();
			a = *const_cast<BigInt*>(this);
			NonRec = true;
			a++;
			const_cast<BigInt*>(this)->Digits = a.Digits;
			const_cast<BigInt*>(this)->isneg = true;
			NonRec = false;
			return *this;
		}
		for (long long i = this->Digits.size()-1; i >= 0; i--) {
			if (const_cast<BigInt*>(this)->Digits[i] == '0' || const_cast<BigInt*>(this)->Digits[i] == '/') {
				const_cast<BigInt*>(this)->Digits[i] = '9';
				const_cast<BigInt*>(this)->Digits[i - 1] --;
			}
			else { 
				if ((i != 0 || const_cast<BigInt*>(this)->size() == 1)) const_cast<BigInt*>(this)->Digits[i] --;
				break; 
			}
		}
		
		return *this;
	}
	
	BigInt& BigInt::operator--() {
		BigInt ans = *this;
		ans--;
		const_cast<BigInt*>(this)->Digits = ans.Digits;
		return *this;
		return *this;
	}

	BigInt BigInt::operator+() const{
		const_cast<BigInt*>(this)->Digits = Digits;
		const_cast<BigInt*>(this)->isneg = false;
		return *this;
	}
	
	BigInt BigInt::operator-() const {
		BigInt& temp = const_cast<BigInt&>(*this);
		if (this->isneg)
		{
			temp = const_cast<BigInt&>(*this);
			temp.isneg = false;
			return temp;
		}
		else
		{
			temp = const_cast<BigInt&>(*this);
			temp.isneg = true;
			return temp;
		}
	}
	
	size_t BigInt::size() const{
		return this->Digits.size();
	}

	BigInt& BigInt::operator^=(const BigInt& a) {
		BigInt ans = BigInt();
		ans = a ^ *this;
		const_cast<BigInt*>(this)->Digits = ans.Digits;
		const_cast<BigInt*>(this)->isneg = ans.isneg;
		return *this;
	}

	BigInt& BigInt::operator|=(const BigInt& a) {
		BigInt ans = BigInt();
		ans = a | *this;
		const_cast<BigInt*>(this)->Digits = ans.Digits;
		const_cast<BigInt*>(this)->isneg = ans.isneg;
		return *this;
	}

	BigInt& BigInt::operator&=(const BigInt& a) {
		BigInt ans = BigInt();
		ans = a & *this;
		const_cast<BigInt*>(this)->Digits = ans.Digits;
		const_cast<BigInt*>(this)->isneg = ans.isneg;
		return *this;
	}

	bool BigInt::operator!=(const BigInt& a) const {
		return !(*this == a);
	}

	bool BigInt::operator<(const BigInt& a) const {
		if (this->isneg && !a.isneg) return true;
		else if (!this->isneg && a.isneg) return false;

		if (this->size() < a.size()) return true;
		else if (this->size() > a.size()) return false;

		else
		{
			for (long long i = 0; i < a.size(); i++) {
				if (this->Digits[i] < a.Digits[i]) return !this->isneg;
				else if(this->Digits[i] > a.Digits[i]) return this->isneg;
			}
			return false;
		}
	}

	bool BigInt::operator>(const BigInt& a) const {
		return !(*this < a)^(*this==a);
	}
	
	bool BigInt::operator<=(const BigInt& a) const {
		return (*this < a) || (*this == a);
	}
	
	bool BigInt::operator>=(const BigInt& a) const {
		return !(*this < a) || (*this == a);
	}

	bool BigInt::operator==(const BigInt& a) const {
		if (this->isneg != a.isneg) return false;
		if (this->size() != a.size()) return false;
		for (int i = 0; i < a.size(); i++) {
			if (this->Digits[i] != a.Digits[i]) return false;
		}
		return true;
	}

	BigInt& BigInt::operator=(const BigInt& a) {
		if (a.Digits != this->Digits) {
			Digits = a.Digits;
			isneg = a.isneg;
		}
		if (a.Digits == this->Digits && a.isneg != this->isneg) {
			isneg = a.isneg;
		}
		return *this;
	}

	BigInt& BigInt::operator+=(const BigInt& a) {
		BigInt ans = BigInt();
		ans = a + *this;
		const_cast<BigInt*>(this)->Digits = ans.Digits;
		const_cast<BigInt*>(this)->isneg = ans.isneg;
		return *this;

	}

	BigInt& BigInt::BigInt::operator-=(const BigInt& a ) {
		BigInt ans = BigInt();
		ans = *this-a;
		const_cast<BigInt*>(this)->Digits = ans.Digits;
		const_cast<BigInt*>(this)->isneg = ans.isneg;
		return *this;
	}

	BigInt& BigInt:: operator*=(const BigInt& a) {
		BigInt ans = BigInt();
		ans = a * *this;
		const_cast<BigInt*>(this)->Digits = ans.Digits;
		const_cast<BigInt*>(this)->isneg = ans.isneg;
		return *this;
	}

	BigInt& BigInt:: operator/=(const BigInt& a) {
		BigInt ans = BigInt();
		ans = *this/a;
		const_cast<BigInt*>(this)->Digits = ans.Digits;
		const_cast<BigInt*>(this)->isneg = ans.isneg;
		return *this;
	}

	BigInt& BigInt:: operator%=(const BigInt& a) {
		BigInt ans = BigInt();
		ans = *this % a;
		const_cast<BigInt*>(this)->Digits = ans.Digits;
		const_cast<BigInt*>(this)->isneg = ans.isneg;
		return *this;
	}

	BigInt::operator int() const {
		BigInt temp = (*this % BigInt(INT_MAX));
		int ans = std::stoi(temp.Digits);
		if (temp.isneg) ans *= -1;
		return ans;
	}
	BigInt::operator std::string() const {
		std::string ans;
		if (this->isneg) ans.append ("-");
		else ans.append(this->Digits);
		return ans;
	}

BigInt operator+(const BigInt& a, const BigInt& b){
	BigInt ans = BigInt();
	int temp = 0;
	BigInt a1 = a;
	BigInt b1 = b;
	if (a.isneg && !NonRec) {
		NonRec = true;
		ans = b - a1;
		NonRec = false;
		return ans;
	}
	else if (b.isneg && !NonRec) {
		NonRec = true;
		ans = a - b1;
		NonRec = false;
		return ans;
	}
	if (a.size() < b.size()) a1 = addZero(a, b.size());
	else if (a.size() > b.size()) b1 = addZero(b, a.size());
		for (long long i = b1.size()-1; i >= 0; i--) {
			if (a1.Digits[i] + b1.Digits[i] - 2 * CHARSTART+temp > 9)
			{
				ans.Digits.insert(0,std::to_string(a1.Digits[i] + b1.Digits[i] - 2 * CHARSTART - 10 + temp));
					temp = 1;
			}
			else {
				ans.Digits.insert(0,std::to_string(a1.Digits[i] + b1.Digits[i] - 2 * CHARSTART + temp));
					temp = 0;
			}
	}
	ans.Digits.insert(0, std::to_string(temp));
	deleteZero(ans);
	return ans;
}

BigInt operator-(const BigInt& a, const BigInt& b) {
	BigInt ans = BigInt();
	int temp = 0;
	BigInt a1 = a;
	BigInt b1 = b;
	if (b.isneg && !NonRec) {
		NonRec = true;
		ans = a + b1;
		NonRec = false;
		return ans;
	}
	if (a.isneg && b.isneg && !NonRec) {
		NonRec = true;;
		BigInt ans = a + b;
		NonRec = false;
		return ans;
	}
	if (a.size() < b.size()) a1 = addZero(a, b.size());
	else if (a.size() > b.size()) b1 = addZero(b, a.size());
	if (a1< b1 && b1.isneg) {
		BigInt temp = b1;
		b1 = a1;
		a1 = temp;
	}
	for (long long i = b1.size()-1; i >= 0; i--) {
		if (a1.Digits[i]-b1.Digits[i]+temp<0) {
			ans.Digits.insert(0,std::to_string(a1.Digits[i] - b1.Digits[i] + 10+temp));
			temp = -1;
		}
		else {
			ans.Digits.insert(0,std::to_string(a1.Digits[i] - b1.Digits[i]+temp));
			temp = 0;
		}
	}
	deleteZero(ans);
	b1.isneg = b.isneg;
	a1.isneg = a.isneg;
	if (a1 < b1) ans.isneg = true;
	return ans;
}

BigInt operator^(BigInt& a, BigInt& b) {
	BigInt ans = BigInt(0);
	std::vector<int> a_2 = ToBinPow(a);
	std::vector<int> b_2 = ToBinPow(b);

	ans.Digits.reserve(a.size() + b.size());

	while (a_2.size() > b_2.size()) b_2.push_back((b.isneg) ? -1 : 0);
	while (a_2.size() < b_2.size()) a_2.push_back((a.isneg) ? -1 : 0);

	std::vector<int> _ans;
	_ans.reserve(a.size() + b.size());
	for (int i = 0; i < a_2.size(); i++) {
		_ans.push_back(a_2[i] ^ b_2[i]);
	}

	BigInt currentPower = 1;
	for (int i = 0; i < _ans.size(); i++)
	{
		BigInt left = BigInt(_ans[i]) * currentPower;
		ans += (BigInt(_ans[i]) * currentPower);
		currentPower *= 1073741824;
		if (ans.isneg) ans++;
	}
	ans.isneg = (a.isneg ^ b.isneg);

	return ans; 
}

BigInt operator&(const BigInt& a , const BigInt& b) {
	BigInt ans = BigInt(0);
	ans.isneg = (a.isneg && b.isneg);
	std::vector<int> a_2 = ToBinPow(a);
	std::vector<int> b_2 = ToBinPow(b);

	ans.Digits.reserve(a.size() + b.size());

	while (a_2.size() > b_2.size()) b_2.push_back((b.isneg) ? -1 : 0);
	while (a_2.size() < b_2.size()) a_2.push_back((a.isneg) ? -1 : 0);

	std::vector<int> _ans;
	_ans.reserve(a.size() + b.size());
	for (int i = 0; i < a_2.size(); i++) {
		_ans.push_back(a_2[i] & b_2[i]);
	}

	BigInt currentPower = 1;
	for (int i = 0; i < _ans.size(); i++)
	{
		ans += (BigInt(_ans[i]) * currentPower);
		currentPower *= 1073741824;
		
	}
	if (b.isneg || a.isneg) ans--;

	return ans;
}

BigInt operator|(const BigInt& a , const BigInt& b) {
	BigInt ans = BigInt(0);
	ans.isneg = (a.isneg || b.isneg);
	std::vector<int> a_2 = ToBinPow(a);
	std::vector<int> b_2 = ToBinPow(b);

	ans.Digits.reserve(a.size() + b.size());

	while (a_2.size() > b_2.size()) b_2.push_back((b.isneg) ? -1 : 0);
	while (a_2.size() < b_2.size()) a_2.push_back((a.isneg) ? -1 : 0);

	std::vector<int> _ans;
	_ans.reserve(a.size() + b.size());
	for (int i = 0; i < a_2.size(); i++) {
		_ans.push_back(a_2[i] | b_2[i]);
	}

	BigInt currentPower = 1;
	for (int i = 0; i < _ans.size(); i++)
	{
		ans += (BigInt(_ans[i]) * currentPower);
		currentPower *= 1073741824;
	}

	return ans;
}

BigInt addZero(const BigInt& a, size_t size) {
	BigInt ans = a;
	while (ans.size() < size) ans.Digits.insert(0,"0");
	return ans;
}

void deleteZero(BigInt& a) {
	BigInt nonzeroans = BigInt();
	nonzeroans.isneg = a.isneg;
	long long i = 0;
	for (; a.Digits[i]=='0'; i++){}
	nonzeroans.Digits.append(a.Digits.substr(i));
	a = nonzeroans;
}

std::vector<int> ToBinPow(const BigInt& a) {
	std::vector<int> ans;
	BigInt temp = a, zero(0);
	ans.reserve(a.size() * 2);
	temp.isneg = false;
	while (temp > zero)
	{
		ans.push_back((!a.isneg) ? temp % BigInt(1073741824) : -(temp % BigInt(1073741824)));
		temp /= BigInt(1073741824);
	}

	if (a.isneg) ans[0]++;

	return ans;
}

std::ostream& operator<<(std::ostream& o, const BigInt& i) {
	if (i.Digits[0] == '0') {
		o << 0;
		return o;
	}	

	else if (i.Digits == "") return o;
	else {
		if (i.isneg) {
			o << '-';
		}
		for (int j=0; j < i.size(); j++) {
			o << i.Digits[j];
		}
	}
	return o;
}

BigInt operator*(const BigInt& a, const BigInt& b) {
	if (a.Digits[0] == '0' || b.Digits[0] == '0') return BigInt(0);


	BigInt promans = BigInt();
	BigInt sum = BigInt(0);
	int temp = 0;
	BigInt a1 = a;
	BigInt b1 = b;
	if (a.size() < b.size()) a1 = addZero(a, b.size());
	else if (a.size() > b.size()) b1 = addZero(b, a.size());
	for (long long i = a1.size()-1; i >=0; i--) {
		for (long long j = a1.size()-1; j >=0; j--) {
			if ((a1.Digits[j] - CHARSTART) * (b1.Digits[i] - CHARSTART)+temp > 9) {
				promans.Digits.insert(0, std::to_string(((a1.Digits[j] - CHARSTART) * (b1.Digits[i] - CHARSTART)+temp)%10));
				temp = ((a1.Digits[j] - CHARSTART) * (b1.Digits[i] - CHARSTART)+temp)/10;
			}
			else{
				promans.Digits.insert(0, std::to_string((a1.Digits[j] - CHARSTART) * (b1.Digits[i] - CHARSTART)+temp));
				temp = 0;
			}
		}
		promans.Digits.insert(0, std::to_string(temp));
		for (long long k = a1.size() - i-1; k > 0; k--)promans.Digits.append("0");
		sum += promans;
		promans = BigInt();
		temp = 0;
	}
	deleteZero(sum);
	if (a.isneg != b.isneg) sum.isneg = true;
	else sum.isneg = false;
	return sum;

}



BigInt operator/(const BigInt& a, const BigInt& b) {
	BigInt ans = BigInt();
	BigInt cur = BigInt();
	BigInt temp = b;
	temp.isneg = false;
	if (a < b) {
		ans.Digits.append("0");
		return ans;
	}
	if (b.Digits[0] == '0') throw ("Exception: Integer division by zero");
	if (a == b) {
		ans.Digits.append("1");
		return ans;
	}
	for (long long i = 0; i < a.size(); ++i) {
		cur.Digits.push_back('0');
		cur.Digits[cur.size()-1] = a.Digits[i];
		deleteZero(cur);
		BigInt x = BigInt(0);
		int l = 0, r = 10;
		while (l <= r) {
			int middle = (l + r) / 2;
			BigInt raw = temp*BigInt(middle);
			if (raw <= cur) {
				x = middle;
				l = middle+1;
			}
			else r = middle-1;

		}
		ans.Digits.append(x.Digits);
		cur = cur - temp * x;
	}
	deleteZero(ans);
	if (a.isneg != b.isneg) ans.isneg = true;
	return ans;
}


BigInt operator%(const BigInt& a, const BigInt& b) {
	if (a < b) return a;
	BigInt ans = BigInt();
	ans = a - (a / b)*b;
	if (ans.isneg) ans += b;
	if (ans.Digits == "") ans.Digits.append("0");
	return ans;
}
