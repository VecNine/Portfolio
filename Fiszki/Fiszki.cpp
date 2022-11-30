#include <iostream>
#include <fstream>
#include <cstdint>


using namespace std;

class cMenu
{
private:
	int opcja = 0;

public:


	void Menu()
	{

		cout << "\n\tSuper Program Do Uczenia Się";
		cout << "\n\tWybierz opcję: \n\t[1] Wpisywanie nowych słówek\n\t[2] Uczenie się \n\t[3] Jednak nie chce się uczyć \n\t";
		std::cin >> opcja;

		switch (opcja)
		{
		case 1:
			system("CLS");
			PrzywolanieWypisywania();
			break;
		case 2:
			system("CLS");
			PrzywolanieSlowek();
			break;
		case 3:
			system("CLS");
			cout << "\t-_-\n";
			break;
		default:
			cout << "\tZły numer!\n";
			
		}

		return;
	}
	void PrzywolanieWypisywania();

	void PrzywolanieSlowek();

	
};





class cWypisywanie
{
private:
	int wyborJezyka;
	int wyborKategori;

	string slowo;
	char myuint = 'a';
	ifstream fileCheck;
	string nazwaPliku;

public:

	void MenuWypisywania()
	{
		cout << "\n\tJaki język chciałbyś nadpisać słówkami?\n\t[1] Niemiecki\n\t[2] Szwedzki\n\t[3] Norweski\n\t[4] Niderlandzki\n\t[5] Fiński\n\t[6] Węgierski\n\t[7] Łaciński\n\t[8] Włoski\n\t[9] Hiszpański\n\t[10] Portugalski\n\t[11] Rumuński\n\t[12] Mongolski\n\t[13] Turecki\n\t[14] Japoński\n\t[15] Aniu\n\t[16] Czeski\n\t[17] Rosyjski\n\t[18] Ukraiński\n\t[19] Jidysz\n\t[20] Hawajski\n\t[21] Tagalog\n\t[22] Nahuatl\n\t[23] Grecki\n\t[24] Walijski\n\t[25] Irlandzki\n\t[26] Szkocki Galeik\n\t[27] Arabski\n\t";
		cin >> wyborJezyka;

		system("CLS");

		cout << "\n\tWybierz kategorie:\n\t[1] Liczebniki od 1-10\n\t[2] Liczebniki dziesiętne\n\t[3] Kolory\n\t[4] Zwierzęta\n\t[5] Przyroda\n\t[6] Przedmioty\n\t[7] Inne\n\t";
		cin >> wyborKategori;

		system("CLS");

		switch (wyborJezyka)
		{
		case 1:
			nazwaPliku = "niemiecki";
			break;
		case 2:
			nazwaPliku = "szwedzki";
			break;
		case 3:
			nazwaPliku = "norweski";
			break;
		case 4:
			nazwaPliku = "niderlandzki";
			break;
		case 5:
			nazwaPliku = "finski";
			break;
		case 6:
			nazwaPliku = "wegierski";
			break;
		case 7:
			nazwaPliku = "lacinski";
			break;
		case 8:
			nazwaPliku = "wloski";
			break;
		case 9:
			nazwaPliku = "hiszpanski";
			break;
		case 10:
			nazwaPliku = "portugalski";
			break;
		case 11:
			nazwaPliku = "rumunski";
			break;
		case 12:
			nazwaPliku = "mongolski";
			break;
		case 13:
			nazwaPliku = "turecki";
			break;
		case 14:
			nazwaPliku = "japonski";
			break;
		case 15:
			nazwaPliku = "aniu";
			break;
		case 16:
			nazwaPliku = "czeski";
			break;
		case 17:
			nazwaPliku = "rosyjski";
			break;
		case 18:
			nazwaPliku = "ukrainski";
			break;
		case 19:
			nazwaPliku = "jidysz";
			break;
		case 20:
			nazwaPliku = "hawajski";
			break;
		case 21:
			nazwaPliku = "tagalog";
			break;
		case 22:
			nazwaPliku = "nahuatl";
			break;
		case 23:
			nazwaPliku = "grecki";
			break;
		case 24:
			nazwaPliku = "walijski";
			break;
		case 25:
			nazwaPliku = "irlandzki";
			break;
		case 26:
			nazwaPliku = "szkockigaleik";
			break;
		case 27:
			nazwaPliku = "arabski";
			break;
		default:
			cout << "\tZły numer języka!\n";

			return;
		}

		switch (wyborKategori)
		{
		case 1:
			nazwaPliku = nazwaPliku + "Liczebniki10";
			break;
		case 2:
			nazwaPliku = nazwaPliku + "LiczebnikiD";
			break;
		case 3:
			nazwaPliku = nazwaPliku + "Kolory";
			break;
		case 4:
			nazwaPliku = nazwaPliku + "Zwierzeta";
			break;
		case 5:
			nazwaPliku = nazwaPliku + "Przyroda";
			break;
		case 6:
			nazwaPliku = nazwaPliku + "Przedmioty";
			break;
		case 7:
			nazwaPliku = nazwaPliku + "Inne";
			break;
		default:
			cout << "\tZły numer  kategori!\n";

			return;
		}

		nazwaPliku = nazwaPliku + ".txt";

		wpisywanieSlow(nazwaPliku);
	}




