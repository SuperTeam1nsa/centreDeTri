#include "UsineTraitement.h"
#include "GenerateurSequenceOperation.h"
#include "UQAC.h"

void laboratoire2() {
	ChargementDechet* chargement = UQAC::getChargementDechets();
	UsineTraitement* usineTraitement = new UsineTraitement();
	GenerateurSequenceOperation gso;

	usineTraitement->chargerOperations(gso.genererSequence(0, usineTraitement));
	usineTraitement->demarrerTraitement(chargement);

	delete usineTraitement;
	delete chargement; //I devrait être détruit dans usine
}

void afficherInformation() {

	std::cout << std::endl << std::endl;
	std::cout << std::endl << "--------------------------" << std::endl
		<< " NB constructeurs : " << Compteur::getNbConstructeurs() + Compteur::getNbConstructeursCopie() << std::endl
		<< " NB destructeurs : " << Compteur::getNbDestructeurs() << std::endl;
	std::cin.get();

}
class D {

public:
	D() { printf("D construit"); }
	~D() { printf("D détruit !"); }

};
int main()
{

	laboratoire2();
	afficherInformation();

	return 0;
}
