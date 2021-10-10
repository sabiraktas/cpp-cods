/****************************************************************************
**								SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**							 BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**							   PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...:1 PROJE
**				ÖÐRENCÝ ADI...............:Sabýr AKTAÞ
**				ÖÐRENCÝ NUMARASI.:G191210060
**				DERS GRUBU…………:C Grubu
****************************************************************************/

#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include<clocale>
#include <ctime>
#include <ratio>
#include <chrono>


using namespace std;


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Turkish");
	auto start = chrono::system_clock::now();
	auto simdi = chrono::system_clock::to_time_t(start);
	char Giris_saati[30];
	ctime_s(Giris_saati, sizeof(Giris_saati), &simdi);
	//Giriþ saati için char deðiþkeni belirleyerek anlýk saat kodunu yazdým
	cout << "Giriþ Saati: " << Giris_saati << endl;

	string KullanýcýAdi;
	string Sifre;


	ifstream DosyaOku("Kullanici.txt");
	while (!DosyaOku.eof())
	{
		string KullanýcýAdi_2;
		string Sifre_2;
		DosyaOku >> KullanýcýAdi >> Sifre;
		cout << "Lütfen kullanýcý adýnýzý giriniz:";
		cin >> KullanýcýAdi_2;
		cout << "Lütfen þifrenizi giriniz:";
		cin >> Sifre_2;
		if (KullanýcýAdi_2 == KullanýcýAdi && Sifre_2 == Sifre)
		{
			// Kullanýcý dosyasýndaki kullanýcý adý ve þifrenin, programý kullanan kiþinin girdiði deðerlerin eþleþip eþleþmediðini bakýyor
			cout << "Hoþ Geldiniz!" << endl;

			//Okuyucu.txt dosyasýnda yer alancak alanlar
			double secim, i = 1;
			string Tc;
			string Adi;
			string Soyadi;
			string Uye_no;
			string Telefon;
			string Dogum_tarihi;
			string Gorevi;
			string Alabilecegi_kitap_sayisi;

			//Kitaplar.txt dosyasýnda yer alacak alanlar
			string Isbn;
			string Kitap_adi;
			string Yazar_adi;
			string Yazar_soyadi;
			string Konu;
			string Tur;
			string Sayfa_sayisi;

			//Odunc.txt dosyasýnda yer alacak alanlar
			string Odunc_tarihi;
			string Donus_tarihi;

			char cevap = 'e';

			do
			{
				cout << "   Ne yapmak istiyorsunuz ? " << endl;
				cout << "   1- Okuyucu kaydý" << endl;
				cout << "   2- Okuyucu kaydý güncelleme  " << endl;
				cout << "   3- Okuyucu silme " << endl;
				cout << "   4- Okuyucu üzerindeki kitaplar listesi " << endl;
				cout << "   5- Okuyucu kitap ödünç alma " << endl;
				cout << "   6- Okuyucu kitap geri döndürme " << endl;
				cout << "   7- Kitap ekleme " << endl;
				cout << "   8- Kitap silme " << endl;
				cout << "   9- Kitap düzeltme " << endl;
				cin >> secim;
			} while (secim != 1 && secim != 2 && secim != 3 && secim != 4 && secim != 5 && secim != 6 && secim != 7 && secim != 8 && secim != 9);
			//Menüde girilen deðere göre yönlendiriyor
			if (secim == 1)
			{
				ofstream DosyaYaz;
				DosyaYaz.open("Okuyucu.txt", ios::app);
				//Okuyucu dosyasýný açarak yeni kayýt yapýlmasýna olanak saðlýyor
				do
				{
					cout << "\n TC NO      :";
					cin >> Tc;
					cout << "\n Adý      :";
					cin >> Adi;
					cout << "\n Soy Adý   :";
					cin >> Soyadi;
					cout << "\n Üye No     :";
					cin >> Uye_no;
					cout << "\n Telefonu       :";
					cin >> Telefon;
					cout << "\n Doðum Tarihi       :";
					cin >> Dogum_tarihi;
					cout << "\n Görevi      :";
					cin >> Gorevi;
					cout << "\n Alabileceði kitap sayýsý      :";
					cin >> Alabilecegi_kitap_sayisi;

					DosyaYaz << Tc << " " << Adi << ' ' << Soyadi << ' ' << Uye_no << ' ' << Telefon << ' ' << Dogum_tarihi << '	' << Gorevi << ' ' << Alabilecegi_kitap_sayisi << ' ' << "\n";
					//Bilgileri Kaydediyor
					cout << "\n Baþka okuyucu kaydý yapacak mýsýnýz ? (e/h) ";
					cin >> cevap;
				} while (!(cevap == 'h'));
				DosyaYaz.close();
				cout << "Okuyucu kaydý baþarýyla yapýlmýþtýr ";
			}
			if (secim == 2)
			{
				string TC;
				cout << " Kaydý güncellenecek oyuyucunun TC'si :";
				cin >> TC;
				ifstream DosyaOku("Okuyucu.txt");
				ofstream DosyaYaz("Okuyucu.tmp");
				while (!DosyaOku.eof())
				{
					DosyaOku >> Tc >> Adi >> Soyadi >> Uye_no >> Telefon >> Dogum_tarihi >> Gorevi >> Alabilecegi_kitap_sayisi;
					if (TC == Tc)
					{
						//Eski Bilgileri ekrana bastýrýlýyor
						cout << "\n Dosyadaki kayýt \n";
						cout << Tc << endl;
						cout << Adi << endl;
						cout << Soyadi << endl;
						cout << Uye_no << endl;
						cout << Telefon << endl;
						cout << Dogum_tarihi << endl;
						cout << Gorevi << endl;
						cout << Alabilecegi_kitap_sayisi << endl;
						cout << "\n Kayýt için yeni deðerler giriþi \n";
						//Yeni deðerlerin girilmesi isteniyor
						cout << "\n TC NO      :";
						cin >> Tc;
						cout << "\n Adý      :";
						cin >> Adi;
						cout << "\n Soy Adý   :";
						cin >> Soyadi;
						cout << "\n Üye No     :";
						cin >> Uye_no;
						cout << "\n Telefonu       :";
						cin >> Telefon;
						cout << "\n Doðum Tarihi       :";
						cin >> Dogum_tarihi;
						cout << "\n Görevi      :";
						cin >> Gorevi;
						cout << "\n Alabileceði kitap sayýsý      :";
						cin >> Alabilecegi_kitap_sayisi;

						DosyaYaz << Tc << " " << Adi << ' ' << Soyadi << ' ' << Uye_no << ' ' << Telefon << ' ' << Dogum_tarihi << Gorevi << ' ' << Alabilecegi_kitap_sayisi << ' ' << "\n";
						//Yeni deðerler dosyaya aktarýlýyor
					}
					else
					{
						DosyaYaz << Tc << " " << Adi << ' ' << Soyadi << ' ' << Uye_no << ' ' << Telefon << ' ' << Dogum_tarihi << Gorevi << ' ' << Alabilecegi_kitap_sayisi << ' ' << "\n";
					}
				}
				DosyaYaz.close();
				DosyaOku.close();
				//Dosya kapatýlýyor
				remove("Okuyucu.txt");
				//Önceki veriler siliniyor
				rename("Okuyucu.tmp", "Okuyucu.txt");
				//Girilen yeni deðerler yedek dosyayla birlkte asýl dosya olarak adlandýrýlýyor
			}
			if (secim == 3)
			{
				string ArananString;
				cout << " Kayýdý silenecek okuyucunun TC'si :"; cin >> ArananString;
				ifstream DosyaOku("Okuyucu.txt");
				ofstream DosyaYaz("Okuyucu.tmp");
				//silinecek kayýtý göster ve yedek dosyaya kayýt etme

				while (!DosyaOku.eof())
				{
					DosyaOku >> Tc >> Adi >> Soyadi >> Uye_no >> Telefon >> Dogum_tarihi >> Gorevi >> Alabilecegi_kitap_sayisi;

					if (ArananString == Tc)
					{
						cout << "\n Okuyucu bilgileri \n";
						cout << Tc << endl;
						cout << Adi << endl;
						cout << Soyadi << endl;
						cout << Uye_no << endl;
						cout << Telefon << endl;
						cout << Dogum_tarihi << endl;
						cout << Gorevi << endl;
						cout << Alabilecegi_kitap_sayisi << endl;

						ifstream DosyaOku_2("Odunc.txt");
						ofstream DosyaYaz_2("Odunc.tmp");
						//silinecek kayýtý göster ve yedek dosyaya kayýt etme
						while (!DosyaOku_2.eof())
						{

							DosyaOku_2 >> Tc >> Isbn >> Odunc_tarihi >> Donus_tarihi;

							if (ArananString == Tc)
							{

								cout << "\n Ödünç Bilgileri    \n";
								cout << "\n TC No       :" << Tc;
								cout << "\n Kitabýn ISBN:" << Isbn;
								cout << "\n Ödünç Tarihi:" << Odunc_tarihi;
								cout << "\n Dönüþ Tarihi:" << Donus_tarihi << endl;

								DosyaYaz << Tc << ' ' << Isbn << ' ' << Odunc_tarihi << ' ' << Donus_tarihi << "\n";

							}
							else {
								DosyaYaz << Tc << ' ' << Isbn << ' ' << Odunc_tarihi << ' ' << Donus_tarihi << "\n";
							}
						}
						DosyaYaz_2.close();
						DosyaOku_2.close();
						remove("Odunc.txt");
						// Yedek dosyanýn ismini asýl dosya ismi olarak deðiþtir.
						rename("Odunc.tmp", "Odunc.txt");
						// Yedek dosyanýn ismini asýl dosya ismi olarak deðiþtir.
					}
					else
					{
						DosyaYaz << Tc << " " << Adi << ' ' << Soyadi << ' ' << Uye_no << ' ' << Telefon << ' ' << Dogum_tarihi << Gorevi << ' ' << Alabilecegi_kitap_sayisi << ' ' << "\n";
					}
				}
				DosyaYaz.close();
				DosyaOku.close();
				remove("Okuyucu.txt");
				// Asýl veri dosyasýný diskten siler
				rename("Okuyucu.tmp", "Okuyucu.txt");
				// Yedek dosyanýn ismini asýl dosya ismi olarak deðiþtir.

				cout << "Okuyucu kaydý silinmiþtir" << endl;
				system("PAUSE");
				exit(1);
			}
			if (secim == 4)
			{
				string TC;
				cout << " Okuyucu TC :";
				cin >> TC;
				ifstream DosyaOku("Okuyucu.txt");
				while (!DosyaOku.eof())
					//Okuyucu dosyasýný açarak bilgilerin görüntülenmesine olanak saðlýyor
				{
					DosyaOku >> Tc >> Adi >> Soyadi >> Uye_no >> Telefon >> Dogum_tarihi >> Gorevi >> Alabilecegi_kitap_sayisi;

					if (TC == Tc)
					{
						cout << "\n Okuyucunun bilgileri \n";
						cout << "\n TC NO: " << Tc << endl;
						cout << "\n Adý: " << Adi << endl;
						cout << "\n Soy Adý: " << Soyadi << endl;
						cout << "\n Üye No: " << Uye_no << endl;
						cout << "\n Telefonu: " << Telefon << endl;
						cout << "\n Doðum Tarihi: " << Dogum_tarihi << endl;
						cout << "\n Görevi: " << Gorevi << endl;
						cout << "\n Alabileceði kitap sayýsý: " << Alabilecegi_kitap_sayisi << endl;
						TC = Tc;
						DosyaOku.close();
						ofstream DosyaYaz;
						DosyaOku.open("Odunc.txt", ios::in);
						cout << " Ödünç bilgileri \n" << endl;
						cout << setw(5) << " TC  " << setw(5) << " ISBN " << setw(16) << " Ödünç Tarihi " << setw(16) << "  Dönüþ Tarihi " << endl;
						//Dosyalarý yatay olarak sýralanmasýný saðlýyor
						while (!DosyaOku.eof())
						{

							DosyaOku >> Tc >> Isbn >> Odunc_tarihi >> Donus_tarihi;

							if (TC == Tc)
							{
								cout << setw(3) << Tc << setw(5) << Isbn << setw(15) << Odunc_tarihi << setw(15) << Donus_tarihi << endl;
							}

						}
						DosyaYaz.close();
						system("PAUSE");
						exit(1);
					}
				}
			}

			if (secim == 5)
			{
				string TC;
				cout << "Okuyucu TC :";
				cin >> TC;
				ifstream DosyaOku("Okuyucu.txt");
				while (!DosyaOku.eof())
					//Okuyucu dosyasýný açarak bilgilerin görüntülenmesine olanak saðlýyor
				{
					DosyaOku >> Tc >> Adi >> Soyadi >> Uye_no >> Telefon >> Dogum_tarihi >> Gorevi >> Alabilecegi_kitap_sayisi;

					if (TC == Tc)
					{
						cout << "\n Okuyucunun bilgileri \n";
						cout << "\n TC NO: " << Tc << endl;
						cout << "\n Adý: " << Adi << endl;
						cout << "\n Soy Adý: " << Soyadi << endl;
						cout << "\n Üye No: " << Uye_no << endl;
						cout << "\n Telefonu: " << Telefon << endl;
						cout << "\n Doðum Tarihi: " << Dogum_tarihi << endl;
						cout << "\n Görevi: " << Gorevi << endl;
						cout << "\n Alabileceði kitap sayýsý: " << Alabilecegi_kitap_sayisi << endl;

						string ISBN;
						cout << "Lütfen Kitabýn ISBN'sini Giriniz: ";
						cin >> ISBN;
						ifstream DosyaOku_2("Kitaplar.txt");
						while (!DosyaOku_2.eof())
							//Okuyucu dosyasýný açarak bilgilerin görüntülenmesine olanak saðlýyor
						{
							DosyaOku_2 >> Isbn >> Kitap_adi >> Yazar_adi >> Yazar_soyadi >> Konu >> Tur;

							if (ISBN == Isbn) {
								cout << "\n Kitap bilgileri \n";
								cout << "\n ISBN        :" << Isbn << endl;
								cout << "\n Kitap Adý   :" << Kitap_adi << endl;
								cout << "\n Yazar Adý   :" << Yazar_adi << endl;
								cout << "\n Yazar Soyadý:" << Yazar_soyadi << endl;
								cout << "\n Konu        :" << Konu << endl;
								cout << "\n Tür         :" << Tur << endl;

								DosyaOku.close();
								DosyaOku_2.close();
								ofstream DosyayaYaz;
								DosyayaYaz.open("Odunc.txt", ios::app);
								//Ödünç dosyasýný açarak yeni kayýt yapýlmasýna olanak saðlýyor
								cout << "\n Ödünç Bilgileri    \n";
								cout << "\n TC No       :" << Tc;
								cout << "\n Kitabýn ISBN:" << Isbn;
								cout << "\n Ödünç Tarihi:";
								cin >> Odunc_tarihi;
								cout << "\n Dönüþ Tarihi:";
								cin >> Donus_tarihi;

								DosyayaYaz << Tc << " " << Isbn << ' ' << Odunc_tarihi << ' ' << Donus_tarihi << "\n";
								DosyayaYaz.close();
								system("PAUSE");
								exit(1);

							}
							else
							{
								exit(1);
							}

						}
					}
					else
					{
						exit(1);
					}
				}

			}
			if (secim == 6)
			{
				string ArananString;
				cout << " Kitabý iade edecek kiþinin TC'sini giriniz :";
				cin >> ArananString;
				ifstream DosyaOku("Odunc.txt");
				ofstream DosyaYaz("Odunc.tmp");
				//Ödünç dosyasýný açarak kayýtýn görüntülenmesine olanak saðlýyor
				while (!DosyaOku.eof())
				{
					DosyaOku >> Tc >> Isbn >> Odunc_tarihi >> Donus_tarihi;

					if (ArananString == Tc)
					{
						cout << "\n Ödünç Bilgileri    \n";
						cout << "\n TC No       :" << Tc;
						cout << "\n Kitabýn ISBN:" << Isbn;
						cout << "\n Ödünç Tarihi:" << Odunc_tarihi;
						cout << "\n Dönüþ Tarihi:" << Donus_tarihi;

					}
					else
					{
						DosyaYaz << Tc << " " << Isbn << ' ' << Odunc_tarihi << ' ' << Donus_tarihi << "\n";
					}
				}
				DosyaYaz.close();
				DosyaOku.close();
				remove("Odunc.txt");
				// Asýl veri dosyasýný diskten sil
				rename("Odunc.tmp", "Odunc.txt");
				// yedek dosyanýn ismini asýl dosya ismi olarak deðiþtir.

			}
			if (secim == 7)
			{
				ofstream DosyaYaz;
				DosyaYaz.open("Kitaplar.txt", ios::app);
				//Kitaplar dosyasýný açarak yeni kayýt yapýlmasýna olanak saðlýyor
				do
				{
					cout << "\n ISBN      :";
					cin >> Isbn;
					cout << "\n Kitap Adý      :";
					cin >> Kitap_adi;
					cout << "\n Yazar Adý   :";
					cin >> Yazar_adi;
					cout << "\n Yazar Soyadý     :";
					cin >> Yazar_soyadi;
					cout << "\n Konu       :";
					cin >> Konu;
					cout << "\n Tür      :";
					cin >> Tur;

					DosyaYaz << Isbn << " " << Kitap_adi << ' ' << Yazar_adi << ' ' << Yazar_soyadi << ' ' << Konu << ' ' << Tur << "\n";
					// Girilen kayýtlarý dosyaya kaydet
					cout << "\n baska kayit yapacak misin?(e/h) ";
					cin >> cevap;
				} while (!(cevap == 'h'));
				DosyaYaz.close();
				cout << "dosyaya yazim tamamlandi. ";
			}
			if (secim == 8)
			{
				string ArananString;
				cout << " Silinecek kitabýn ISBN'si :";
				cin >> ArananString;
				ifstream DosyaOku("Kitaplar.txt");
				ofstream DosyaYaz("Kitaplar.tmp");
				while (!DosyaOku.eof())
				{
					DosyaOku >> Isbn >> Kitap_adi >> Yazar_adi >> Yazar_soyadi >> Konu >> Tur;

					if (ArananString == Isbn)
					{
						//silinecek kayýtý göster ve yedek dosyaya kayýt etme
						cout << "\n Dosyadaki kayýt \n";
						cout << Isbn << endl;
						cout << Kitap_adi << endl;
						cout << Yazar_adi << endl;
						cout << Yazar_soyadi << endl;
						cout << Konu << endl;
						cout << Tur << endl;

					}
					else
					{
						// silinmeyecek kayýtlarý yedek dosyaya kaydet
						DosyaYaz << Isbn << " " << Kitap_adi << ' ' << Yazar_adi << ' ' << Yazar_soyadi << ' ' << Konu << ' ' << Tur << "\n";
					}
				}
				//dosyalarý kapat
				DosyaYaz.close();
				DosyaOku.close();

				remove("Kitaplar.txt");
				// Asýl veri dosyasýný diskten sil
				rename("Kitaplar.tmp", "Kitaplar.txt");
				// yedek dosyanýn ismini asýl dosya ismi olarak deðiþtir.
			}
			if (secim == 9)
			{
				string ArananString;
				cout << " Düzenlenecek Kitabýn ISBN :";
				cin >> ArananString;
				ifstream DosyaOku("Kitaplar.txt");
				ofstream DosyaYaz("Kitaplar.tmp");
				while (!DosyaOku.eof())
				{
					DosyaOku >> Isbn >> Kitap_adi >> Yazar_adi >> Yazar_soyadi >> Konu >> Tur;

					if (ArananString == Isbn)
						// düzeltilecek kayýt ise
					{
						cout << "\n Dosyadaki kayýt \n";
						cout << Isbn << endl;
						cout << Kitap_adi << endl;
						cout << Yazar_adi << endl;
						cout << Yazar_soyadi << endl;
						cout << Konu << endl;
						cout << Tur << endl;
						cout << "\n Kayýt için yeni deðerler giriþi \n";
						cout << "\n ISBN      :";
						cin >> Isbn;
						cout << "\n Kitap Adý      :";
						cin >> Kitap_adi;
						cout << "\n Yazar Adý   :";
						cin >> Yazar_adi;
						cout << "\n Yazar Soyadý     :";
						cin >> Yazar_soyadi;
						cout << "\n Konu       :";
						cin >> Konu;
						cout << "\n Tür      :";
						cin >> Tur;

						DosyaYaz << Isbn << " " << Kitap_adi << ' ' << Yazar_adi << ' ' << Yazar_soyadi << ' ' << Konu << ' ' << Tur << "\n";
					}
					else
					{
						DosyaYaz << Isbn << " " << Kitap_adi << ' ' << Yazar_adi << ' ' << Yazar_soyadi << ' ' << Konu << ' ' << Tur << "\n";
					}
				}
				DosyaYaz.close();
				DosyaOku.close();
				remove("Kitaplar.txt");
				rename("Kitaplar.tmp", "Kitaplar.txt");
			}
		}
		else
		{
			cout << "Kullanýcý adý veya þifrenizi hatalý girdiniz" << endl;
		}
	}

	auto startt = chrono::system_clock::now();
	auto simdii = chrono::system_clock::to_time_t(startt);
	char Cýkýs_saati[30];
	ctime_s(Cýkýs_saati, sizeof(Cýkýs_saati), &simdii);
	cout << "Bitiþ Saati: " << Cýkýs_saati << endl;
	//Bitiþ saati için char deðiþkeni belirleyerek anlýk saat kodunu yazdým
	system("PAUSE");

	return EXIT_SUCCESS;


}
