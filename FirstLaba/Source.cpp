#include <iostream>
#include "BigInt.h"
#include <assert.h>
#include <vector>
using namespace std;

int main() {

	BigInt a = BigInt("-000000000000000000000000000025");
	/**BigInt n = BigInt("kfjsdkfjsd");*/
	BigInt n = BigInt("394858934859348534");
	cout << a;
	a++;
	cout << '\n';
	cout << a;
	cout << '\n';
	BigInt b = BigInt(-128);
	cout << b;
	cout << '\n';
	BigInt c = BigInt();
	cout << c;
	cout << '\n';
	BigInt f = BigInt("5345893478592378954237894892384923849823942385723894758923758923");
	f++;
	cout << f;
	cout << '\n';
	f--;
	cout << f;
	cout << '\n';
	BigInt h = BigInt(45);
	BigInt j = h + a;
	cout << j;
	cout << '\n';
	BigInt k = BigInt("-48723847238478127481274812");
	cout << k;
	BigInt l = BigInt("312903012903129031291249129491");
	cout << h;
	cout << '\n';
	h = j;
	cout << h;
	cout << '\n';
	h = l + k;
	cout << h;
	cout << '\n';
	j = BigInt(56);
	BigInt o = l - k;
	cout << o;
	cout << '\n';
	BigInt g = BigInt("48723847238478127481274813");
	BigInt p = g + k;
	cout << p;
	cout << '\n';
	a = BigInt("2999999999999999999999999999999999");
	a++;
	cout << a;
	cout << '\n';
	a--;
	cout << a;
	a = BigInt("11");
	cout << '\n';
	b = BigInt(12);
	h = a | b;
	cout << h;
	cout << '\n';
	a = BigInt("-10");
	cout << a;
	a--;
	a--;
	a--;
	cout << '\n';
	cout << a;
	a++;
	a++;
	cout << '\n';
	cout << a;
	cout << '\n';
	h = -g;
	cout << h;
	h--;
	cout << '\n';
	cout << h;
	h++;
	cout << '\n';
	cout << h;
	a = BigInt("3463463463462352");
	b = BigInt("4567547456734634523");
	cout << '\n';
	cout << a * b;
	assert((a < b) == true);
	-b;
	assert((a > b) == true);
	a = BigInt("534");
	b = BigInt("534");
	assert((a == b) == true);
	assert((a <= b) == true);
	b = BigInt("533");
	assert((a >= b) == true);
	g = BigInt(500);
	c = BigInt(5);
	a = BigInt(15);
	b = BigInt(12);
	assert(a >= b);
	cout << '\n';
	cout << g / c;
	cout << '\n';
	cout << a % b;
	cout << '\n';
	h = BigInt("11");
	j = BigInt("12");
	g = h ^ j;
	cout << g;
	cout << "\n";
	/*vector <int> arr;*/
	/*long long int* arr = new long long int [10*h.size()];
	/*cout << ToBinPow(h, arr);
	cout << "\n";
	for (int i=0;i<arr.size(); i++) cout << arr[i];*/
	cout << (h / j);
	cout << '\n';
	h = BigInt("85734857348573485");
	j = BigInt("11901901910191010");
	g = h ^ j;
	/*cout << "111010010001011000001001100101000000100011010010111010001001";*/
	cout << '\n';
	cout << g;
	cout << '\n';
	a= BigInt("347663465893");
	b = BigInt("25735738");
	cout << (a | b);
	cout << '\n';
	cout << (~a);
	cout << '\n';
	cout << (a & b);
	cout << '\n';
	b = BigInt("-25735738");
	cout << (a & b);
	cout << '\n';
	cout << (~b);
	return 0;
}