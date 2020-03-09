/*Exception Handling mekanizmalarý burada kullanýlmýþtýr*/
/*Yusuf YALÇIN tarafýndan yazýlmýþtýr
18120205032
16.05.2019 Perþembe */
#include <vector>
#include <iostream>
#include "Sablon.h"

using namespace std;

template <class T>
ostream& operator<<(ostream & out, AkilliDizi <T> & dizi) {
	for (unsigned int i = 0; i < dizi.elemanSayisi; ++i) {
		out <<i <<".eleman " <<dizi.veri[i] << endl;
	}
	return out;
}

template <class T>
AkilliDizi<T>::AkilliDizi() {
	cout << "Default constructor cagrildi" << endl;
	veri = nullptr;
	elemanSayisi = 0;
	kapasite = 0;
}

template<class T>
AkilliDizi<T>::AkilliDizi(T i)
{
	kapasite = 1;
	elemanSayisi = 1;
	veri = new T[elemanSayisi];
	try {
		if (veri == nullptr) throw bad_alloc();
	}	
	catch (bad_alloc) {
		cout << " Hata olustu " << endl;
		exit(-1);
	}
	veri[0] = i;
}

template<class T>
AkilliDizi<T>::AkilliDizi(const T * intDizi, unsigned int elemanSayisi)
{   
	this->elemanSayisi = elemanSayisi;
	kapasite = this->elemanSayisi;
	veri = new T[this->elemanSayisi];
	try {
		if (veri == nullptr) throw bad_alloc();
	}
	catch (bad_alloc) {
		cout << " Hata olustu " << endl;
		exit(-1);
	}
	for (unsigned int i = 0; i < elemanSayisi; ++i) {
		veri[i] = intDizi[i];
	}
}

template<class T>
AkilliDizi<T>::AkilliDizi(const vector<T>& intVector)
{
	elemanSayisi = intVector.size();
	kapasite = elemanSayisi;
	veri = new T[elemanSayisi];
	try {
		if (veri == nullptr) throw bad_alloc();
	}
	catch (bad_alloc) {
		cout << " Hata olustu " << endl;
		exit(-1);
	}
	for (unsigned int i = 0; i < intVector.size(); ++i) {
		veri[i] = intVector[i];
	}
}

template<class T>
AkilliDizi<T>::AkilliDizi(const AkilliDizi<T>& other)
{
	elemanSayisi = other.elemanSayisi;
	kapasite = elemanSayisi;
	veri = nullptr;
	if (elemanSayisi != 0)
	{
		veri = new T[elemanSayisi];
		try {
			if (veri == nullptr) throw bad_alloc();
		}
		catch (bad_alloc) {
			cout << " Hata olustu " << endl;
			exit(-1);
		}
		if (memcpy(veri, other.veri, elemanSayisi * sizeof(T)) == nullptr)
			exit(-1);
	}
}

template<class T>
AkilliDizi<T>::~AkilliDizi()
{
	cout << "Destructor cagrildi " << endl;
	if (veri != nullptr)
	delete[] veri;
}

template<class T>
AkilliDizi<T>& AkilliDizi<T>::operator=(const AkilliDizi<T>& other)
{
	if (this == &other)
		return *this;

	if (veri != nullptr)
		delete[] veri;

	elemanSayisi = other.elemanSayisi;
	kapasite = elemanSayisi;
	veri = new T[elemanSayisi];
	try {
		if (veri == nullptr) throw bad_alloc();
	}
	catch (bad_alloc) {
		cout << " Hata olustu " << endl;
		exit(-1);
	}
	if (memcpy(veri, other.veri, elemanSayisi * sizeof(T)) == nullptr)
		exit(-1);
	return *this;
}

template<class T>
T & AkilliDizi<T>::operator[](unsigned int index)
{
	try {
		if (index > elemanSayisi) throw 1;
	}
	catch (int i) {
		cout << i << " Illegal index in Sablon.\n ";
		exit(0);
	}
	return veri[index];
}

template<class T>
AkilliDizi<T>& AkilliDizi<T>::operator+(const T & i)
{
	vector<T> temp;
	vector <T> temp2; // son hali için 
	vector <T> temp3;
	for (unsigned int k = 0; k < elemanSayisi; ++k) {
		temp.push_back(veri[k]);
	}
	for (unsigned int j = 0; j < 1; ++j)
	{
		temp3.push_back(i);
	}
	for (unsigned int j = 0; j < temp.size(); ++j)
	{
		temp2.push_back(temp[j]);
	}
	for (unsigned int j = 0; j < 1; ++j)
	{
		temp2.push_back(temp3[j]);
	}
	veri = nullptr;
	elemanSayisi = temp2.size();
	kapasite = 2 * elemanSayisi;
	veri = new T[(kapasite / 2) + 1];
	try {
		if (veri == nullptr) throw bad_alloc();
	}
	catch (bad_alloc) {
		cout << " Hata olustu " << endl;
		exit(-1);
	}
	for (unsigned int m = 0; m < elemanSayisi; ++m) {
		veri[m] = temp2[m];
	}
	return *this;
}

template<class T>
void AkilliDizi<T>::sirala()
{
	T temp;
	for (unsigned int i = 0; i < elemanSayisi; i++) 
		for (unsigned int j = 0; j < elemanSayisi; j++)
		{
			if (veri[j] < veri[j + 1])
			{
				temp = veri[j];
				veri[j] = veri[j + 1];
				veri[j + 1] = temp;
			}
		}
	for (unsigned int i = 0; i < elemanSayisi; i++)
	{
		cout << i+1 << ". " << veri[i] << endl;
	}
	
}

template<class T>
void AkilliDizi<T>::histogram(vector<Pair<T>>& hist) const
{
	
	hist.clear();
	for (unsigned m = 0; m < elemanSayisi; ++m) {
		Pair <T> a;
		int as = 0;
		for (unsigned  k = 1; k < elemanSayisi ; ++k) 
			if (veri[m] == veri[m + k])
				as = 1;
			if (as == 1)
				continue;
		        a.eleman = veri[m]; 
				a.adet = kacTane(veri[m]);
				hist.push_back(a);
	}
}

template<class T>
unsigned AkilliDizi<T>::kacTane(T i) const
{
	unsigned tane=0;
	for (unsigned int k = 0; k < elemanSayisi; ++k) {
		if (veri[k] == i) {
			++tane;
		}
	}
	return tane;
}

template<class T>
bool AkilliDizi<T>::varMi(T i) const
{
	for (unsigned int k = 0; k < elemanSayisi; ++k) {
		if (veri[k] == i) {
			return true;
		}
	}
	return false;
}



