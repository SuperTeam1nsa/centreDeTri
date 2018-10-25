#pragma once
#include <string>
#include <algorithm>
#include <iostream>
#include "Compteur.h"

using namespace std;

class Dechet
{
public:
	enum Materiel
	{
		CARTON, BOUTEILLE, PLASTIQUE, METAL, VEGETAL, BOIS, NOURRITURE, PAPIER, STYROFOAM, INCONNU
	};

private:
	int poids;
	int id;
	string description;
	int type;
	string couleur;
	Materiel materiel;
	int purete;
	bool styromousse;
	bool rigide;
	static int idCourant;

protected:
	Dechet(int poids, string description, int type, string couleur, Materiel materiel, int purete, bool estEnStyromousse, bool estRigide);
	Dechet(int poids, string description);


public:
	Dechet(Dechet const& autre) : poids(autre.poids), id(autre.id), description(autre.description), type(autre.type),
		couleur(autre.couleur), materiel(autre.materiel),
		purete(autre.purete), styromousse(autre.styromousse), rigide(autre.rigide) {
		Compteur::ajouterConstructeurCopie();
	}
	virtual ~Dechet();
	int getPoids() const { return poids; }
	int getId() const { return id; }
	string getDescription() const { return description; }
	int getType() const { return type; }
	string getCouleur() const { return couleur; }
	Materiel getMateriel() const { return materiel; }
	int getPurete() const { return purete; }
	bool estEnStyromousse() const { return styromousse; }
	bool estRigide() const { return rigide; }
	ostream& operator<<(ostream &out) const;

private:
	void setPoids(int _poids) { poids = max(min(_poids, 100), 0); }
	void setPurete(int _purete) { purete = max(min(_purete, 100), 0); }
	void setType(int _type) {
		if (_type <= 7 && _type >= 1) {
			type = _type;
		}
		else {
			type = 0;
		}
	}
	void setDescription(string _description) {
		if (size(_description) < 3)
		{
			description = string("???");
		}
		else { description = _description; }
	}
	void setCouleur(string _couleur) { couleur = _couleur; }
};
