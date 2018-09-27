#pragma once
#include <string>
#include <algorithm>

using namespace std;

class Dechet
{
public:
	enum materiel
	{
		carton, bouteille, plastique, metal, vegetal, bois, nourriture, papier, styromousse, inconnu
	};

private:
	int poids; 
	static int id;
	int purete;
	int type;
	string description;
	string couleur;
	materiel m;
	bool estEnStyromousse;
	bool estRigide;

public:
	Dechet(int poids, int purete, int type, string description, string couleur, materiel materiel, bool estEnStyromousse, bool estRigide);
	Dechet(int poids, string description);
	~Dechet();

	int getPoids() const { return poids; };
	int getId() const { return id; };
	int getPurete() const { return purete; };
	int getType() const { return type; };
	string getDescription() const { return description; };
	string getCouleur() const { return couleur; };
	bool getEstEnStyromousse() const { return estEnStyromousse; };
	bool getEstRigide() const { return estRigide; };

private:
	void setPoids(int _poids) { poids = max(min(_poids, 100), 0); };
	void setPurete(int _purete) { purete = max(min(_purete, 100), 0); };
	void setType(int _type) { if (_type <= 7 && _type >= 1) { type = _type; } else { type = 0; }; };
	void setDescription(string _description) { if (size(_description) < 3) { description = string("???"); } else { description = _description; } };
	void setCouleur(string _couleur) { couleur = _couleur; };
	void setMateriel(materiel _materiel) { m = _materiel; };
	void setEstEnStyromousse(bool _estEnStyromousse) { estEnStyromousse = _estEnStyromousse; };
	void setEstRigide(bool _estRigide) { estRigide = _estRigide; };
};