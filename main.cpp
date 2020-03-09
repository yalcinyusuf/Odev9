/*
Yusuf YALÇIN tarafýndan yazýlmýþtýr
18120205032
16.05.2019 Perþembe */
#include <vector>
#include <iostream>
#include "Sablon.cpp"

using namespace std;

class Ogrenci
{
	friend ostream & operator<<(ostream & output, const Ogrenci& s);
public:
	Ogrenci();
	Ogrenci(const char * str,const char * num);
	~Ogrenci(); 
	const Ogrenci & operator=(const Ogrenci & other);
	Ogrenci(const Ogrenci & other); // Copy Constructor
	bool operator==(const Ogrenci & other) const;
	bool operator <(const Ogrenci& s1)const; 
	bool operator >(const Ogrenci& s1) const;
private:
	char * ogrenciAdi;
	char * numarasi;
	unsigned int adUzunluk;
	unsigned int numaraUzunluk;
};
ostream & operator<<(ostream & output, const Ogrenci & s)
{
	output << " Ogrencinin Numarasi: ";
	for (unsigned int i = 0; i < s.numaraUzunluk; ++i) {
		output << s.numarasi[i];
	}
	output << " Ogrencinin Adi: ";
	for (unsigned int i = 0; i < s.adUzunluk; ++i) {
		output  << s.ogrenciAdi[i];
	}
	output << endl;
	
	return output;
}

Ogrenci::Ogrenci()
{
	ogrenciAdi = nullptr;
	numarasi = nullptr;
	adUzunluk = 0;
	numaraUzunluk = 0;
}

Ogrenci::Ogrenci(const char * str, const char * num)
{

	adUzunluk = strnlen_s(str, 20);
	numaraUzunluk = strnlen_s(num, 20);
	ogrenciAdi = nullptr;
	numarasi = nullptr;
	if (numaraUzunluk > 0 && adUzunluk > 0) {
		ogrenciAdi = new char[adUzunluk];
		numarasi = new char[numaraUzunluk];
		if (ogrenciAdi == nullptr && numarasi == nullptr)
			exit(-1);

		for (unsigned i = 0; i < adUzunluk; ++i)
		{
			ogrenciAdi[i] = str[i];
		}
		for (unsigned i = 0; i < numaraUzunluk; ++i)
		{
			numarasi[i] = num[i];
		}
	}
}

