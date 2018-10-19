#include "SequenceOperations.h"
SequenceOperations::~SequenceOperations()
{
	/*OLD
	Operation* aux;
	while (listeOperation != NULL)
	{
		aux = listeOperation->getOperationSuivante(false);
		delete listeOperation;
		listeOperation = aux;
		//on "depile", listeoperation pointant sur le dernier (on aurait pu le faire à partir de demarrage aussi)
	}*/

	Compteur::ajouterDestructeur();

	Operation* aux;
	listeOperation = operationDemarrage;
	while (listeOperation != NULL)
	{
		aux = listeOperation->getOperationSuivante(true);
		delete listeOperation;
		listeOperation = aux;
		//on suit la liste en supprimant au passage //cf note sur le simplement chaine du à la création et abscence de mutateur 
	}
}
