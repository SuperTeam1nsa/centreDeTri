#pragma once
#include <string>
#include <algorithm>
#include <iostream>
#include "Compteur.h"

using namespace std;

class Dechet
{
public:
	enum materiel
	{
		CARTON, BOUTEILLE, PLASTIQUE, METAL, VEGETAL, BOIS, NOURRITURE, PAPIER, STYROFOAM, INCONNU
	};

private:
	int poids; 
	static int id;
	string description;
	int type;
	string couleur;
	materiel mat;
	int purete;
	bool styromousse;
	bool rigide;
	static int idCourant;

protected:
	Dechet(int poids, string description, int type, string couleur, materiel materiel, int purete, bool estEnStyromousse, bool estRigide);
	Dechet(int poids, string description);
	~Dechet();

public:
	Dechet();
	int getPoids() const { return poids; };
	int getId() const { return id; };
	string getDescription() const { return description; };
	int getType() const { return type; };
	string getCouleur() const { return couleur; };
	materiel getMateriel() const { return mat; };
	int getPurete() const { return purete; };
	bool getEstEnStyromousse() const { return styromousse; };
	bool getEstRigide() const { return rigide; };
	ostream& operator<<(ostream &out);

private:
	void setPoids(int _poids) { poids = max(min(_poids, 100), 0); };
	void setId() { id = idCourant; idCourant++; };
	void setPurete(int _purete) { purete = max(min(_purete, 100), 0); };
	void setType(int _type) { if (_type <= 7 && _type >= 1) { type = _type; } else { type = 0; }; };
	void setDescription(string _description) { if (size(_description) < 3) { description = string("???"); } else { description = _description; } };
	void setCouleur(string _couleur) { couleur = _couleur; };
	void setMateriel(materiel _materiel) { mat = _materiel; };
	void setEstEnStyromousse(bool _estEnStyromousse) { styromousse = _estEnStyromousse; };
	void setEstRigide(bool _estRigide) { rigide = _estRigide; };
};