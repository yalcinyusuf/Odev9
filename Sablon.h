/*
Yusuf YALÇIN tarafýndan yazýlmýþtýr
18120205032
16.05.2019 Perþembe */
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
	AkilliDizi(T i); /* tek elamanlý ve eleman degeri i olan bir akilli dizi olusturur
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

	unsigned kacTane(T i) const; /* veri icinde i degerinden kac tane olduðunu sayar
	TEMPLATE OLACAK*/
	bool varMi(T i) const; /* veri icinde i degeri mevcutsa dogru degilse yanlis donderir
	TEMPLATE OLACAK*/
private:
	T * veri; /* veriyi dinamik olarak tutar TEMPLATE OLACAK*/
	unsigned int kapasite; /* Kapasite doldugunda yeni alinacak yer mevcut kapasitenin yarisi
	olmali. Ýhtiyac daha

	fazlaysa ihtiyac + mevcut kapasitenin yarisi kadar

	yer alinmali.*/
	unsigned int elemanSayisi; /* dizideki mevcut eleman sayisini verir */
};

/*Akýllý dizi sýnýfýný þablon sýnýf haline getirin.Aþaðýdaki türlerle test edin.
1 - Int, double, char, Ogrenci(Ogrenci sýnýfý C - string olarak öðrenci adý ve numarasýný tutan bir sýnýftýr.
	Ogrenci sýnýfý << operatörüyle ekrana öðrenci adý ve numarasýný yazar.)
	2 - Yukarýda verilen tiplerin dizisi ve vektörleri
	Ödevde gerçeklediðiniz sýnýfý uygun þekilde test edecek main program yazýnýz.
	Bu ödevde öðrencilerin yardýmlaþmasýna izin verilmez.
	*/

