#pragma once

class Compteur
{
public:
	Compteur() {Compteur::ajouterConstructeur();};
	~Compteur() {Compteur::ajouterDestructeur();};

	void static ajouterConstructeur() { constructeur++; };
	void static ajouterConstructeurCopie() { constructeurCopie++; };
	void static ajouterDestructeur() { destructeur++; };

	int static getNbConstructeurs() { return constructeur; };
	int static getNbConstructeursCopie() { return constructeurCopie; };
	int static getNbDestructeurs() { return destructeur; };

private:
	int static constructeur;
	int static constructeurCopie;
	int static destructeur;
};

int Compteur::constructeur = 0;
int Compteur::constructeurCopie = 0;
int Compteur::destructeur = 0;