	void wpisywanieSlow(string plik)
	{
		fileCheck.open(plik, ios::app | ios::binary);
		if (fileCheck)
		{
			cout << "\n\tPlik otwarty pomyślnie.\n\n";

			ofstream fileOut;
			fileOut.open(plik, ios::app | ios::binary);

			cout << "\n\tNapisz słowo po polsku. Wpisz 0 jeśli chcesz skończyć.\n\t";
			std::cin >> slowo;
			if (slowo == "0")
			{
				cout << "\n\tKoniec dodawania słów.\n";
				fileOut.close();
				fileCheck.close();

				return;
			}
			else
			{
				do
				{
					for (int i = 0; i < slowo.length(); i++)
					{

						int x = (int)slowo[i];

						switch (x)
						{
							//polski
						case -94: x = -13; //ó
							break;
						case -91: x = -71; //ą
							break;
						case -122: x = -26; //ć
							break;
						case -66: x = -65; //ż
							break;
						case -85: x = -97; //ź
							break;
						case -120: x = -77; //ł
							break;
						case -28: x = -15; //ń
							break;
						case -87: x = -22; //ę
							break;
						case -104: x = -100; //ś
							break;

							//niemiecki
						case -124: x = -28; //ä
							break;
						case -108: x = -10; //ö
							break;
						case -127: x = -4; // ü
							break;
						case -31: x = -33; //ß
							break;

							//węgierski
						case -126: x = -23; //é
							break;
						case -96: x = -31; //á
							break;
						case -95: x = -19; //í
							break;
						case -117: x = -11; //ő
							break;
						case -93: x = -6; //ú
							break;
						case -5: x = -5; //ű
							break;

							//portugalski
						case -109: x = -12; //ô
							break;
						case -125: x = -30; //â
							break;

							//turecki
						case -121: x = -25; //ç
							break;
						case -83: x = -70; //ş
							break;

							//czeski
						case -3: x = -8; //ř
							break;
						case -25: x = -102; //š
							break;
						case -123: x = -7; //ů
							break;
						case -20: x = -3; //ý
							break;
						case -89: x = -98; //ž
							break;
						case -97: x = -24; //č
							break;
						case -40: x = -20; //ě
							break;
						}

						myuint = x;
						fileOut.write(reinterpret_cast<char*>(&myuint), sizeof(myuint));

					}
					char block = ' ';

					fileOut.write(reinterpret_cast<char*>(&block), sizeof(block));


					cout << "\n\tTeraz przetłumacz je w wybranym wcześniej języku:\n\t";
					std::cin >> slowo;

					for (int i = 0; i < slowo.length(); i++)
					{

						int x = (int)slowo[i];

						switch (x)
						{
							//polski
						case -94: x = -13; //ó
							break;
						case -91: x = -71; //ą
							break;
						case -122: x = -26; //ć
							break;
						case -66: x = -65; //ż
							break;
						case -85: x = -97; //ź
							break;
						case -120: x = -77; //ł
							break;
						case -28: x = -15; //ń
							break;
						case -87: x = -22; //ę
							break;
						case -104: x = -100; //ś
							break;

							//niemiecki
						case -124: x = -28; //ä
							break;
						case -108: x = -10; //ö
							break;
						case -127: x = -4; // ü
							break;
						case -31: x = -33; //ß
							break;

							//węgierski
						case -126: x = -23; //é
							break;
						case -96: x = -31; //á
							break;
						case -95: x = -19; //í
							break;
						case -117: x = -11; //ő
							break;
						case -93: x = -6; //ú
							break;
						case -5: x = -5; //ű
							break;

							//portugalski
						case -109: x = -12; //ô
							break;
						case -125: x = -30; //â
							break;

							//turecki
						case -121: x = -25; //ç
							break;
						case -83: x = -70; //ş
							break;

							//czeski
						case -3: x = -8; //ř
							break;
						case -25: x = -102; //š
							break;
						case -123: x = -7; //ů
							break;
						case -20: x = -3; //ý
							break;
						case -89: x = -98; //ž
							break;
						case -97: x = -24; //č
							break;
						case -40: x = -20; //ě
							break;
						}

						myuint = x;
						fileOut.write(reinterpret_cast<char*>(&myuint), sizeof(myuint));


					}

					fileOut.write(reinterpret_cast<char*>(&block), sizeof(block));

					cout << "\n\tDodaj kolejne słowo lub wpisz 0 jeśli chcesz skończyć:\n\t";
					std::cin >> slowo;
					if (slowo == "0")
					{
						cout << "\n\tKoniec dodawania słów.\n";
						fileOut.close();
						fileCheck.close();

						return;
					}
				} while (slowo != "0");
			}
		}
		else
		{
			fstream fileCreate;

			fileCreate.open(plik, ios::binary);
			if (!fileCreate)
			{
				cout << "\n\tWystąpił problem z tworzeniem nowego pliku.\n";

				return;
			}
			else
			{
				cout << "\n\tNowy plik utworzony. Zresetuj aplikacje.\n";

				fileCreate.close();

				return;
			}
		}

	}
};

