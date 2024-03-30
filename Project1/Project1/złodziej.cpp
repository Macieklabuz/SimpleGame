#include "z³odziej.h"

Zlodziej::Zlodziej() {
	this->rodzajAtaku = "Atak z Zaskoczenia";
	this->rodzajZlodzieja = "Kieszonkowiec";
}
Zlodziej::Zlodziej(string rodzajAtaku, string rodzajZlodzieja, int sila, int zrecznosc, int inteligencja, double zloto, int rozmiar_opisu, string* opisPostaci) 
	:Podstawa(sila, zrecznosc, inteligencja, zloto, rozmiar_opisu, opisPostaci) {
	this->rodzajAtaku = rodzajAtaku;
	this->rodzajZlodzieja = rodzajZlodzieja;
}

void Zlodziej::printPodstawa() {
	cout << sila << " " << endl;
	cout << zrecznosc << " " << endl;
	cout << inteligencja << " " << endl;
	cout << zloto << " " << endl;
	for (int i = 0; i < rozmiar_opisu; i++) {
		cout << opisPostaci[i] << " ";
	}
	cout << endl;
	cout << " " << rodzajAtaku;
	cout << " " << rodzajZlodzieja << endl;
}

void Zlodziej::write(ofstream& file) {
	if (file.good()) {
		file.write(reinterpret_cast<char*>(&zloto), sizeof(double));
		int rozmiar = opisPostaci.size();
		for (int i = 0; rozmiar; i++) {
			int rozmiar1 = opisPostaci[i].size();
			file.write(reinterpret_cast<char*>(&rozmiar1), sizeof(int));
			file.write((&opisPostaci[i][0]), rozmiar1);
		}
	}
}


Zlodziej::~Zlodziej()
{
}
