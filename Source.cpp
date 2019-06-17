#include<iostream>
#include<fstream>
using namespace std;
double f(double x);
void funkc(double g, double c);
void Vidurio(double a, double b, double h, int N, double x);
void Trapeciju(double a, double b, double h, int N, double x);
void Simpsono(double a, double b, double h, int N, double x);
int main()
{
	double g;
	double a, b, h;
	int N, SN;
	double x;
	//double c = 10; // pakeisti i norimas reiksmes
	//cout << f(c) << endl;
	Vidurio(a, b, h, N, x);
	Trapeciju(a, b, h, N, x);
	Simpsono(a, b, h, N, x);

}
double f(double x) // funkcija i kuria ivedam norimas reiksmes kad paskaiciuotu
{
	return x * x + 15 + 3;
}
void Vidurio(double a, double b, double h, int N, double x)
{
	ifstream fd("duom.txt");
	fd >> a >> b >> N; // a - pradinis integralas, b - galutinis integralas, N - zingsniu kiekis
	h = (b - a) / N;

	double iks[100], iks2[100], ats;
	for (int i = 0; i < N; i++)
	{
		iks[0] = a + h;
		iks[i + 1] = iks[i] + h;
		iks2[0] = (a + iks[0]) / 2;
		iks2[i + 1] = (iks[i] + iks[i + 1]) / 2;
		ats += (f(iks2[i]));
	}

	ats = ats * h;
	cout << "Vidurio(bendroji) staciakampiu: " << ats << endl;
}
void Trapeciju(double a, double b, double h, int N, double x)
{
	ifstream fd("duom.txt");
	fd >> a >> b >> N; // a - pradinis integralas, b - galutinis integralas, N - zingsniu kiekis
	h = (b - a) / N;

	double iks[100], iks2[100], ats = 0; //ats = 0 nes kitur jau buvom ats parase ir jis nera 0 po veiksmu
	for (int i = 0; i < N; i++)
	{
		iks[0] = a + h;
		iks[i + 1] = iks[i] + h;

		if (i < N - 1)
		{
			ats += (2 * f(iks[i])); // Pridedam visus isskyrus pirma ir paskutini N nes dar * 2
		}
	}

	ats += (f(a)); // pridedam pirma N
	ats += (f(b)); // pridedam paskutini N
	ats = ats * (h / 2);

	cout << "Trapeciju metodas: " << ats << endl;
}
void Simpsono(double a, double b, double h, int N, double x)
{
	ifstream fd("duom.txt");
	fd >> a >> b >> N; // a - pradinis integralas, b - galutinis integralas, N - zingsniu kiekis
	h = (b - a) / N;

	double iks[100], iks2[100], ats = 0; //ats = 0 nes kitur jau buvom ats parase ir jis nera 0 po veiksmu
	for (int i = 0; i < N; i++)
	{
		iks[0] = a + h;
		iks[i + 1] = iks[i] + h;
		//cout << iks[i] << endl;

		if (i < N - 1)
		{
			if (i % 2 == 0)
			{
				ats += (4 * f(iks[i]));
			}
			if (i % 2 == 1)
			{
				ats += (2 * f(iks[i]));
			}
			//cout << ats << endl;
		}
	}

	ats += (f(a)); // pridedam pirma N
	//cout << (f(a)) << endl;
	ats += (f(b)); // pridedam paskutini N
	//cout << (f(b)) << endl;
	ats = ats * (h / 3);

	cout << "Simpsono metodas: " << ats << endl;
}