class cWyswietlanie
{
private:
	ifstream file;
	string nazwaPliku;
	string slowo;
	string zgadniecie;
	int wyborJezyka = 0;
	int wyborKategori = 0;
public:

	void MenuUczeniaSie()
	{
		cout << "\n\tJakiego języka chcialbyś się teraz uczyć?\n\t[1] Niemiecki\n\t[2] Szwedzki\n\t[3] Norweski\n\t[4] Niderlandzki\n\t[5] Fiński\n\t[6] Węgierski\n\t[7] Łaciński\n\t[8] Włoski\n\t[9] Hiszpański\n\t[10] Portugalski\n\t[11] Rumuński\n\t[12] Mongolski\n\t[13] Turecki\n\t[14] Japoński\n\t[15] Aniu\n\t[16] Czeski\n\t[17] Rosyjski\n\t[18] Ukraiński\n\t[19] Jidysz\n\t[20] Hawajski\n\t[21] Tagalog\n\t[22] Nahuatl\n\t[23] Grecki\n\t[24] Walijski\n\t[25] Irlandzki\n\t[26] Szkocki Galeik\n\t[27] Arabski\n\t";
		std::cin >> wyborJezyka;

		system("CLS");

		cout << "\n\tWybierz kategorie:\n\t[1] Liczebniki od 1-10\n\t[2] Liczebniki dziesiętne\n\t[3] Kolory\n\t[4] Zwierzęta\n\t[5] Przyroda\n\t[6] Przedmioty\n\t[7] Inne\n\t";
		std::cin >> wyborKategori;

		system("CLS");

		switch (wyborJezyka)
		{
		case 1:
			nazwaPliku = "niemiecki";
			break;
		case 2:
			nazwaPliku = "szwedzki";
			break;
		case 3:
			nazwaPliku = "norweski";
			break;
		case 4:
			nazwaPliku = "niderlandzki";
			break;
		case 5:
			nazwaPliku = "finski";
			break;
		case 6:
			nazwaPliku = "wegierski";
			break;
		case 7:
			nazwaPliku = "lacinski";
			break;
		case 8:
			nazwaPliku = "wloski";
			break;
		case 9:
			nazwaPliku = "hiszpanski";
			break;
		case 10:
			nazwaPliku = "portugalski";
			break;
		case 11:
			nazwaPliku = "rumunski";
			break;
		case 12:
			nazwaPliku = "mongolski";
			break;
		case 13:
			nazwaPliku = "turecki";
			break;
		case 14:
			nazwaPliku = "japonski";
			break;
		case 15:
			nazwaPliku = "aniu";
			break;
		case 16:
			nazwaPliku = "czeski";
			break;
		case 17:
			nazwaPliku = "rosyjski";
			break;
		case 18:
			nazwaPliku = "ukrainski";
			break;
		case 19:
			nazwaPliku = "jidysz";
			break;
		case 20:
			nazwaPliku = "hawajski";
			break;
		case 21:
			nazwaPliku = "tagalog";
			break;
		case 22:
			nazwaPliku = "nahuatl";
			break;
		case 23:
			nazwaPliku = "grecki";
			break;
		case 24:
			nazwaPliku = "walijski";
			break;
		case 25:
			nazwaPliku = "irlandzki";
			break;
		case 26:
			nazwaPliku = "szkockigaleik";
			break;
		case 27:
			nazwaPliku = "arabski";
			break;
		default:
			cout << "\tZły numer języka!\n";

			return;
		}

		switch (wyborKategori)
		{
		case 1:
			nazwaPliku = nazwaPliku + "Liczebniki10";
			break;
		case 2:
			nazwaPliku = nazwaPliku + "LiczebnikiD";
			break;
		case 3:
			nazwaPliku = nazwaPliku + "Kolory";
			break;
		case 4:
			nazwaPliku = nazwaPliku + "Zwierzeta";
			break;
		case 5:
			nazwaPliku = nazwaPliku + "Przyroda";
			break;
		case 6:
			nazwaPliku = nazwaPliku + "Przedmioty";
			break;
		case 7:
			nazwaPliku = nazwaPliku + "Inne";
			break;
		default:
			cout << "\tZły numer kategori!\n";

			return;
		}

		nazwaPliku = nazwaPliku + ".txt";

		wyswietlanieSlow(nazwaPliku);
	}