Ogrenci::~Ogrenci()
{
	cout << "Ogrenci destructoru cagrildi" << endl;
	if (ogrenciAdi != nullptr && numarasi != nullptr)
		delete[] ogrenciAdi;
		delete[] numarasi;
}
const Ogrenci & Ogrenci::operator=(const Ogrenci & other)
{
	if (this == &other)
		return *this;

	if (ogrenciAdi == nullptr && numarasi == nullptr)
		delete[] ogrenciAdi;
		delete[] numarasi;

	adUzunluk = other.adUzunluk;
	numaraUzunluk = other.numaraUzunluk;

	ogrenciAdi = new char[adUzunluk];
	numarasi = new char[numaraUzunluk];
	if (ogrenciAdi == nullptr && numarasi == nullptr)
		exit(-1);
	for (unsigned i = 0; i < adUzunluk; ++i)
	{
		ogrenciAdi[i] = other.ogrenciAdi[i];
	}
	for (unsigned i = 0; i < numaraUzunluk; ++i)
	{
		numarasi[i] = other.numarasi[i];
	}
	return *this;

}
Ogrenci::Ogrenci(const Ogrenci & other)
{
	adUzunluk = other.adUzunluk;
	numaraUzunluk = other.numaraUzunluk;
	ogrenciAdi = nullptr;
	numarasi = nullptr;
	if (numaraUzunluk != 0 && adUzunluk != 0)
	{ 
		ogrenciAdi = new char[adUzunluk];
		numarasi = new char[numaraUzunluk];
		if (ogrenciAdi == nullptr && numarasi == nullptr)
			exit(-1);
		for (unsigned i = 0; i < adUzunluk; ++i)
		{
			ogrenciAdi[i] = other.ogrenciAdi[i];
		}
		for (unsigned i = 0; i < numaraUzunluk; ++i)
		{
			numarasi[i] = other.numarasi[i];
		}
	}
}
bool Ogrenci::operator==(const Ogrenci & other) const
{
	if (numaraUzunluk != other.numaraUzunluk)
		return false;
	for (unsigned i = 0; i < numaraUzunluk; ++i)
		if (numarasi[i] != other.numarasi[i])
			return false;
	return true;
}
bool Ogrenci::operator<(const Ogrenci & s1) const
{
	if (numaraUzunluk > s1.numaraUzunluk)
		return false;
	for (unsigned i = 0; i < numaraUzunluk; ++i)
		if (numarasi[i] > s1.numarasi[i])
			return false; 
	return true;

}
bool Ogrenci::operator>(const Ogrenci & s1) const
{
	if (numaraUzunluk < s1.numaraUzunluk)
		return false;
	for (unsigned i = 0; i < numaraUzunluk; ++i)
		if (numarasi[i] < s1.numarasi[i])
			return false;
	return true;
}
int main() {
	cout << "\n\t\t\tHOSGELDINIZ!!" << endl << endl;
	Ogrenci ee("yusuf","1234");
	Ogrenci uu("yalcin", "1233");
	cout << " Ogrencinin << operatoru ve iki parametreli constructori calismaktadir" << endl;
	vector<Ogrenci> xx;
	xx.push_back(ee);
	Ogrenci oo("yusuf","1234");
	cout << oo;
	cout << "####################" << endl;
	cout << " Ogrenci copy constructor test edilmekte,ee icin" << endl;
	Ogrenci zz = ee;
	cout << zz << endl;
	cout << "####################" << endl;
	cout << " Ogrenci assignment operator test edilmekte" << endl;
	zz= uu;
	cout << zz << endl;
	cout << "####################" << endl;
	cout << "Ogrenci bool >" << endl;
	if (oo > uu)cout << "oo > uu" << endl;
	cout << "####################" << endl;
	cout << "Ogrenci bool <" << endl;
	if (uu < oo)cout << "uu < oo" << endl;
	cout << "####################" << endl;
	cout << "Ogrenci bool ==" << endl;
	if (ee == oo)cout << "ee == oo" << endl;
	cout << "####################" << endl;
	cout << "Default constructor calismaktadir" << endl;
	AkilliDizi<int> y;
	cout << y << endl;
	cout << "####################" << endl;
	cout << "<< operatoru calismaktadir , tek parametre ile vektor(ogrenci icin) alan constructor calismaktadir" << endl << endl;
	AkilliDizi<Ogrenci> r(xx);
	AkilliDizi<int> a(2);
	AkilliDizi<int> x(5);
	AkilliDizi<double> d(2.5);
	AkilliDizi<char> cc('c');
	cout << " Ogrenci sinif tipinde: " << r;
	cout << " int tipinde: " << a << endl;
	cout << " double tipinde: " << d << endl;
	cout << " char tipinde: " << cc << endl;
	cout << "####################" << endl;
	cout << "<< operatoru calismaktadir ve iki parametre alan constructor calismaktadir" << endl;
	int dizi[3] = { 1,2,3 };
	AkilliDizi<int> b(dizi, 3);
	cout << b << endl;
	cout << "####################" << endl;
	cout << "Copy constructor test edilmekte,a(2) icin" << endl;
	AkilliDizi<int> c = a;
	cout << c << endl;
	cout << "####################" << endl;
	cout << "Assignment operator test edilmekte" << endl;
	c = x;
	cout << c << endl;
	cout << "####################" << endl;
	cout << "<< operatoru  ve vector alan constructor calismaktadir "<< endl;
	vector<int> diziVector;
	vector<char> diziVector2;
	diziVector2.push_back('c');
	diziVector2.push_back('d');
	diziVector2.push_back('a');
	AkilliDizi<char> akillidizi2(diziVector2);
	for (int i = 0; i < 10; ++i) {
		diziVector.push_back(i);
	}
	for (int i = 0; i < 5; ++i) {
		diziVector.push_back(i);
	}
	AkilliDizi<int> akillidizi1(diziVector);
	cout << akillidizi1 << endl;
	cout << "####################" << endl;
	cout << "histogram test edilmekte" << endl;
	vector<Pair<int>> p;
	akillidizi1.histogram(p);
	for (unsigned i = 0; i < p.size(); i++) {
		cout << p[i].eleman << "  " << p[i].adet << " tane"<< endl;
	}
	vector<Pair<char>> p2;
	akillidizi2.histogram(p2);
	for (unsigned i = 0; i < p2.size(); i++) {
		cout << p2[i].eleman << "  " << p2[i].adet << " tane" << endl;
	}
	cout << "####################" << endl;
	cout << "kactane test edilmekte" << endl;
	cout << "2 sayisindan " << akillidizi1.kacTane(2) << " tane var" << endl;
	cout << "####################" << endl;
	cout << "varMi test edilmekte" << endl;
	cout << "2 sayisi " << akillidizi1.varMi(2) << "(true) yani vardir" << endl;
	cout << "####################" << endl;
	cout << "operator[],2 sayisi ile  test edilmekte" << endl;
	cout << "veri[2] = " << akillidizi1.operator[](2) << endl;
	cout << "####################" << endl;
	cout << "sirala test edilmekte buyukten kucuge" << endl;
	akillidizi1.sirala();
	akillidizi2.sirala();
	cout << "####################" << endl;
	cout << "(int)5'i akilli diziye ekleyecek sekilde operator+ test edilmekte" << endl;
	cout <<  akillidizi1.operator+(5);
	cout << "####################" << endl;
	return 0;
}

