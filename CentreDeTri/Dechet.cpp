#include "Dechet.h"

int Dechet::idCourant = 1;

Dechet::Dechet(int poids, string description, int type, string couleur, materiel materiel, int purete, bool estEnStyromousse, bool estRigide)
{
	setPoids(poids);
	setId();
	setPurete(purete);
	setType(type);
	setDescription(description);
	setCouleur(couleur);
	setMateriel(materiel);
	setEstEnStyromousse(estEnStyromousse);
	setEstRigide(estRigide);
}

Dechet::Dechet(int poids, string description)
{
	Dechet::Dechet(poids, description, 0, string("inconnue"), INCONNU, 0, false, false);
}

Dechet::Dechet()
{
	Dechet::Dechet(1, string("inconnue"), 0, string("inconnue"), INCONNU, 0, false, false);
}

Dechet::~Dechet()
{
}

ostream & Dechet::operator<<(ostream & out)
{
	std::cout << "-------------------------------" << std::endl;
	std::cout << "id          : " << getId() << std::endl;
	std::cout << "poids       : " << getPoids() << std::endl;
	std::cout << "description : " << getDescription() << std::endl;
	std::cout << "type        : " << getType() << std::endl;
	std::cout << "couleur     : " << getCouleur() << std::endl;
	std::cout << "materiel    : " << getMateriel() << std::endl;
	std::cout << "purete      : " << getPurete() << std::endl;
	std::cout << "styromousse : " << getEstEnStyromousse() << std::endl;
	std::cout << "rigide      : " << getEstRigide() << std::endl;
}