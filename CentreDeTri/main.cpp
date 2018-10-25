#include "UsineTraitement.h"
#include "GenerateurSequenceOperation.h"
#include "UQAC.h"

void laboratoire2() {
	ChargementDechet* chargement = UQAC::getChargementDechets();
	//UsineTraitement* usineTraitement = new UsineTraitement();
	//GenerateurSequenceOperation gso;
	*chargement->getDechet() << std::cout << std::endl;
	//usineTraitement->chargerOperations(gso.genererSequence(0, usineTraitement));
	//usineTraitement->demarrerTraitement(chargement);

	//delete usineTraitement;
	//delete chargement; //I devrait être détruit dans usine
}

void afficherInformation() {

	std::cout << std::endl << std::endl;
	std::cout << std::endl << "--------------------------" << std::endl
		<< " NB constructeurs : " << Compteur::getNbConstructeurs() + Compteur::getNbConstructeursCopie() << std::endl
		<< " NB destructeurs : " << Compteur::getNbDestructeurs() << std::endl;
	std::cin.get();

}

int main()
{

	laboratoire2();
	afficherInformation();

	return 0;
}
