/****************************************************************************

**					SAKARYA �N�VERS�TES�

**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�

**				    B�LG�SAYAR M�HEND�SL��� B�L�M�

**				          PROGRAMLAMAYA G�R��� DERS�

**

**				�DEV NUMARASI�...: PROJE

**				��RENC� ADI...............: BERKAY KOPUZ

**				��RENC� NUMARASI.: G211210045

**				DERS GRUBU����: BILGISAYAR MUHENDISLIGI 1.SINIF A GRUBU

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
	string �r�nKodu;
	string �r�nAdi;
	string �reticisi;
	string TeminSuresi;
	double fiyat;
	double OzelFiyat;
	double kdv_Orani;
	int StokAdedi;
	string firmaNo;
	string firmaAdi;
	string firmaYetkili;
	char m�steriKategorisi;
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
				cout << "\n urun kodu      :"; cin >> �r�nKodu;
				while (!DosyaOku.eof()) //her bir urun bilgisi okunarak urun kodu aranan degiskenine kaydediliyor.
				{
					DosyaOku >> aranan >> �r�nAdi >> �reticisi >> TeminSuresi >> fiyat >> OzelFiyat >> kdv_Orani >> StokAdedi;
					if (aranan == �r�nKodu) //eger girdigimiz urun kodu ile kayitta okunan bir kod ayni ise kontrol degiskenimiz degisti.
					{
						kontrol = 1;
					}
				}
				if (kontrol == 1) //kontrol degiskeni degisti ise ayni urun kodundan bulundugu anlamina gelir ve urun eklemeden cikar.
				{
					cout << "bu urun kodu zaten var !!!!\n"; 
					continue;
				}
				

				cout << "\n urun adi      :"; cin >> �r�nAdi;
				cout << "\n urun �reticisi   :"; cin >> �reticisi;
				cout << "\n Temin s�resi     :"; cin >> TeminSuresi;
				cout << "\n Fiyat�       :"; cin >> fiyat;
				cout << "\n �zel fiyat       :"; cin >> OzelFiyat;
				cout << "\n Kdv Oran�     :"; cin >> kdv_Orani;
				cout << "\n Stok adedi    :"; cin >> StokAdedi;

				DosyaYaz << ' ' << �r�nKodu << ' ' << �r�nAdi << ' ' << �reticisi << ' ' << TeminSuresi << ' ' << fiyat << ' ' << OzelFiyat << ' ' << kdv_Orani << ' ' << StokAdedi;//cevabin evet olma durumunda yeniden urun eklettiriyor.
				DosyaYaz.close(); DosyaOku.close();
			}
			if (secim == 2)  //Urun dosyasindaki bilgiler sirasiyla okunuyor. Aradigimiz urun koduyla uyusuyorsa yeni bilgiler sorularak yedek.txt yerine yaziliyor. 
			{
				ofstream DosyaYaz("yedek.txt");
				ifstream DosyaOku;
				string aranan;
				DosyaOku.open("urun.txt");
				cout << "Kayd� de�i�tirilmek istenen �r�n�n kodu: ";
				cin >> aranan;
				while (!DosyaOku.eof())
				{
					DosyaOku >> �r�nKodu >> �r�nAdi >> �reticisi >> TeminSuresi >> fiyat >> OzelFiyat >> kdv_Orani >> StokAdedi;
					if (aranan == �r�nKodu)
					{
						cout << "--�R�N KAYDI--\n";
						cout << �r�nKodu << endl;
						cout << �r�nAdi << endl;
						cout << �reticisi << endl;
						cout << TeminSuresi << endl;
						cout << fiyat << endl;
						cout << OzelFiyat << endl;
						cout << kdv_Orani << endl;
						cout << StokAdedi << endl;
						cout << "\nAltta �r�n�n yeni kayd� i�in  de�erler giriniz";
						cout << "\n �r�n kodu    :"; cin >> �r�nKodu;
						cout << "\n urun ad�   :"; cin >> �r�nAdi;
						cout << "\n �r�n�n �reticisi   :"; cin >> �reticisi;
						cout << "\n Temin s�resi     :"; cin >> TeminSuresi;
						cout << "\n Fiyat�       :"; cin >> fiyat;
						cout << "\n �zel fiyat       :"; cin >> OzelFiyat;
						cout << "\n Kdv Oran�     :"; cin >> kdv_Orani;
						cout << "\n Stok adedi    :"; cin >> StokAdedi;
						DosyaYaz << ' ' << �r�nKodu << ' ' << �r�nAdi << ' ' << �reticisi << ' '
							<< TeminSuresi << ' ' << fiyat << ' ' << OzelFiyat << ' ' << kdv_Orani << ' ' << StokAdedi;
						continue; //Yeni girdigimiz degerler eklendikten sonra while dongusu basina atilarak verilerin yeniden okutulmasi saglaniyor.
					}
					DosyaYaz << ' ' << �r�nKodu << ' ' << �r�nAdi << ' ' << �reticisi << ' ' << TeminSuresi << ' ' << fiyat << ' ' << OzelFiyat << ' ' << kdv_Orani << ' ' << StokAdedi;
				}
				DosyaYaz.close(); DosyaOku.close();
				remove("urun.txt"); //asil dosya siliniyor.
				rename("yedek.txt", "urun.txt"); //en sonda yedek.txt urun.txt adiyla degisiliyor. Asil dosya yerine geciyor.

			}
			if (secim == 3) //listeleme icin tum veriler tek tek degiskene atilip sirasiyla yazdiriliyor.
			{

				ifstream DosyaOku;
				DosyaOku.open("urun.txt"); //urun.txt okunuyor.
				cout << "\n----T�M �R�NLER----\n";
				while (!DosyaOku.eof())
				{
					DosyaOku >> �r�nKodu >> �r�nAdi >> �reticisi >> TeminSuresi >> fiyat >> OzelFiyat >> kdv_Orani >> StokAdedi;
					cout << "\n �r�n kodu    :" << �r�nKodu;
					cout << "\n urun ad�   :" << �r�nAdi;
					cout << "\n �r�n�n �reticisi   :" << �reticisi;
					cout << "\n Temin s�resi     :" << TeminSuresi;
					cout << "\n Fiyat�       :" << fiyat;
					cout << "\n �zel fiyat�       :" << OzelFiyat;
					cout << "\n Kdv Oran�     :" << kdv_Orani;
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
				cout << "��renilmek istenen �r�n�n kodu:"; cin >> aranan;
				while (!DosyaOku.eof())
				{
					DosyaOku >> �r�nKodu >> �r�nAdi >> �reticisi >> TeminSuresi >> fiyat >> OzelFiyat >> kdv_Orani >> StokAdedi;
					if (aranan == �r�nKodu) //ogrenilmek istenen urun bulunduysa aktarilan degiskenler sirasiyla yazdiriliyor. 
					{
						kontrol = 1; //urun bulundu ise kontrol degiskeni  degerini aldi.

						cout << "--ARANAN �R�N�N KAYDI--\n";
						cout << "�r�n kodu:	" << �r�nKodu << endl;
						cout << "�r�n ad�:	" << �r�nAdi << endl;
						cout << "�reticisi:	" << �reticisi << endl;
						cout << "temin s�resi:	" << TeminSuresi << endl;
						cout << "fiyat�:	" << fiyat << endl;
						cout << "�zel fiyat�:	" << OzelFiyat << endl;
						cout << "kdv oran�:	" << kdv_Orani << endl;
						cout << "stok adedi:	" << StokAdedi << endl;
					}

				}

				if (kontrol == 0) //kontrol sifir olarak kaldiysa urun bulunamadigi, if icine giremedigi anlam�na gelir.
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
				cout << "Silinmek istenen �r�n�n ilgili kodu: "; cin >> aranan;
				while (!DosyaOku.eof())
				{
					DosyaOku >> �r�nKodu >> �r�nAdi >> �reticisi >> TeminSuresi >> fiyat >> OzelFiyat >> kdv_Orani >> StokAdedi;

					if (aranan == �r�nKodu)
					{
						cout << "Silme ba�ar�l�.\n";
						continue;
					}
					DosyaYaz << ' ' << �r�nKodu << ' ' << �r�nAdi << ' ' << �reticisi << ' '
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
					cout << "\n firma numaras�      :"; cin >> firmaNo;
					cout << "\n firma adi     :"; cin >> firmaAdi;
					cout << "\n firma yetkilisi     :"; cin >> firmaYetkili;
					cout << "\n (genel/ozel)(g/o seciniz)m�steri kategorisi  :"; cin >> m�steriKategorisi;
					cout << "\n adres       :"; cin >> adres;

					DosyaYaz << ' ' << firmaNo << ' ' << firmaAdi << ' ' << firmaYetkili << ' ' << m�steriKategorisi << ' ' << adres;
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
				cout << "��renilmek istenen firman�n numaras�:"; cin >> aranan;
				while (!DosyaOku.eof())
				{
					DosyaOku >> firmaNo >> firmaAdi >> firmaYetkili >> m�steriKategorisi >> adres;
					if (aranan == firmaNo)
					{
						kontrol = 1;
						cout << "\n--ARANAN F�RMA KAYDI--\n";
						cout << "firma numaras�:	" << firmaNo << endl;
						cout << "firma ad�	" << firmaAdi << endl;
						cout << "firma yetkilisi:	" << firmaYetkili << endl;
						cout << "m��teri kategorisi:	" << m�steriKategorisi << endl;
						cout << "adresi:	" << adres << endl;

					}
				}
				if (kontrol == 0)
					cout << "B�yle bir firma bulunamad�!!!!\n";
				DosyaOku.close();
			}
			if (secim == 3)
			{
				ofstream DosyaYaz("yedek.txt");
				ifstream DosyaOku;
				string aranan;
				DosyaOku.open("cari.txt");
				cout << "Kayd� de�i�tirilmek istenen firma numaras�: ";
				cin >> aranan;
				while (!DosyaOku.eof()) //sirasiyla firma bilgileri okunuyor.
				{
					DosyaOku >> firmaNo >> firmaAdi >> firmaYetkili >> m�steriKategorisi >> adres;

					if (aranan == firmaNo) //kullanicinin girdigi veriyle firma no ortusuyor mu bakiliyor.Ortusuyor iste yeni veriler kaydediiliyor.
					{
						cout << "--F�RMA KAYDI--\n";
						cout << firmaNo << endl;
						cout << firmaAdi << endl;
						cout << firmaYetkili << endl;
						cout << m�steriKategorisi << endl;
						cout << adres << endl;
						cout << "\nAltta m��terinin yeni kayd� i�in de�erler giriniz";
						cout << "\n firma numaras�    :"; cin >> firmaNo;
						cout << "\n firma ad�   :"; cin >> firmaAdi;
						cout << "\n firma yetkilisi   :"; cin >> firmaYetkili;
						cout << "\n m��teri kategorisi (o/g)    :"; cin >> m�steriKategorisi;
						cout << "\n adresi      :"; cin >> adres;

						DosyaYaz << ' ' << firmaNo << ' ' << firmaAdi << ' ' << firmaYetkili << ' '
							<< m�steriKategorisi << ' ' << adres;
						continue; //kullanicinin yeni guncelledigi firma bilgileri yedege yazdiriliyor. sonra da dongu basina atiliyor.
					}
					DosyaYaz << ' ' << firmaNo << ' ' << firmaAdi << ' ' << firmaYetkili << ' '
						<< m�steriKategorisi << ' ' << adres;  //kullanicinin girdigi ortusmuyorsa mevcut veri yedege yazdirildi.
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
				cout << "Silinmek istenen firman�n ilgili numaras�: "; cin >> aranan;
				while (!DosyaOku.eof())
				{
					DosyaOku >> firmaNo >> firmaAdi >> firmaYetkili >> m�steriKategorisi >> adres;

					if (aranan == firmaNo)
					{
						cout << "Silme ba�ar�l�.";
						continue;
					}
					DosyaYaz << ' ' << firmaNo << ' ' << firmaAdi << ' ' << firmaYetkili << ' '
						<< m�steriKategorisi << ' ' << adres;
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
				cout << "siparis vermek isteyen firman�n numaras� : "; cin >> FirmaNo;	//siparis vermek isteyen firma no soruldu.
				ifstream DosyaOku("cari.txt");
				ifstream UrunOku("urun.txt");
				while (!DosyaOku.eof())
				{
					DosyaOku >> firmaNo >> firmaAdi >> firmaYetkili >> m�steriKategorisi >> adres;

					if (FirmaNo == firmaNo) //firma no ortustu ise bilgileri gosterilerek istenen urun soruldu.
					{

						cout << "\n Firma bilgileri \n";
						cout << " firma no   :" << firmaNo << endl;
						cout << " firma adi      :" << firmaAdi << endl;
						cout << " firma yetkilisi  :" << firmaYetkili << endl;
						cout << " kategorisi:" << m�steriKategorisi << endl;
						cout << " adresi :" << adres << endl;
						cout << "istenen urunun kodu: "; cin >> gecicikod;
						while (!UrunOku.eof())
						{
							UrunOku >> �r�nKodu >> �r�nAdi >> �reticisi >> TeminSuresi >> fiyat >> OzelFiyat >> kdv_Orani >> StokAdedi;

							if (gecicikod == �r�nKodu) //ilgili firmanin siparis vermek istedigi urun kodu soruldu. Ortusuyor mu diye bakiliyor.
							{
								cout << "sipari� tarihi:  "; cin >> siparisTarihi;
								cout << "sipari� etmek istenen miktar: "; cin >> miktar;
								if (m�steriKategorisi == 'g') //bu kisimlarda musterinin kategorisine ozel tutar hesaplaniyor.
								{
									siparisTutariGenel = fiyat * miktar;
								}
								else if (m�steriKategorisi == 'o')
								{
									siparisTutariOzel
										= OzelFiyat * miktar;
								}
								SiparisAlan = firmaAdi; //siparisi alan firmanin adi olarak tutuldu.

								ofstream DosyaYaz2;
								DosyaYaz2.open("siparis.txt", ios::app);
								if (m�steriKategorisi == 'o') //kategoriye ozel olarak siparis.txt dosyasina yazdiriliyor.
								{
									DosyaYaz2 << ' ' << firmaNo << ' ' << �r�nKodu << ' ' << siparisTarihi << ' ' << siparisTutariOzel << ' ' << SiparisAlan;

								}
								else if (m�steriKategorisi == 'g')
								{
									DosyaYaz2 << ' ' << firmaNo << ' ' << �r�nKodu << ' ' << siparisTarihi << ' ' << siparisTutariGenel << ' ' << SiparisAlan;

								}
								DosyaYaz2.close();

								ifstream DosyaOku2("siparis.txt");

								if (m�steriKategorisi == 'o')
								{
									while (!DosyaOku2.eof())
									{
										DosyaOku2 >> firmaNo >> �r�nKodu >> siparisTarihi >> siparisTutariOzel >> SiparisAlan;
									}

									cout << "\n----VER�LEN S�PAR�S HAKK�NDA----\n" << endl;
									cout << "siparis veren firma numaras�:  " << firmaNo << endl;
									cout << "sipari�i verilen �r�n kodu:	" << �r�nKodu << endl;
									cout << "siparis tarihi: " << siparisTarihi << endl;
									cout << "siparis tutari: " << siparisTutariOzel << endl;
									cout << "siparisi alan firma ad�:   " << SiparisAlan << endl;
								}
								if (m�steriKategorisi == 'g')
								{
									while (!DosyaOku2.eof())
									{
										DosyaOku2 >> firmaNo >> �r�nKodu >> siparisTarihi >> siparisTutariGenel >> SiparisAlan;
									}

									cout << "\n----VER�LEN S�PAR�S HAKK�NDA----\n" << endl;
									cout << "siparis veren firma numaras�:  " << firmaNo << endl;
									cout << "sipari�i verilen �r�n kodu:	" << �r�nKodu << endl;
									cout << "sipari� tarihi: " << siparisTarihi << endl;
									cout << "sipari� tutari: " << siparisTutariGenel << endl;
									cout << "sipari�i alan firma ad�:   " << SiparisAlan << endl;

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
				cout << "Sipari�i ��renilmek istenen firma numaras�:	"; cin >> arananno; //Hangi firmanin siparislerini ogrenmek istiyorsak soruluyor.
				while (!DosyaOku.eof()) //ortusen firma numarasi ile o firmanin ne siparisi varsa yazdiriliyor.
				{
					DosyaOku >> firmaNo >> �r�nKodu >> siparisTarihi >> tutar >> SiparisAlan;
					if (arananno == firmaNo)
					{
						cout << "\nsipari�i veren firma no:	" << firmaNo << endl;
						cout << "sipari�i verilen �r�n kodu:	" << �r�nKodu << endl;
						cout << "sipari� tarihi:	" << siparisTarihi << endl;
						cout << "sipari� tutar�: " << tutar << endl;
						cout << "sipari�i alan: " << SiparisAlan << endl << endl;
					}
				}
				DosyaOku.close();
			}
			if (secim == 3)
			{
				string deneme;
				ifstream DosyaOku("siparis.txt");
				ofstream DosyaYaz("yedek.txt");
				cout << "Hangi firman�n sipari�ini silmek istiyorsunuz? Firma No giriniz:	"; cin >> arananno;
				cout << "Hangi �r�n�n sipari�ini silmek istersiniz? �r�n kodu giriniz:	"; cin >> deneme; //Siparisi bulabilmek icin firma ve onun siparis verdigi urunun kodundan faydalaniyoruz.
				while (!DosyaOku.eof())
				{
					DosyaOku >> firmaNo >> �r�nKodu >> siparisTarihi >> tutar >> SiparisAlan;
					if (arananno == firmaNo)
					{

						if (deneme == �r�nKodu)
						{
							cout << "silme basarili!!\n"; //firma ve urun kodu ortusuyorsa bu kisim yedege yazdirilmiyor.
							continue;
						}
					}
					DosyaYaz << ' ' << firmaNo << ' ' << �r�nKodu << ' ' << siparisTarihi << ' ' << tutar << ' ' << SiparisAlan;
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
				cout << "Hangi firman�n sipari�ini d�zeltmek istersiniz? Firma no giriniz:	"; cin >> arananno;
				cout << "Hangi �r�n�n sipari�ini d�zeltmek istersiniz? �r�n no giriniz:		"; cin >> arananno2;
				while (!DosyaOku.eof())
				{
					DosyaOku >> firmaNo >> �r�nKodu >> siparisTarihi >> tutar >> SiparisAlan; //siparis dosyasi verileri sirasiyla okundu.
					if (arananno == firmaNo)
					{

						if (arananno2 == �r�nKodu) //aradigimiz firma ve onun urun siparisi bulunduysa komple yeni bilgiler sorulacak.
						{
							cout << "Sipari� bulundu.\n" << "Sipari� i�in yeni bir firma no giriniz:	"; cin >> arananno3;
							cout << "\nFirma No bulundu. Sipari� i�in yeni bir �r�n kodu giriniz:		"; cin >> arananno4;
							while (!DosyaOku2.eof())
							{
								DosyaOku2 >> firmaNo >> firmaAdi >> firmaYetkili >> m�steriKategorisi >> adres;
								if (arananno3 == firmaNo)
								{
									SiparisAlan = firmaAdi;
									while (!UrunOku.eof())
									{
										UrunOku >> �r�nKodu >> �r�nAdi >> �reticisi >> TeminSuresi >> fiyat >> OzelFiyat >> kdv_Orani >> StokAdedi;
										if (arananno4 == �r�nKodu) //sordugumuz yeni firma no ve istedigi urun bilgileri diger txtlerden okunarak uyusuyor mu diye bakildi degerleri ogrenildi.
										{

											cout << "sipari� tarihi:	"; cin >> siparisTarihi;
											cout << "�r�nden istenilen miktar:	"; cin >> miktar;
											if (m�steriKategorisi == 'g') //musteri kategorisine ozel tutar belirleniyor.
											{
												tutar = fiyat * miktar;
											}
											if (m�steriKategorisi == 'o')
											{
												tutar = OzelFiyat * miktar;
											}
											DosyaYaz << ' ' << firmaNo << ' ' << �r�nKodu << ' ' << siparisTarihi << ' ' << tutar << ' ' << SiparisAlan;
											break; //yeni girdigimiz degerler yedege kaydediliyor. break ve continue komutlari ile fazladan yazdirmamasi icin dongu basina alinarak yeni veriler okunuyor.
										}
									}
								}

							}
							continue;
						}

					}
					DosyaYaz << ' ' << firmaNo << ' ' << �r�nKodu << ' ' << siparisTarihi << ' ' << tutar << ' ' << SiparisAlan; //girilen degerler hic ortusmedigi takdirde degistirilmeden yedege kaydediliyor.
				}
				DosyaYaz.close(); DosyaOku.close(); DosyaOku2.close(); UrunOku.close();
				remove("siparis.txt");
				rename("yedek.txt", "siparis.txt");
				cout << "islem basariyla tamamlandi.\n";
			}

			if (secim == 5)
			{
				ifstream DosyaOku("siparis.txt");
				cout << "----Verilen Sipari�ler Hakk�nda----\n";
				while (!DosyaOku.eof())
				{
					DosyaOku >> firmaNo >> �r�nKodu >> siparisTarihi >> tutar >> SiparisAlan; //verilen siparis verileri tek tek okunarak yazdirildi.
					cout << "\nsipari�i veren firma numaras�:	" << firmaNo << endl;
					cout << "sipari�i verilen �r�n�n kodu: " << �r�nKodu << endl;
					cout << "sipari� tarihi:	" << siparisTarihi << endl;
					cout << "tutar:	" << tutar << endl;
					cout << "sipari�i alan:	" << SiparisAlan << endl;
				}
				DosyaOku.close();
			}
			secim = 0; //her bir secim sonunda secim degiskeni sifirlanarak while dongusunun basina atmaya ve baska secimlere karismamaya yariyor. 
		}


	}











	return 0;
}