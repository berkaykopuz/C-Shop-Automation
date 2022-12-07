/****************************************************************************

**					SAKARYA ÜNÝVERSÝTESÝ

**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ

**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ

**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ

**

**				ÖDEV NUMARASI…...: PROJE

**				ÖÐRENCÝ ADI...............: BERKAY KOPUZ

**				ÖÐRENCÝ NUMARASI.: G211210045

**				DERS GRUBU…………: BILGISAYAR MUHENDISLIGI 1.SINIF A GRUBU

****************************************************************************/

#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");
	int secim;
	int kontrol;
	string ürünKodu;
	string ürünAdi;
	string üreticisi;
	string TeminSuresi;
	double fiyat;
	double OzelFiyat;
	double kdv_Orani;
	int StokAdedi;
	string firmaNo;
	string firmaAdi;
	string firmaYetkili;
	char müsteriKategorisi;
	string adres;
	string siparisTarihi;
	double siparisTutariGenel;
	double siparisTutariOzel;
	double tutar;
	string SiparisListesi;
	string SiparisAlan;
	int miktar;
	string istenenurun;
	char cevap;
	string arananno;

	while (true) //while true dongusu ile sinirsiz donguye sokuyoruz boylece yapilmak istenen islemler surekli sorulacak.
	{
		do //3 tur islem var bunlardan birini secmek zorunlu.
		{
			cout << "   Ne yapmak istiyorsunuz ? " << endl;
			cout << "   1) Urun islemleri " << endl;
			cout << "   2) Musteri kayiti islemleri " << endl;
			cout << "   3) Siparis islemleri " << endl;
			cin >> secim;
		} while (secim != 1 && secim != 2 && secim != 3);

		if (secim == 1)

		{
			do //urun islemi icin 5 cesit ayri islem soruluyor.
			{
				cout << " Hangi islemi yapmak istiyorsunuz? " << endl;
				cout << "   1) Urun ekleme " << endl;
				cout << "   2) Urun bilgisi duzeltme" << endl;
				cout << "   3) Listeleme " << endl;
				cout << "   4) Urun aramak" << endl;
				cout << "   5) Urun kaydi silme " << endl;
				cin >> secim;
			} while (secim != 1 && secim != 2 && secim != 3 && secim != 4 && secim != 5);
			if (secim == 1) //Her bir bilgi kullanicidan istenilerek uruntxtye aralarinda bosluk olacak sekilde kaydediliyor.
			{
				kontrol = 0;
				string aranan;
				ofstream DosyaYaz("urun.txt", ios::app);
				ifstream DosyaOku("urun.txt");
				cout << "\n urun kodu      :"; cin >> ürünKodu;
				while (!DosyaOku.eof()) //her bir urun bilgisi okunarak urun kodu aranan degiskenine kaydediliyor.
				{
					DosyaOku >> aranan >> ürünAdi >> üreticisi >> TeminSuresi >> fiyat >> OzelFiyat >> kdv_Orani >> StokAdedi;
					if (aranan == ürünKodu) //eger girdigimiz urun kodu ile kayitta okunan bir kod ayni ise kontrol degiskenimiz degisti.
					{
						kontrol = 1;
					}
				}
				if (kontrol == 1) //kontrol degiskeni degisti ise ayni urun kodundan bulundugu anlamina gelir ve urun eklemeden cikar.
				{
					cout << "bu urun kodu zaten var !!!!\n"; 
					continue;
				}
				

				cout << "\n urun adi      :"; cin >> ürünAdi;
				cout << "\n urun Üreticisi   :"; cin >> üreticisi;
				cout << "\n Temin süresi     :"; cin >> TeminSuresi;
				cout << "\n Fiyatý       :"; cin >> fiyat;
				cout << "\n Özel fiyat       :"; cin >> OzelFiyat;
				cout << "\n Kdv Oraný     :"; cin >> kdv_Orani;
				cout << "\n Stok adedi    :"; cin >> StokAdedi;

				DosyaYaz << ' ' << ürünKodu << ' ' << ürünAdi << ' ' << üreticisi << ' ' << TeminSuresi << ' ' << fiyat << ' ' << OzelFiyat << ' ' << kdv_Orani << ' ' << StokAdedi;//cevabin evet olma durumunda yeniden urun eklettiriyor.
				DosyaYaz.close(); DosyaOku.close();
			}
			if (secim == 2)  //Urun dosyasindaki bilgiler sirasiyla okunuyor. Aradigimiz urun koduyla uyusuyorsa yeni bilgiler sorularak yedek.txt yerine yaziliyor. 
			{
				ofstream DosyaYaz("yedek.txt");
				ifstream DosyaOku;
				string aranan;
				DosyaOku.open("urun.txt");
				cout << "Kaydý deðiþtirilmek istenen ürünün kodu: ";
				cin >> aranan;
				while (!DosyaOku.eof())
				{
					DosyaOku >> ürünKodu >> ürünAdi >> üreticisi >> TeminSuresi >> fiyat >> OzelFiyat >> kdv_Orani >> StokAdedi;
					if (aranan == ürünKodu)
					{
						cout << "--ÜRÜN KAYDI--\n";
						cout << ürünKodu << endl;
						cout << ürünAdi << endl;
						cout << üreticisi << endl;
						cout << TeminSuresi << endl;
						cout << fiyat << endl;
						cout << OzelFiyat << endl;
						cout << kdv_Orani << endl;
						cout << StokAdedi << endl;
						cout << "\nAltta ürünün yeni kaydý için  deðerler giriniz";
						cout << "\n ürün kodu    :"; cin >> ürünKodu;
						cout << "\n urun adý   :"; cin >> ürünAdi;
						cout << "\n ürünün Üreticisi   :"; cin >> üreticisi;
						cout << "\n Temin süresi     :"; cin >> TeminSuresi;
						cout << "\n Fiyatý       :"; cin >> fiyat;
						cout << "\n Özel fiyat       :"; cin >> OzelFiyat;
						cout << "\n Kdv Oraný     :"; cin >> kdv_Orani;
						cout << "\n Stok adedi    :"; cin >> StokAdedi;
						DosyaYaz << ' ' << ürünKodu << ' ' << ürünAdi << ' ' << üreticisi << ' '
							<< TeminSuresi << ' ' << fiyat << ' ' << OzelFiyat << ' ' << kdv_Orani << ' ' << StokAdedi;
						continue; //Yeni girdigimiz degerler eklendikten sonra while dongusu basina atilarak verilerin yeniden okutulmasi saglaniyor.
					}
					DosyaYaz << ' ' << ürünKodu << ' ' << ürünAdi << ' ' << üreticisi << ' ' << TeminSuresi << ' ' << fiyat << ' ' << OzelFiyat << ' ' << kdv_Orani << ' ' << StokAdedi;
				}
				DosyaYaz.close(); DosyaOku.close();
				remove("urun.txt"); //asil dosya siliniyor.
				rename("yedek.txt", "urun.txt"); //en sonda yedek.txt urun.txt adiyla degisiliyor. Asil dosya yerine geciyor.

			}
			if (secim == 3) //listeleme icin tum veriler tek tek degiskene atilip sirasiyla yazdiriliyor.
			{

				ifstream DosyaOku;
				DosyaOku.open("urun.txt"); //urun.txt okunuyor.
				cout << "\n----TÜM ÜRÜNLER----\n";
				while (!DosyaOku.eof())
				{
					DosyaOku >> ürünKodu >> ürünAdi >> üreticisi >> TeminSuresi >> fiyat >> OzelFiyat >> kdv_Orani >> StokAdedi;
					cout << "\n ürün kodu    :" << ürünKodu;
					cout << "\n urun adý   :" << ürünAdi;
					cout << "\n ürünün Üreticisi   :" << üreticisi;
					cout << "\n Temin süresi     :" << TeminSuresi;
					cout << "\n Fiyatý       :" << fiyat;
					cout << "\n Özel fiyatý       :" << OzelFiyat;
					cout << "\n Kdv Oraný     :" << kdv_Orani;
					cout << "\n Stok adedi    :" << StokAdedi << endl;
				}
				DosyaOku.close();
			}
			if (secim == 4)
			{
				kontrol = 0; //kontrol degeri her secim basinda sifirlaniyor.
				ifstream DosyaOku;
				DosyaOku.open("urun.txt");
				string aranan;
				cout << "Öðrenilmek istenen ürünün kodu:"; cin >> aranan;
				while (!DosyaOku.eof())
				{
					DosyaOku >> ürünKodu >> ürünAdi >> üreticisi >> TeminSuresi >> fiyat >> OzelFiyat >> kdv_Orani >> StokAdedi;
					if (aranan == ürünKodu) //ogrenilmek istenen urun bulunduysa aktarilan degiskenler sirasiyla yazdiriliyor. 
					{
						kontrol = 1; //urun bulundu ise kontrol degiskeni  degerini aldi.

						cout << "--ARANAN ÜRÜNÜN KAYDI--\n";
						cout << "ürün kodu:	" << ürünKodu << endl;
						cout << "ürün adý:	" << ürünAdi << endl;
						cout << "üreticisi:	" << üreticisi << endl;
						cout << "temin süresi:	" << TeminSuresi << endl;
						cout << "fiyatý:	" << fiyat << endl;
						cout << "özel fiyatý:	" << OzelFiyat << endl;
						cout << "kdv oraný:	" << kdv_Orani << endl;
						cout << "stok adedi:	" << StokAdedi << endl;
					}

				}

				if (kontrol == 0) //kontrol sifir olarak kaldiysa urun bulunamadigi, if icine giremedigi anlamýna gelir.
				{
					cout << "urun bulunamadi!!!!\n";
				}
				DosyaOku.close();
			}
			if (secim == 5) //silinmek istenen urunun kodu ortusuyorsa o kismi es gecip yedege yazdirmiyor. Diger tum urunler ise yedege yazdiriliyor.
			{
				ifstream DosyaOku("urun.txt");
				ofstream DosyaYaz("yedek.txt");
				string aranan;
				cout << "Silinmek istenen ürünün ilgili kodu: "; cin >> aranan;
				while (!DosyaOku.eof())
				{
					DosyaOku >> ürünKodu >> ürünAdi >> üreticisi >> TeminSuresi >> fiyat >> OzelFiyat >> kdv_Orani >> StokAdedi;

					if (aranan == ürünKodu)
					{
						cout << "Silme baþarýlý.\n";
						continue;
					}
					DosyaYaz << ' ' << ürünKodu << ' ' << ürünAdi << ' ' << üreticisi << ' '
						<< TeminSuresi << ' ' << fiyat << ' ' << OzelFiyat << ' ' << kdv_Orani << ' ' << StokAdedi;
				}
				DosyaOku.close();
				DosyaYaz.close();
				remove("urun.txt");
				rename("yedek.txt", "urun.txt"); //yedek dosya asil dosya yerine gecirildi.
			}
			secim = 0;
		}
		if (secim == 2) //firma islemleri.
		{
			do  //urun islemleri mantigi ile birebir ayni calisiyor.
			{
				cout << " Hangi islemi yapmak istiyorsunuz? " << endl;
				cout << "   1) Musteri ekleme " << endl;
				cout << "   2) Musteri arama" << endl;
				cout << "   3) Musteri kaydi duzeltme" << endl;
				cout << "   4) Musteri kaydi silme" << endl;
				cin >> secim;
			} while (secim != 1 && secim != 2 && secim != 3 && secim != 4);
			if (secim == 1)
			{

				ofstream DosyaYaz;
				DosyaYaz.open("cari.txt", ios::app);

				do
				{
					cout << "\n firma numarasý      :"; cin >> firmaNo;
					cout << "\n firma adi     :"; cin >> firmaAdi;
					cout << "\n firma yetkilisi     :"; cin >> firmaYetkili;
					cout << "\n (genel/ozel)(g/o seciniz)müsteri kategorisi  :"; cin >> müsteriKategorisi;
					cout << "\n adres       :"; cin >> adres;

					DosyaYaz << ' ' << firmaNo << ' ' << firmaAdi << ' ' << firmaYetkili << ' ' << müsteriKategorisi << ' ' << adres;
					cout << "yeniden kayit girmek ister misiniz?(e/h)"; cin >> cevap;
				} while (!(cevap == 'h'));
				DosyaYaz.close();
				cout << "dosyaya yazim tamamlandi. " << endl;
			}
			if (secim == 2)
			{
				kontrol = 0;
				ifstream DosyaOku;
				DosyaOku.open("cari.txt");
				string aranan;
				cout << "Öðrenilmek istenen firmanýn numarasý:"; cin >> aranan;
				while (!DosyaOku.eof())
				{
					DosyaOku >> firmaNo >> firmaAdi >> firmaYetkili >> müsteriKategorisi >> adres;
					if (aranan == firmaNo)
					{
						kontrol = 1;
						cout << "\n--ARANAN FÝRMA KAYDI--\n";
						cout << "firma numarasý:	" << firmaNo << endl;
						cout << "firma adý	" << firmaAdi << endl;
						cout << "firma yetkilisi:	" << firmaYetkili << endl;
						cout << "müþteri kategorisi:	" << müsteriKategorisi << endl;
						cout << "adresi:	" << adres << endl;

					}
				}
				if (kontrol == 0)
					cout << "Böyle bir firma bulunamadý!!!!\n";
				DosyaOku.close();
			}
			if (secim == 3)
			{
				ofstream DosyaYaz("yedek.txt");
				ifstream DosyaOku;
				string aranan;
				DosyaOku.open("cari.txt");
				cout << "Kaydý deðiþtirilmek istenen firma numarasý: ";
				cin >> aranan;
				while (!DosyaOku.eof()) //sirasiyla firma bilgileri okunuyor.
				{
					DosyaOku >> firmaNo >> firmaAdi >> firmaYetkili >> müsteriKategorisi >> adres;

					if (aranan == firmaNo) //kullanicinin girdigi veriyle firma no ortusuyor mu bakiliyor.Ortusuyor iste yeni veriler kaydediiliyor.
					{
						cout << "--FÝRMA KAYDI--\n";
						cout << firmaNo << endl;
						cout << firmaAdi << endl;
						cout << firmaYetkili << endl;
						cout << müsteriKategorisi << endl;
						cout << adres << endl;
						cout << "\nAltta müþterinin yeni kaydý için deðerler giriniz";
						cout << "\n firma numarasý    :"; cin >> firmaNo;
						cout << "\n firma adý   :"; cin >> firmaAdi;
						cout << "\n firma yetkilisi   :"; cin >> firmaYetkili;
						cout << "\n müþteri kategorisi (o/g)    :"; cin >> müsteriKategorisi;
						cout << "\n adresi      :"; cin >> adres;

						DosyaYaz << ' ' << firmaNo << ' ' << firmaAdi << ' ' << firmaYetkili << ' '
							<< müsteriKategorisi << ' ' << adres;
						continue; //kullanicinin yeni guncelledigi firma bilgileri yedege yazdiriliyor. sonra da dongu basina atiliyor.
					}
					DosyaYaz << ' ' << firmaNo << ' ' << firmaAdi << ' ' << firmaYetkili << ' '
						<< müsteriKategorisi << ' ' << adres;  //kullanicinin girdigi ortusmuyorsa mevcut veri yedege yazdirildi.
				}
				DosyaYaz.close(); DosyaOku.close();
				remove("cari.txt"); //asil dosya kaldirildi. yedegin ismi degistirilip asil hale geldi.
				rename("yedek.txt", "cari.txt");
			}
			if (secim == 4) //ustteki secimle ayni mantiktadir. tek fark olarak istenen firma eslesti ise o kisim es geciliyor. Diger tum kisimlar ise yedege yazdiriliyor.
			{
				ifstream DosyaOku("cari.txt");
				ofstream DosyaYaz("yedek.txt");
				string aranan;
				cout << "Silinmek istenen firmanýn ilgili numarasý: "; cin >> aranan;
				while (!DosyaOku.eof())
				{
					DosyaOku >> firmaNo >> firmaAdi >> firmaYetkili >> müsteriKategorisi >> adres;

					if (aranan == firmaNo)
					{
						cout << "Silme baþarýlý.";
						continue;
					}
					DosyaYaz << ' ' << firmaNo << ' ' << firmaAdi << ' ' << firmaYetkili << ' '
						<< müsteriKategorisi << ' ' << adres;
				}
				DosyaOku.close();
				DosyaYaz.close();
				remove("cari.txt");
				rename("yedek.txt", "cari.txt");
			}
			secim = 0;
		}
		if (secim == 3)
		{
			do
			{
				cout << " Hangi islemi yapmak istiyorsunuz? " << endl;
				cout << "   1) Siparis olusturma " << endl;
				cout << "   2) Siparis arama" << endl;
				cout << "   3) Siparis kaydi silme" << endl;
				cout << "   4) Siparis kaydi duzeltme" << endl;
				cout << "   5) Siparis raporlama" << endl;
				cin >> secim;
			} while (secim != 1 && secim != 2 && secim != 3 && secim != 4 && secim != 5);
			if (secim == 1)
			{
				string gecicikod;
				string FirmaNo;
				cout << "siparis vermek isteyen firmanýn numarasý : "; cin >> FirmaNo;	//siparis vermek isteyen firma no soruldu.
				ifstream DosyaOku("cari.txt");
				ifstream UrunOku("urun.txt");
				while (!DosyaOku.eof())
				{
					DosyaOku >> firmaNo >> firmaAdi >> firmaYetkili >> müsteriKategorisi >> adres;

					if (FirmaNo == firmaNo) //firma no ortustu ise bilgileri gosterilerek istenen urun soruldu.
					{

						cout << "\n Firma bilgileri \n";
						cout << " firma no   :" << firmaNo << endl;
						cout << " firma adi      :" << firmaAdi << endl;
						cout << " firma yetkilisi  :" << firmaYetkili << endl;
						cout << " kategorisi:" << müsteriKategorisi << endl;
						cout << " adresi :" << adres << endl;
						cout << "istenen urunun kodu: "; cin >> gecicikod;
						while (!UrunOku.eof())
						{
							UrunOku >> ürünKodu >> ürünAdi >> üreticisi >> TeminSuresi >> fiyat >> OzelFiyat >> kdv_Orani >> StokAdedi;

							if (gecicikod == ürünKodu) //ilgili firmanin siparis vermek istedigi urun kodu soruldu. Ortusuyor mu diye bakiliyor.
							{
								cout << "sipariþ tarihi:  "; cin >> siparisTarihi;
								cout << "sipariþ etmek istenen miktar: "; cin >> miktar;
								if (müsteriKategorisi == 'g') //bu kisimlarda musterinin kategorisine ozel tutar hesaplaniyor.
								{
									siparisTutariGenel = fiyat * miktar;
								}
								else if (müsteriKategorisi == 'o')
								{
									siparisTutariOzel
										= OzelFiyat * miktar;
								}
								SiparisAlan = firmaAdi; //siparisi alan firmanin adi olarak tutuldu.

								ofstream DosyaYaz2;
								DosyaYaz2.open("siparis.txt", ios::app);
								if (müsteriKategorisi == 'o') //kategoriye ozel olarak siparis.txt dosyasina yazdiriliyor.
								{
									DosyaYaz2 << ' ' << firmaNo << ' ' << ürünKodu << ' ' << siparisTarihi << ' ' << siparisTutariOzel << ' ' << SiparisAlan;

								}
								else if (müsteriKategorisi == 'g')
								{
									DosyaYaz2 << ' ' << firmaNo << ' ' << ürünKodu << ' ' << siparisTarihi << ' ' << siparisTutariGenel << ' ' << SiparisAlan;

								}
								DosyaYaz2.close();

								ifstream DosyaOku2("siparis.txt");

								if (müsteriKategorisi == 'o')
								{
									while (!DosyaOku2.eof())
									{
										DosyaOku2 >> firmaNo >> ürünKodu >> siparisTarihi >> siparisTutariOzel >> SiparisAlan;
									}

									cout << "\n----VERÝLEN SÝPARÝS HAKKÝNDA----\n" << endl;
									cout << "siparis veren firma numarasý:  " << firmaNo << endl;
									cout << "sipariþi verilen ürün kodu:	" << ürünKodu << endl;
									cout << "siparis tarihi: " << siparisTarihi << endl;
									cout << "siparis tutari: " << siparisTutariOzel << endl;
									cout << "siparisi alan firma adý:   " << SiparisAlan << endl;
								}
								if (müsteriKategorisi == 'g')
								{
									while (!DosyaOku2.eof())
									{
										DosyaOku2 >> firmaNo >> ürünKodu >> siparisTarihi >> siparisTutariGenel >> SiparisAlan;
									}

									cout << "\n----VERÝLEN SÝPARÝS HAKKÝNDA----\n" << endl;
									cout << "siparis veren firma numarasý:  " << firmaNo << endl;
									cout << "sipariþi verilen ürün kodu:	" << ürünKodu << endl;
									cout << "sipariþ tarihi: " << siparisTarihi << endl;
									cout << "sipariþ tutari: " << siparisTutariGenel << endl;
									cout << "sipariþi alan firma adý:   " << SiparisAlan << endl;

								}
								DosyaOku2.close();
								cout << endl;
								break;
							}

						}

					}

				}
				DosyaOku.close(); UrunOku.close();
			}

			if (secim == 2)
			{
				ifstream DosyaOku("siparis.txt");
				cout << "Sipariþi öðrenilmek istenen firma numarasý:	"; cin >> arananno; //Hangi firmanin siparislerini ogrenmek istiyorsak soruluyor.
				while (!DosyaOku.eof()) //ortusen firma numarasi ile o firmanin ne siparisi varsa yazdiriliyor.
				{
					DosyaOku >> firmaNo >> ürünKodu >> siparisTarihi >> tutar >> SiparisAlan;
					if (arananno == firmaNo)
					{
						cout << "\nsipariþi veren firma no:	" << firmaNo << endl;
						cout << "sipariþi verilen ürün kodu:	" << ürünKodu << endl;
						cout << "sipariþ tarihi:	" << siparisTarihi << endl;
						cout << "sipariþ tutarý: " << tutar << endl;
						cout << "sipariþi alan: " << SiparisAlan << endl << endl;
					}
				}
				DosyaOku.close();
			}
			if (secim == 3)
			{
				string deneme;
				ifstream DosyaOku("siparis.txt");
				ofstream DosyaYaz("yedek.txt");
				cout << "Hangi firmanýn sipariþini silmek istiyorsunuz? Firma No giriniz:	"; cin >> arananno;
				cout << "Hangi ürünün sipariþini silmek istersiniz? Ürün kodu giriniz:	"; cin >> deneme; //Siparisi bulabilmek icin firma ve onun siparis verdigi urunun kodundan faydalaniyoruz.
				while (!DosyaOku.eof())
				{
					DosyaOku >> firmaNo >> ürünKodu >> siparisTarihi >> tutar >> SiparisAlan;
					if (arananno == firmaNo)
					{

						if (deneme == ürünKodu)
						{
							cout << "silme basarili!!\n"; //firma ve urun kodu ortusuyorsa bu kisim yedege yazdirilmiyor.
							continue;
						}
					}
					DosyaYaz << ' ' << firmaNo << ' ' << ürünKodu << ' ' << siparisTarihi << ' ' << tutar << ' ' << SiparisAlan;
				}
				DosyaYaz.close(); DosyaOku.close();
				remove("siparis.txt"); //siparis dosyasi kaldirildi yeni yazilan yedek dosyasi onun yerine gecti.
				rename("yedek.txt", "siparis.txt");
			}
			if (secim == 4)
			{
				string arananno2;
				string arananno3;
				string arananno4;
				ifstream UrunOku("urun.txt"); //her bir txt icin ozel okuyucu ve yazicilar tanimlandi.
				ifstream DosyaOku("siparis.txt");
				ifstream DosyaOku2("cari.txt");
				ofstream DosyaYaz("yedek.txt", ios::app);
				cout << "Hangi firmanýn sipariþini düzeltmek istersiniz? Firma no giriniz:	"; cin >> arananno;
				cout << "Hangi ürünün sipariþini düzeltmek istersiniz? Ürün no giriniz:		"; cin >> arananno2;
				while (!DosyaOku.eof())
				{
					DosyaOku >> firmaNo >> ürünKodu >> siparisTarihi >> tutar >> SiparisAlan; //siparis dosyasi verileri sirasiyla okundu.
					if (arananno == firmaNo)
					{

						if (arananno2 == ürünKodu) //aradigimiz firma ve onun urun siparisi bulunduysa komple yeni bilgiler sorulacak.
						{
							cout << "Sipariþ bulundu.\n" << "Sipariþ için yeni bir firma no giriniz:	"; cin >> arananno3;
							cout << "\nFirma No bulundu. Sipariþ için yeni bir ürün kodu giriniz:		"; cin >> arananno4;
							while (!DosyaOku2.eof())
							{
								DosyaOku2 >> firmaNo >> firmaAdi >> firmaYetkili >> müsteriKategorisi >> adres;
								if (arananno3 == firmaNo)
								{
									SiparisAlan = firmaAdi;
									while (!UrunOku.eof())
									{
										UrunOku >> ürünKodu >> ürünAdi >> üreticisi >> TeminSuresi >> fiyat >> OzelFiyat >> kdv_Orani >> StokAdedi;
										if (arananno4 == ürünKodu) //sordugumuz yeni firma no ve istedigi urun bilgileri diger txtlerden okunarak uyusuyor mu diye bakildi degerleri ogrenildi.
										{

											cout << "sipariþ tarihi:	"; cin >> siparisTarihi;
											cout << "üründen istenilen miktar:	"; cin >> miktar;
											if (müsteriKategorisi == 'g') //musteri kategorisine ozel tutar belirleniyor.
											{
												tutar = fiyat * miktar;
											}
											if (müsteriKategorisi == 'o')
											{
												tutar = OzelFiyat * miktar;
											}
											DosyaYaz << ' ' << firmaNo << ' ' << ürünKodu << ' ' << siparisTarihi << ' ' << tutar << ' ' << SiparisAlan;
											break; //yeni girdigimiz degerler yedege kaydediliyor. break ve continue komutlari ile fazladan yazdirmamasi icin dongu basina alinarak yeni veriler okunuyor.
										}
									}
								}

							}
							continue;
						}

					}
					DosyaYaz << ' ' << firmaNo << ' ' << ürünKodu << ' ' << siparisTarihi << ' ' << tutar << ' ' << SiparisAlan; //girilen degerler hic ortusmedigi takdirde degistirilmeden yedege kaydediliyor.
				}
				DosyaYaz.close(); DosyaOku.close(); DosyaOku2.close(); UrunOku.close();
				remove("siparis.txt");
				rename("yedek.txt", "siparis.txt");
				cout << "islem basariyla tamamlandi.\n";
			}

			if (secim == 5)
			{
				ifstream DosyaOku("siparis.txt");
				cout << "----Verilen Sipariþler Hakkýnda----\n";
				while (!DosyaOku.eof())
				{
					DosyaOku >> firmaNo >> ürünKodu >> siparisTarihi >> tutar >> SiparisAlan; //verilen siparis verileri tek tek okunarak yazdirildi.
					cout << "\nsipariþi veren firma numarasý:	" << firmaNo << endl;
					cout << "sipariþi verilen ürünün kodu: " << ürünKodu << endl;
					cout << "sipariþ tarihi:	" << siparisTarihi << endl;
					cout << "tutar:	" << tutar << endl;
					cout << "sipariþi alan:	" << SiparisAlan << endl;
				}
				DosyaOku.close();
			}
			secim = 0; //her bir secim sonunda secim degiskeni sifirlanarak while dongusunun basina atmaya ve baska secimlere karismamaya yariyor. 
		}


	}











	return 0;
}