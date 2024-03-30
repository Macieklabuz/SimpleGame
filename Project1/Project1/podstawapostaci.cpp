#include "podstawapostaci.h"

Podstawa::Podstawa()
{
	this->sila = 50;
	this->zrecznosc = 50;
	this->inteligencja = 50;
	this->zloto = 100;
	this->rozmiar_opisu = 5;
	opisPostaci.push_back("To");
	opisPostaci.push_back("Jest");
	opisPostaci.push_back("Domyslny");
	opisPostaci.push_back("Opis");
	opisPostaci.push_back("Postaci");
}

int Podstawa::getSila() {
	return sila;
}
int Podstawa::getZrecznosc() {
	return zrecznosc;
}
int Podstawa::getInteligencja() {
	return inteligencja;
}
double Podstawa::getZloto() {
	return zloto;
}

Podstawa::Podstawa(int sila, int zrecznosc, int inteligencja, double zloto, int rozmiar_opisu, string *opisPostaci)
{
	this->sila = sila;
	this->zrecznosc = zrecznosc;
	this->inteligencja = inteligencja;
	this->zloto = zloto;
	this->rozmiar_opisu = rozmiar_opisu;
	for (int i = 0; i < rozmiar_opisu; i++) {
		this->opisPostaci.push_back(opisPostaci[i]);
	}
}

void Podstawa::printPodstawa()
{
	cout << sila <<" "<< endl;
	cout << zrecznosc << " " << endl;
	cout << inteligencja << " " << endl;
	cout << zloto << " " << endl;
	for (int i = 0; i < rozmiar_opisu; i++) {
		cout << opisPostaci[i] << " ";
	}
	cout << endl;
}

void Podstawa::write(ofstream& file) {
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

int Podstawa::operator+(const Podstawa& prawa)
{
	return(this->zloto + prawa.zloto);
}

Podstawa::~Podstawa() {

}
