/****************************************************************************
**								SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**							 B�LG�SAYAR M�HEND�SL��� B�L�M�
**							   PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...:1 PROJE
**				��RENC� ADI...............:Sab�r AKTA�
**				��RENC� NUMARASI.:G191210060
**				DERS GRUBU����:C Grubu
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
	//Giri� saati i�in char de�i�keni belirleyerek anl�k saat kodunu yazd�m
	cout << "Giri� Saati: " << Giris_saati << endl;

	string Kullan�c�Adi;
	string Sifre;


	ifstream DosyaOku("Kullanici.txt");
	while (!DosyaOku.eof())
	{
		string Kullan�c�Adi_2;
		string Sifre_2;
		DosyaOku >> Kullan�c�Adi >> Sifre;
		cout << "L�tfen kullan�c� ad�n�z� giriniz:";
		cin >> Kullan�c�Adi_2;
		cout << "L�tfen �ifrenizi giriniz:";
		cin >> Sifre_2;
		if (Kullan�c�Adi_2 == Kullan�c�Adi && Sifre_2 == Sifre)
		{
			// Kullan�c� dosyas�ndaki kullan�c� ad� ve �ifrenin, program� kullanan ki�inin girdi�i de�erlerin e�le�ip e�le�medi�ini bak�yor
			cout << "Ho� Geldiniz!" << endl;

			//Okuyucu.txt dosyas�nda yer alancak alanlar
			double secim, i = 1;
			string Tc;
			string Adi;
			string Soyadi;
			string Uye_no;
			string Telefon;
			string Dogum_tarihi;
			string Gorevi;
			string Alabilecegi_kitap_sayisi;

			//Kitaplar.txt dosyas�nda yer alacak alanlar
			string Isbn;
			string Kitap_adi;
			string Yazar_adi;
			string Yazar_soyadi;
			string Konu;
			string Tur;
			string Sayfa_sayisi;

			//Odunc.txt dosyas�nda yer alacak alanlar
			string Odunc_tarihi;
			string Donus_tarihi;

			char cevap = 'e';

			do
			{
				cout << "   Ne yapmak istiyorsunuz ? " << endl;
				cout << "   1- Okuyucu kayd�" << endl;
				cout << "   2- Okuyucu kayd� g�ncelleme  " << endl;
				cout << "   3- Okuyucu silme " << endl;
				cout << "   4- Okuyucu �zerindeki kitaplar listesi " << endl;
				cout << "   5- Okuyucu kitap �d�n� alma " << endl;
				cout << "   6- Okuyucu kitap geri d�nd�rme " << endl;
				cout << "   7- Kitap ekleme " << endl;
				cout << "   8- Kitap silme " << endl;
				cout << "   9- Kitap d�zeltme " << endl;
				cin >> secim;
			} while (secim != 1 && secim != 2 && secim != 3 && secim != 4 && secim != 5 && secim != 6 && secim != 7 && secim != 8 && secim != 9);
			//Men�de girilen de�ere g�re y�nlendiriyor
			if (secim == 1)
			{
				ofstream DosyaYaz;
				DosyaYaz.open("Okuyucu.txt", ios::app);
				//Okuyucu dosyas�n� a�arak yeni kay�t yap�lmas�na olanak sa�l�yor
				do
				{
					cout << "\n TC NO      :";
					cin >> Tc;
					cout << "\n Ad�      :";
					cin >> Adi;
					cout << "\n Soy Ad�   :";
					cin >> Soyadi;
					cout << "\n �ye No     :";
					cin >> Uye_no;
					cout << "\n Telefonu       :";
					cin >> Telefon;
					cout << "\n Do�um Tarihi       :";
					cin >> Dogum_tarihi;
					cout << "\n G�revi      :";
					cin >> Gorevi;
					cout << "\n Alabilece�i kitap say�s�      :";
					cin >> Alabilecegi_kitap_sayisi;

					DosyaYaz << Tc << " " << Adi << ' ' << Soyadi << ' ' << Uye_no << ' ' << Telefon << ' ' << Dogum_tarihi << '	' << Gorevi << ' ' << Alabilecegi_kitap_sayisi << ' ' << "\n";
					//Bilgileri Kaydediyor
					cout << "\n Ba�ka okuyucu kayd� yapacak m�s�n�z ? (e/h) ";
					cin >> cevap;
				} while (!(cevap == 'h'));
				DosyaYaz.close();
				cout << "Okuyucu kayd� ba�ar�yla yap�lm��t�r ";
			}
			if (secim == 2)
			{
				string TC;
				cout << " Kayd� g�ncellenecek oyuyucunun TC'si :";
				cin >> TC;
				ifstream DosyaOku("Okuyucu.txt");
				ofstream DosyaYaz("Okuyucu.tmp");
				while (!DosyaOku.eof())
				{
					DosyaOku >> Tc >> Adi >> Soyadi >> Uye_no >> Telefon >> Dogum_tarihi >> Gorevi >> Alabilecegi_kitap_sayisi;
					if (TC == Tc)
					{
						//Eski Bilgileri ekrana bast�r�l�yor
						cout << "\n Dosyadaki kay�t \n";
						cout << Tc << endl;
						cout << Adi << endl;
						cout << Soyadi << endl;
						cout << Uye_no << endl;
						cout << Telefon << endl;
						cout << Dogum_tarihi << endl;
						cout << Gorevi << endl;
						cout << Alabilecegi_kitap_sayisi << endl;
						cout << "\n Kay�t i�in yeni de�erler giri�i \n";
						//Yeni de�erlerin girilmesi isteniyor
						cout << "\n TC NO      :";
						cin >> Tc;
						cout << "\n Ad�      :";
						cin >> Adi;
						cout << "\n Soy Ad�   :";
						cin >> Soyadi;
						cout << "\n �ye No     :";
						cin >> Uye_no;
						cout << "\n Telefonu       :";
						cin >> Telefon;
						cout << "\n Do�um Tarihi       :";
						cin >> Dogum_tarihi;
						cout << "\n G�revi      :";
						cin >> Gorevi;
						cout << "\n Alabilece�i kitap say�s�      :";
						cin >> Alabilecegi_kitap_sayisi;

						DosyaYaz << Tc << " " << Adi << ' ' << Soyadi << ' ' << Uye_no << ' ' << Telefon << ' ' << Dogum_tarihi << Gorevi << ' ' << Alabilecegi_kitap_sayisi << ' ' << "\n";
						//Yeni de�erler dosyaya aktar�l�yor
					}
					else
					{
						DosyaYaz << Tc << " " << Adi << ' ' << Soyadi << ' ' << Uye_no << ' ' << Telefon << ' ' << Dogum_tarihi << Gorevi << ' ' << Alabilecegi_kitap_sayisi << ' ' << "\n";
					}
				}
				DosyaYaz.close();
				DosyaOku.close();
				//Dosya kapat�l�yor
				remove("Okuyucu.txt");
				//�nceki veriler siliniyor
				rename("Okuyucu.tmp", "Okuyucu.txt");
				//Girilen yeni de�erler yedek dosyayla birlkte as�l dosya olarak adland�r�l�yor
			}
			if (secim == 3)
			{
				string ArananString;
				cout << " Kay�d� silenecek okuyucunun TC'si :"; cin >> ArananString;
				ifstream DosyaOku("Okuyucu.txt");
				ofstream DosyaYaz("Okuyucu.tmp");
				//silinecek kay�t� g�ster ve yedek dosyaya kay�t etme

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
						//silinecek kay�t� g�ster ve yedek dosyaya kay�t etme
						while (!DosyaOku_2.eof())
						{

							DosyaOku_2 >> Tc >> Isbn >> Odunc_tarihi >> Donus_tarihi;

							if (ArananString == Tc)
							{

								cout << "\n �d�n� Bilgileri    \n";
								cout << "\n TC No       :" << Tc;
								cout << "\n Kitab�n ISBN:" << Isbn;
								cout << "\n �d�n� Tarihi:" << Odunc_tarihi;
								cout << "\n D�n�� Tarihi:" << Donus_tarihi << endl;

								DosyaYaz << Tc << ' ' << Isbn << ' ' << Odunc_tarihi << ' ' << Donus_tarihi << "\n";

							}
							else {
								DosyaYaz << Tc << ' ' << Isbn << ' ' << Odunc_tarihi << ' ' << Donus_tarihi << "\n";
							}
						}
						DosyaYaz_2.close();
						DosyaOku_2.close();
						remove("Odunc.txt");
						// Yedek dosyan�n ismini as�l dosya ismi olarak de�i�tir.
						rename("Odunc.tmp", "Odunc.txt");
						// Yedek dosyan�n ismini as�l dosya ismi olarak de�i�tir.
					}
					else
					{
						DosyaYaz << Tc << " " << Adi << ' ' << Soyadi << ' ' << Uye_no << ' ' << Telefon << ' ' << Dogum_tarihi << Gorevi << ' ' << Alabilecegi_kitap_sayisi << ' ' << "\n";
					}
				}
				DosyaYaz.close();
				DosyaOku.close();
				remove("Okuyucu.txt");
				// As�l veri dosyas�n� diskten siler
				rename("Okuyucu.tmp", "Okuyucu.txt");
				// Yedek dosyan�n ismini as�l dosya ismi olarak de�i�tir.

				cout << "Okuyucu kayd� silinmi�tir" << endl;
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
					//Okuyucu dosyas�n� a�arak bilgilerin g�r�nt�lenmesine olanak sa�l�yor
				{
					DosyaOku >> Tc >> Adi >> Soyadi >> Uye_no >> Telefon >> Dogum_tarihi >> Gorevi >> Alabilecegi_kitap_sayisi;

					if (TC == Tc)
					{
						cout << "\n Okuyucunun bilgileri \n";
						cout << "\n TC NO: " << Tc << endl;
						cout << "\n Ad�: " << Adi << endl;
						cout << "\n Soy Ad�: " << Soyadi << endl;
						cout << "\n �ye No: " << Uye_no << endl;
						cout << "\n Telefonu: " << Telefon << endl;
						cout << "\n Do�um Tarihi: " << Dogum_tarihi << endl;
						cout << "\n G�revi: " << Gorevi << endl;
						cout << "\n Alabilece�i kitap say�s�: " << Alabilecegi_kitap_sayisi << endl;
						TC = Tc;
						DosyaOku.close();
						ofstream DosyaYaz;
						DosyaOku.open("Odunc.txt", ios::in);
						cout << " �d�n� bilgileri \n" << endl;
						cout << setw(5) << " TC  " << setw(5) << " ISBN " << setw(16) << " �d�n� Tarihi " << setw(16) << "  D�n�� Tarihi " << endl;
						//Dosyalar� yatay olarak s�ralanmas�n� sa�l�yor
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
					//Okuyucu dosyas�n� a�arak bilgilerin g�r�nt�lenmesine olanak sa�l�yor
				{
					DosyaOku >> Tc >> Adi >> Soyadi >> Uye_no >> Telefon >> Dogum_tarihi >> Gorevi >> Alabilecegi_kitap_sayisi;

					if (TC == Tc)
					{
						cout << "\n Okuyucunun bilgileri \n";
						cout << "\n TC NO: " << Tc << endl;
						cout << "\n Ad�: " << Adi << endl;
						cout << "\n Soy Ad�: " << Soyadi << endl;
						cout << "\n �ye No: " << Uye_no << endl;
						cout << "\n Telefonu: " << Telefon << endl;
						cout << "\n Do�um Tarihi: " << Dogum_tarihi << endl;
						cout << "\n G�revi: " << Gorevi << endl;
						cout << "\n Alabilece�i kitap say�s�: " << Alabilecegi_kitap_sayisi << endl;

						string ISBN;
						cout << "L�tfen Kitab�n ISBN'sini Giriniz: ";
						cin >> ISBN;
						ifstream DosyaOku_2("Kitaplar.txt");
						while (!DosyaOku_2.eof())
							//Okuyucu dosyas�n� a�arak bilgilerin g�r�nt�lenmesine olanak sa�l�yor
						{
							DosyaOku_2 >> Isbn >> Kitap_adi >> Yazar_adi >> Yazar_soyadi >> Konu >> Tur;

							if (ISBN == Isbn) {
								cout << "\n Kitap bilgileri \n";
								cout << "\n ISBN        :" << Isbn << endl;
								cout << "\n Kitap Ad�   :" << Kitap_adi << endl;
								cout << "\n Yazar Ad�   :" << Yazar_adi << endl;
								cout << "\n Yazar Soyad�:" << Yazar_soyadi << endl;
								cout << "\n Konu        :" << Konu << endl;
								cout << "\n T�r         :" << Tur << endl;

								DosyaOku.close();
								DosyaOku_2.close();
								ofstream DosyayaYaz;
								DosyayaYaz.open("Odunc.txt", ios::app);
								//�d�n� dosyas�n� a�arak yeni kay�t yap�lmas�na olanak sa�l�yor
								cout << "\n �d�n� Bilgileri    \n";
								cout << "\n TC No       :" << Tc;
								cout << "\n Kitab�n ISBN:" << Isbn;
								cout << "\n �d�n� Tarihi:";
								cin >> Odunc_tarihi;
								cout << "\n D�n�� Tarihi:";
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
				cout << " Kitab� iade edecek ki�inin TC'sini giriniz :";
				cin >> ArananString;
				ifstream DosyaOku("Odunc.txt");
				ofstream DosyaYaz("Odunc.tmp");
				//�d�n� dosyas�n� a�arak kay�t�n g�r�nt�lenmesine olanak sa�l�yor
				while (!DosyaOku.eof())
				{
					DosyaOku >> Tc >> Isbn >> Odunc_tarihi >> Donus_tarihi;

					if (ArananString == Tc)
					{
						cout << "\n �d�n� Bilgileri    \n";
						cout << "\n TC No       :" << Tc;
						cout << "\n Kitab�n ISBN:" << Isbn;
						cout << "\n �d�n� Tarihi:" << Odunc_tarihi;
						cout << "\n D�n�� Tarihi:" << Donus_tarihi;

					}
					else
					{
						DosyaYaz << Tc << " " << Isbn << ' ' << Odunc_tarihi << ' ' << Donus_tarihi << "\n";
					}
				}
				DosyaYaz.close();
				DosyaOku.close();
				remove("Odunc.txt");
				// As�l veri dosyas�n� diskten sil
				rename("Odunc.tmp", "Odunc.txt");
				// yedek dosyan�n ismini as�l dosya ismi olarak de�i�tir.

			}
			if (secim == 7)
			{
				ofstream DosyaYaz;
				DosyaYaz.open("Kitaplar.txt", ios::app);
				//Kitaplar dosyas�n� a�arak yeni kay�t yap�lmas�na olanak sa�l�yor
				do
				{
					cout << "\n ISBN      :";
					cin >> Isbn;
					cout << "\n Kitap Ad�      :";
					cin >> Kitap_adi;
					cout << "\n Yazar Ad�   :";
					cin >> Yazar_adi;
					cout << "\n Yazar Soyad�     :";
					cin >> Yazar_soyadi;
					cout << "\n Konu       :";
					cin >> Konu;
					cout << "\n T�r      :";
					cin >> Tur;

					DosyaYaz << Isbn << " " << Kitap_adi << ' ' << Yazar_adi << ' ' << Yazar_soyadi << ' ' << Konu << ' ' << Tur << "\n";
					// Girilen kay�tlar� dosyaya kaydet
					cout << "\n baska kayit yapacak misin?(e/h) ";
					cin >> cevap;
				} while (!(cevap == 'h'));
				DosyaYaz.close();
				cout << "dosyaya yazim tamamlandi. ";
			}
			if (secim == 8)
			{
				string ArananString;
				cout << " Silinecek kitab�n ISBN'si :";
				cin >> ArananString;
				ifstream DosyaOku("Kitaplar.txt");
				ofstream DosyaYaz("Kitaplar.tmp");
				while (!DosyaOku.eof())
				{
					DosyaOku >> Isbn >> Kitap_adi >> Yazar_adi >> Yazar_soyadi >> Konu >> Tur;

					if (ArananString == Isbn)
					{
						//silinecek kay�t� g�ster ve yedek dosyaya kay�t etme
						cout << "\n Dosyadaki kay�t \n";
						cout << Isbn << endl;
						cout << Kitap_adi << endl;
						cout << Yazar_adi << endl;
						cout << Yazar_soyadi << endl;
						cout << Konu << endl;
						cout << Tur << endl;

					}
					else
					{
						// silinmeyecek kay�tlar� yedek dosyaya kaydet
						DosyaYaz << Isbn << " " << Kitap_adi << ' ' << Yazar_adi << ' ' << Yazar_soyadi << ' ' << Konu << ' ' << Tur << "\n";
					}
				}
				//dosyalar� kapat
				DosyaYaz.close();
				DosyaOku.close();

				remove("Kitaplar.txt");
				// As�l veri dosyas�n� diskten sil
				rename("Kitaplar.tmp", "Kitaplar.txt");
				// yedek dosyan�n ismini as�l dosya ismi olarak de�i�tir.
			}
			if (secim == 9)
			{
				string ArananString;
				cout << " D�zenlenecek Kitab�n ISBN :";
				cin >> ArananString;
				ifstream DosyaOku("Kitaplar.txt");
				ofstream DosyaYaz("Kitaplar.tmp");
				while (!DosyaOku.eof())
				{
					DosyaOku >> Isbn >> Kitap_adi >> Yazar_adi >> Yazar_soyadi >> Konu >> Tur;

					if (ArananString == Isbn)
						// d�zeltilecek kay�t ise
					{
						cout << "\n Dosyadaki kay�t \n";
						cout << Isbn << endl;
						cout << Kitap_adi << endl;
						cout << Yazar_adi << endl;
						cout << Yazar_soyadi << endl;
						cout << Konu << endl;
						cout << Tur << endl;
						cout << "\n Kay�t i�in yeni de�erler giri�i \n";
						cout << "\n ISBN      :";
						cin >> Isbn;
						cout << "\n Kitap Ad�      :";
						cin >> Kitap_adi;
						cout << "\n Yazar Ad�   :";
						cin >> Yazar_adi;
						cout << "\n Yazar Soyad�     :";
						cin >> Yazar_soyadi;
						cout << "\n Konu       :";
						cin >> Konu;
						cout << "\n T�r      :";
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
			cout << "Kullan�c� ad� veya �ifrenizi hatal� girdiniz" << endl;
		}
	}

	auto startt = chrono::system_clock::now();
	auto simdii = chrono::system_clock::to_time_t(startt);
	char C�k�s_saati[30];
	ctime_s(C�k�s_saati, sizeof(C�k�s_saati), &simdii);
	cout << "Biti� Saati: " << C�k�s_saati << endl;
	//Biti� saati i�in char de�i�keni belirleyerek anl�k saat kodunu yazd�m
	system("PAUSE");

	return EXIT_SUCCESS;


}
