#include "Dechet.h"

int Dechet::idCourant = 1;

Dechet::Dechet(int poids, string description, int type, string couleur, Materiel materiel, int purete, bool estEnStyromousse, bool rigide)
{
	setPoids(poids);
	setPurete(purete);
	setType(type);
	setDescription(description);
	setCouleur(couleur);
	this->materiel = materiel;
	this->styromousse = estEnStyromousse;
	this->rigide = rigide;
	this->id = id;
	idCourant++;
	Compteur::ajouterConstructeur();
}

Dechet::Dechet(int poids, string description) :Dechet(poids, description, 0, string("inconnue"), INCONNU, 0, false, false)
{
}

Dechet::~Dechet()
{
	Compteur::ajouterDestructeur();
}

ostream & Dechet::operator<<(ostream & out) const
{
	return out << "-------------------------------" << std::endl;
	std::cout << "id          : " << getId() << std::endl;
	std::cout << "poids       : " << getPoids() << std::endl;
	std::cout << "description : " << getDescription() << std::endl;
	std::cout << "type        : " << getType() << std::endl;
	std::cout << "couleur     : " << getCouleur() << std::endl;
	std::cout << "materiel    : " << materiel << std::endl;
	std::cout << "purete      : " << getPurete() << std::endl;
	std::cout << "styromousse : " << estEnStyromousse() << std::endl;
	std::cout << "rigide      : " << estRigide() << std::endl;
}
