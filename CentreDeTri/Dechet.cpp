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
	this->id = idCourant;
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
	return out << "-------------------------------" << std::endl
		<< "id          : " << getId() << std::endl
		<< "poids       : " << getPoids() << std::endl
		<< "description : " << getDescription() << std::endl
		<< "type        : " << getType() << std::endl
		<< "couleur     : " << getCouleur() << std::endl
		<< "materiel    : " << materiel << std::endl
		<< "purete      : " << getPurete() << std::endl
		<< "styromousse : " << estEnStyromousse() << std::endl
		<< "rigide      : " << estRigide() << std::endl;
}
