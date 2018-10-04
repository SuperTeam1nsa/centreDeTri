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

ostream & operator<<(ostream & out, Dechet const & dechet)
{
	std::cout << "-------------------------------" << std::endl;
	std::cout << "id          : " << dechet.getId() << std::endl;
	std::cout << "poids       : " << dechet.getPoids() << std::endl;
	std::cout << "description : " << dechet.getDescription() << std::endl;
	std::cout << "type        : " << dechet.getType() << std::endl;
	std::cout << "couleur     : " << dechet.getCouleur() << std::endl;
	std::cout << "materiel    : " << dechet.getMateriel() << std::endl;
	std::cout << "purete      : " << dechet.getPurete() << std::endl;
	std::cout << "styromousse : " << dechet.getEstEnStyromousse() << std::endl;
	std::cout << "rigide      : " << dechet.getEstRigide() << std::endl;
}