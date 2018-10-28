#include "OperationTraitement.h"
#include "UsineTraitement.h"

OperationTraitement::OperationTraitement(UsineTraitement* usineT) :Operation() {
	usineTraitement = usineT;
	Compteur::ajouterConstructeur();
}
OperationTraitement::OperationTraitement(OperationTraitement const& autre) : Operation(autre) {
	usineTraitement = new UsineTraitement(*autre.usineTraitement);
	Compteur::ajouterConstructeurCopie();
}
OperationTraitement::~OperationTraitement() {
	//delete usineTraitement; //détruit dans le main
	Compteur::ajouterDestructeur();
}

//car inside via friend, juste namespace les ::
void OperationTraitement::creerDechetTraiteRecyclable(Dechet* dechet)
{
	usineTraitement->creerDechetTraiteRecyclable(dechet);
}
void OperationTraitement::creerDechetTraiteNonRecyclable(Dechet* dechet)
{
	usineTraitement->creerDechetTraiteNonRecyclable(dechet);
}
void OperationTraitement::creerDechetTraiteCompostable(Dechet* dechet)
{
	usineTraitement->creerDechetTraiteCompostable(dechet);
}