	void wyswietlanieSlow(string plik)
	{
		ifstream file;
		file.open(plik, ios::binary | ios::out);
		string slowo;
		string zgadniecie;

		if (file)
		{
			std::cout << "\n\tPlik otworzono pomyślnie.\n\n\tWyświetlone jest słowo, do którego dopisz tłumaczenie w obcym języku.\n\t";
			while (file >> slowo)
			{
				std::cout << "\n\t" << slowo << " - ";

				std::cin >> zgadniecie;

				for (int i = 0; i < zgadniecie.length(); i++)
				{

					int x = (int)zgadniecie[i];

					switch (x)
					{
						//polski
					case -94: x = -13; //ó
						break;
					case -91: x = -71; //ą
						break;
					case -122: x = -26; //ć
						break;
					case -66: x = -65; //ż
						break;
					case -85: x = -97; //ź
						break;
					case -120: x = -77; //ł
						break;
					case -28: x = -15; //ń
						break;
					case -87: x = -22; //ę
						break;
					case -104: x = -100; //ś
						break;

						//niemiecki
					case -124: x = -28; //ä
						break;
					case -108: x = -10; //ö
						break;
					case -127: x = -4; // ü
						break;
					case -31: x = -33; //ß
						break;

						//węgierski
					case -126: x = -23; //é
						break;
					case -96: x = -31; //á
						break;
					case -95: x = -19; //í
						break;
					case -117: x = -11; //ő
						break;
					case -93: x = -6; //ú
						break;
					case -5: x = -5; //ű
						break;

						//portugalski
					case -109: x = -12; //ô
						break;
					case -125: x = -30; //â
						break;

						//turecki
					case -121: x = -25; //ç
						break;
					case -83: x = -70; //ş
						break;

						//czeski
					case -3: x = -8; //ř
						break;
					case -25: x = -102; //š
						break;
					case -123: x = -7; //ů
						break;
					case -20: x = -3; //ý
						break;
					case -89: x = -98; //ž
						break;
					case -97: x = -24; //č
						break;
					case -40: x = -20; //ě
						break;
					}

					zgadniecie[i] = x;

				}

				file >> slowo;

				if (zgadniecie == slowo)
				{
					cout << "\n\tDobrze!\n\t";
				}
				else
				{
					cout << "\n\tŹle!\n\tPoprawne tłumaczenie to: " << slowo << "\n\t";
				}


			}

			std::cout << "\n\n\tKoniec nauki na dziś!\n\n";

			file.close();

			return;
		}
		else
		{
			std::cout << "\n\tTaki plik nie istnieje! Utwórz go w sekcji - Wypisywanie nowych słówek\n";

			return;
		}
	}
};


void cMenu::PrzywolanieWypisywania()
{
	cWypisywanie przywolanie;
	przywolanie.MenuWypisywania();
}

void cMenu::PrzywolanieSlowek()
{
	cWyswietlanie przywolanie2;
	przywolanie2.MenuUczeniaSie();
}


int main() {
	setlocale(LC_ALL, "");

	cMenu menu;
	menu.Menu();

	system("pause");
	return 0;
}
