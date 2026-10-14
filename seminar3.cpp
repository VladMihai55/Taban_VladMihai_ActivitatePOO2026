
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Prajitura {
public:
	char* denumire;
	float pret;
	int cantitate;
	bool dePost;
	int nrIngrediente;
	string* ingrediente;
	/*const int id;*/
	Prajitura()
	{
		this -> denumire = new char[strlen("Tiramisu") + 1];
		strcpy(denumire, "Tiramisu");
		this -> pret = 15;
		this->cantitate = 250;
		this->dePost = true;
		this->nrIngrediente = 3;
		this->ingrediente = new string[this->nrIngrediente];
		this->ingrediente[0] = "Piscot";
		this->ingrediente[1] = "Cafea";
		this->ingrediente[2] = "vanilie";

	}

	Prajitura(const char* denumire, float pret)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->pret = pret;
		this->cantitate = 250;
		this->dePost = true;
		this->nrIngrediente = 3;
		this->ingrediente = new string[this->nrIngrediente];
		this->ingrediente[0] = "Piscot";
		this->ingrediente[1] = "Cafea";
		this->ingrediente[2] = "vanilie";

	}

	void afisare() {
		cout << "Denumire: " << this->denumire << endl;
		cout << "Pret: " << this->pret << endl;
		cout << "Cantitate: " << this->cantitate << endl;
		cout << "De post: " << (this->dePost ? "Da" : "Nu") << endl;
		cout << "Numar ingrediente: " << this->nrIngrediente << endl;
		cout << "Ingredientele sunt: ";
		for (int i = 0; i < this->nrIngrediente; i++) {
			cout << this->ingrediente[i] << "; ";
		}
		cout << endl;
	}
	float costMediuGram() {
		if (this->cantitate == 0)
		{
			return 0;
		}
		else
		{
			return this->pret / this->cantitate;
		}
	}
	void modificaDenumire(const char* denumire)
	{
		delete this->denumire;
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
	}
};

float CalculeazaCantitateTotala(Prajitura* prajituri, int nr_prajituri)
{
	float greutate = 0;
	for (int p = 0;p < nr_prajituri;p++)
	{
		greutate += prajituri[p].cantitate;
	}
	return greutate;
}

void main()
{
	Prajitura p;
	Prajitura p2("Amandina", 40);
	p.afisare();
	cout<<p.costMediuGram()<<endl;
	Prajitura* prajituri;
	prajituri = new Prajitura[3];
	prajituri[2].afisare();
	p2.afisare();
	prajituri[1].pret = 50;
	prajituri[2].cantitate = 70;
	prajituri[0].modificaDenumire("tort");
	prajituri[1].modificaDenumire("ecler");
	for (int i = 0;i < 3;i++)
	{

		cout <<prajituri[i].denumire<<' '<< prajituri[i].costMediuGram() << endl;
	}

	float greutateTotala = CalculeazaCantitateTotala(prajituri, 3);
	cout << "total: " << greutateTotala << endl;

}