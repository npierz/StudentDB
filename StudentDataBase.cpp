//Pierz_Natalia_11k2_Baza_danych_studenta
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

struct student {
	int id;
	string nazwisko;
	string specjalnosc;
	float srednia;

	student(int Id, string Nazwisko, string Specjalnosc, float Srednia)
	{
		id = Id; nazwisko = Nazwisko; specjalnosc = Specjalnosc; srednia = Srednia;
	}
	student* nastepny;
	student() {};
};
void dodaj_studenta_na_koniec(student* &element, int id, string nazwisko, string specjalnosc, float srednia) {
	student *nowy = new student;
	nowy->id = id;
	nowy->nazwisko = nazwisko;
	nowy->specjalnosc = specjalnosc;
	nowy->srednia = srednia;
	if (element == NULL) element = new student;
	else {
		student *tmp = element;
		while (tmp != NULL) element = new student;
		tmp->nastepny = new student;
		student *nowy = NULL;
	}
}
void usun_studenta(student* &element, int id) {
	student* tmp = element;
	if (element == NULL) return;
	if (element->id == id) {
		tmp = NULL;
		if (element->nastepny != NULL) {
			tmp = element->nastepny;
		}
		delete element;
		element = tmp;
		return;
	}
	if (element != NULL) {
		while (tmp->nastepny->id != id) {
			if (tmp->nastepny == NULL) return;
			tmp = tmp->nastepny;
		}
		student* temp = tmp->nastepny;
		tmp->nastepny = temp->nastepny;
		delete temp;
	}
}
void edytuj_studenta(student* element, int id) {
	student* tmp = element;
	while (tmp != NULL) {
		if (tmp->id == id) {
			int tmpID = id;
			cin >> tmpID;
			string tmpNAZWISKO;
			tmp->id = tmpID;
			return;
		}
		tmp = tmp->nastepny;
	}
	cout << "Nie ma takiego studenta" << endl;
}
void wyswietl(student student) {
	cout << "Id studenta: " << student.id << endl;
	cout << "Nazwisko studenta: " << student.nazwisko << endl;
	cout << "Specjalnosc studenta" << student.specjalnosc << endl;
	cout << "Srednia studenta" << student.srednia << endl;
}
void wyswietl_wszystko(student* element) {
	system("cmd /c cls");
	int a = 0;
	student* tmp = element;
	if (tmp != NULL) {
		while (tmp != NULL) {
			cout << "Numer  " << a << endl;
			wyswietl(*tmp);
			a++;
			tmp = tmp->nastepny;
		}
	}
	else {
		cout << "Nie ma takiego studenta" << endl;
	}
}
void szukaj(student* element, int id) {
	student* tmp = element;

	if (tmp != NULL) {
		while (tmp != NULL) {
			if (tmp->id < id) {
				wyswietl(*tmp);
			}
			tmp = tmp->nastepny;
		}
	}
	else {
		cout << "Nie ma takiego id" << endl;
	}
}
void szukaj(student* element, string nazwisko) {
	student* tmp = element;

	if (tmp != NULL) {
		while (tmp != NULL) {
			if (tmp->nazwisko<nazwisko) {
				wyswietl(*tmp);
			}
			tmp = tmp->nastepny;
		}
	}
	else {
		cout << "Nie ma takiego nazwiska" << endl;
	}
}
void szukaj_specjalnosc(student* element, string specjalnosc) {
	student* tmp = element;

	if (tmp != NULL) {
		while (tmp != NULL) {
			if (tmp->specjalnosc<specjalnosc) {
				wyswietl(*tmp);
			}
			tmp = tmp->nastepny;
		}
	}
	else {
		cout << "Nie ma takiego specjalnosc" << endl;
	}

}
void szukaj(student* element, float srednia) {
	student* tmp = element;

	if (tmp != NULL) {
		while (tmp != NULL) {
			if (tmp->srednia<srednia) {
				wyswietl(*tmp);
			}
			tmp = tmp->nastepny;
		}
	}
	else {
		cout << "Nie ma takiej specjalnosci" << endl;
	}
}
void Zapisz(student* &element) {
	ifstream plik;
		plik.open("baza danych.txt");
	plik.close();

	ofstream plik_wyj("baza danych.txt", ios::trunc);
	student* tmp = element;
	if (tmp != NULL) {
		while (tmp != NULL) {
			plik_wyj << tmp->id << " " << tmp->nazwisko << " " << tmp->specjalnosc << " " << tmp->srednia << endl;
			tmp = tmp->nastepny;
		}
	}
	plik_wyj.close();
}
void MenuGlowne() {
	cout << "         Menu bazy studenta" << endl;
	cout << "\n" << endl;
	cout << "1. Szukaj" << endl;
	cout << "2. Dodaj studenta" << endl;
	cout << "3. Usun studenta z bazy" << endl;
	cout << "4. Edytuj studenta" << endl;
	cout << "5. Zapisz" << endl;
	cout << "6. Wyswietl wszystkich" << endl;
	cout << "\n" << endl;
	cout << "7. Wyjdz" << endl;

}
int main() {
	student* lista = NULL;
	int a;
	MenuGlowne();
	cin >> a;
	while (a != 7) {
		switch (a) {
		case 1: {
			int opcja = 0;
			cout << "Szukaj po: " << endl;
			cout << "1. Id";
			cout << "2. Nazwisku";
			cout << "3. Specjalnosci";
			cout << "4. Sredniej z toku studiow: ";
			cin >> opcja;
			switch (opcja) {
			case 1: {
				int id;
				cout << "Podaj id studenta: ";
				cin >> id;
				szukaj(lista, id);
				break;
			}
			case 2: {
				string nazwisko;
				cout << "Podaj nazwisko studenta: ";
				cin >> nazwisko;
				szukaj(lista, nazwisko);
				break;
			}
			case 3: {
				string specjalnosc;
				cout << "Podaj specjalnosc studenta: ";
				cin >> specjalnosc;
				szukaj_specjalnosc(lista, specjalnosc);
				break;
			}
			case 4: {
				float srednia;
				cout << "Podaj srednia studenta: ";
				cin >> srednia;
				szukaj(lista, srednia);
				break;
			}
			}
		}
				break;
		case 2: {
			int id;
			string nazwisko;
			string specjalnosc;
			float srednia;
			cout << "Podaj id: ";
			cin >> id;
			cout << "Podaj nazwisko: ";
			cin >> nazwisko;
			cout << "Podaj specjalnosc: ";
			cin >> specjalnosc;
			cout << "Podaj srednia: ";
			cin >> srednia;
			dodaj_studenta_na_koniec(lista, id, nazwisko, specjalnosc, srednia);
		}
				break;
		case 3: {
			int id;
			cout << "Wpisz id studenta: ";
			cin >> id;
			usun_studenta(lista, id);
		}
				break;
		case 4: {
			int id;
			cout << "Wpisz id studenta: ";
			cin >> id;
			edytuj_studenta(lista, id);
		}
				break;
		case 5: {
			Zapisz(lista);
		}
				break;
		case 6: {
			wyswietl_wszystko(lista);
		}
		}
		MenuGlowne();
		cin >> a;
	}
	return 0;
}


