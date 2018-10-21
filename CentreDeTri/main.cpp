#include "UsineTraitement.h"
#include "GenerateurSequenceOperation.h"
#include "UQAC.h"

void laboratoire2() {
	ChargementDechet* chargement = UQAC::getChargementDechets();
	/*UsineTraitement* usineTraitement = new UsineTraitement();
	GenerateurSequenceOperation gso;

	usineTraitement->chargerOperations(gso.genererSequence(0, usineTraitement));
	usineTraitement->demarrerTraitement(chargement);

	delete usineTraitement;*/
	delete chargement; //I think
}

void afficherInformation() {

	std::cout << std::endl << std::endl;
	std::cout << std::endl << "--------------------------" << std::endl
		<< " NB constructeurs : " << Compteur::getNbConstructeurs() << std::endl
		<< " NB destructeurs : " << Compteur::getNbDestructeurs() << std::endl;


}
class B {
public:
	B() { printf("cstr \n"); };
	B(B const& c) { printf("copie \n"); };
	void presenter() { printf("hello"); }
	~B() { printf("dstr \n"); }

};
B& test() { B b; return b; }

int main()
{
	laboratoire2();
	afficherInformation();
	B &b = test();
	std::cin.get();
	b.presenter();
	std::cin.get();
	return 0;
}
