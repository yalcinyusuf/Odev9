/*
Yusuf YAL�IN taraf�ndan yaz�lm��t�r
18120205032
16.05.2019 Per�embe */
#pragma once
#include <vector>
#include <iostream>
using namespace std;
template <class T>
struct Pair 
{	
	T eleman; 
	int adet;
}; // histogramda her bir elemandan kacar adet oldugunu gosterebilecek veri tipi */
template <class T> 
class AkilliDizi /* TEMPLATE OLACAK */
{
	// Dizinin tum elemanlarini ekrana basabilecek sekilde << operatorunu asiri yukleyiniz
	/*TEMPLATE OLACAK*/
	template <class T>   
	friend ostream& operator<<(ostream & out,  AkilliDizi <T> & dizi);
public:
	AkilliDizi(); /* bos bir akilli dizi olusturur*/
	AkilliDizi(T i); /* tek elamanl� ve eleman degeri i olan bir akilli dizi olusturur
	TEMPLATE OLACAK*/
	AkilliDizi(const T * intDizi, unsigned int elemanSayisi); /* elemanSayisi elamanli bir
	akilli dizi olusturur ve intDizi elamanlarini akilli diziye atar TEMPLATE OLACAK*/
	AkilliDizi(const vector<T> & intVector); /*vektoru akilli diziye donusturur TEMPLATE OLACAK*/
	/* Dinamik bellek yonetimi icin gerekli olan fonksiyonlari yaziniz TEMPLATE OLACAK*/
	AkilliDizi(const AkilliDizi<T> & other);
	~AkilliDizi();
	AkilliDizi<T>& operator=(const AkilliDizi <T> & other);
	/* [] operatorunu asiri yukleyiniz. Verilen indeks degeri elemanSayisindan buyukse hata
	mesaji yazdirin. TEMPLATE OLACAK*/
	T& operator[](unsigned int index);
	/* Akilli diziye  bir int degeri ekleyebilecek sekilde + operatorunu yukleyin TEMPLATE
	OLACAK*/
	AkilliDizi<T>& operator+(const T&i);
	void sirala(); /* diziyi buyukten kucuge siralar TEMPLATE OLACAK*/
	void histogram(vector<Pair<T>> & hist) const; /* veri icinde gecen her bir elemanin kac kez
	oldugunu bulur ve bunu vektor<Pair> olarak donderir TEMPLATE OLACAK*/

	unsigned kacTane(T i) const; /* veri icinde i degerinden kac tane oldu�unu sayar
	TEMPLATE OLACAK*/
	bool varMi(T i) const; /* veri icinde i degeri mevcutsa dogru degilse yanlis donderir
	TEMPLATE OLACAK*/
private:
	T * veri; /* veriyi dinamik olarak tutar TEMPLATE OLACAK*/
	unsigned int kapasite; /* Kapasite doldugunda yeni alinacak yer mevcut kapasitenin yarisi
	olmali. �htiyac daha

	fazlaysa ihtiyac + mevcut kapasitenin yarisi kadar

	yer alinmali.*/
	unsigned int elemanSayisi; /* dizideki mevcut eleman sayisini verir */
};

/*Ak�ll� dizi s�n�f�n� �ablon s�n�f haline getirin.A�a��daki t�rlerle test edin.
1 - Int, double, char, Ogrenci(Ogrenci s�n�f� C - string olarak ��renci ad� ve numaras�n� tutan bir s�n�ft�r.
	Ogrenci s�n�f� << operat�r�yle ekrana ��renci ad� ve numaras�n� yazar.)
	2 - Yukar�da verilen tiplerin dizisi ve vekt�rleri
	�devde ger�ekledi�iniz s�n�f� uygun �ekilde test edecek main program yaz�n�z.
	Bu �devde ��rencilerin yard�mla�mas�na izin verilmez.
	*/

