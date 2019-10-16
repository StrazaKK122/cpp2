#include <iostream>
#include <math.h>
#include <cmath>
#include <chrono>
#include <iomanip>
#include <Windows.h>
using namespace std;

/*opr_rocz i procent_skladany do zadanka 1*/

double opr_rocz(double zysk, int lata) {
	if (lata > 1) {
		return (1 + zysk) * opr_rocz(zysk, lata - 1);
	}
	else return (1 + zysk);
}

double procent_skladany(double wklad, double zysk, int lata) {
	double wynik = wklad * opr_rocz(zysk, lata);
	cout << "Wynik dla procent skladany: " << wynik << endl;
	return wynik;
}

/*wprowadzamy dane do funkcji procent skladany*/
void zadanie1() {
	procent_skladany(10000, 0.03, 10);
}

/*do zadania 2*/
void druk_gwiazd(int a) {
	if (a >= 1) {
		cout << "*" << endl;
		druk_gwiazd(a - 1);
	}
}

void zadanie2() {
	int a;
	cout << "Wprowadz ilosc gwiazdek: " << endl;
	cin >> a;
	druk_gwiazd(a);
}

/* do zadania 3*/
void druk_liczb(int b) {
	cout << b << endl;
	if (b > 1) {
		druk_liczb(b - 1);
	}
}
void zadanie3() {
	int b;
	cout << "Ile liczb wyswietlic? " << endl;
	cin >> b;
	druk_liczb(b);
}

/*do zadania 4*/
int euk(int c, int d) {
	if (d != 0) {
		return euk(d, c % d);
	}
	return c;
}

void zadanie4() {
	int c;
	int d;
	cout << "Wprowadz liczby ktorych NWD mam sprawdzic: " << endl;
	cin >> c >> d;
	int wynik_euk = euk(c, d);
	cout << "NWD dla tych liczb to: " << wynik_euk << endl;
}

//wersja do mierzenia czasu

int zadanie4a(int c, int d) {
	if (d != 0) {
		return zadanie4a(d, c % d);
	}
	return c;

}


/*Suma liczb naturalnych do 100000*/
/*Do zadania 5*/
int sumaN(int e) {
	if (e >= 1) {
		return e % 10 + sumaN(e / 10);
	}
	return 0;
}

void zadanie5() {
	int e;
	cout << "Podaj liczbe a dam Ci sume jej wszystkich cyfr." << endl;
	cin >> e;
	int wynik_sumaN = sumaN(e);
	cout << "Suma liczb podanej liczby to = " << wynik_sumaN << endl;
}

/*Wybralem NWD rekurencyjnie mamy już w zadaniu 4*/
/*Wystarczy zrobić iteracyjnie*/
/*
void zadanie6() {
	int a;
	int b;
	cout << "NWD metoda iteracyjna: " << endl;
	cout << "Podaj a: ";
	cin >> a;
	cout << "Podaj b: ";
	cin >> b;
	cout << "NWD dla " << a << " i " << b << " = ";
	while (a != b) {
		if (a < b)
			b -= a;
		else
			a -= b;
	}
	cout << a << endl;
}
*/

void zadanie6() {
	DWORD t1, t2;
		t1 = GetTickCount();
	for (int i = 1; i < 1000; i++) {

		//kod tu
		zadanie4a(33, 44);
			t2 = GetTickCount() - t1;
			
	}
cout <<"Czas NWD rekurencyjnie = "<< t2;
	DWORD t3, t4;
		t3 = GetTickCount();
		//kod tu
	for (int j = 1; j < 1000; j++) {
		int a = 33;
		int b = 44;
		while (a != b) {
			if (a < b)
				b -= a;
			else
				a -= b;
		}
		cout << a << endl;
	}
	t4 = GetTickCount() - t3;
		cout << "Czas NWD iteracyjnie = " << t4;
}


//Przyklad for'a dla matola
/*
void zadanie6() {
	for (int i = 1; i < 10; i++) {
		cout << "'i' ma wartosc = " << i << endl;
	}
}
*/

int main() {
	int userChoice;
	bool stay = true;
	cout << "C++ II\n ZESTAW ZADAN 1" << endl;
	while (stay) {
		cout << "\n    Aby wybrac program, wpisz odpowiadajaca mu cyfre.\n    Lista dostepnych programow:\n";
		cout << "1 : Zadanie 1\n";
		cout << "2 : Zadanie 2\n";
		cout << "3 : Zadanie 3\n";
		cout << "4 : Zadanie 4\n";
		cout << "5 : Zadanie 5\n";
		cout << "6 : Zadanie 6\n";
		cout << "0 : Wyjscie z programu.\n";

		cin >> userChoice;
		switch (userChoice) {

		case 0:
			stay = false;
			cout << "\nDziekujemy za skorzystanie z programu!";
			break;

		case 1:
			zadanie1();
			break;

		case 2:
			zadanie2();
			break;

		case 3:
			zadanie3();
			break;

		case 4:
			zadanie4();
			break;

		case 5:
			zadanie5();
			break;

		case 6:
			zadanie6();
			break;

		default:
			cout << "\nPodano zla cyfre. Sprobuj jeszcze raz.\n";
			break;
		}


		/*
		switch (userChoice) {
		case 0:
			stay = false;
			cout << "Dziękujemy za skorzystanie z programu!" << endl;
			break;

		case 1:
			zadanie1();
			break;



		}*/
	}
}
