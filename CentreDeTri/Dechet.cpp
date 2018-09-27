#include "Dechet.h"

Dechet::Dechet(int poids, int purete, int type, string description, string couleur, materiel materiel, bool estEnStyromousse, bool estRigide)
{
	setPoids(poids); //test
	id++;
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
	Dechet::Dechet(poids, 100, 0, description, string("inconnue"), inconnu, false, false);
}

Dechet::~Dechet()
{
}
