#include "SequenceOperations.h"
SequenceOperations::~SequenceOperations()
{
	Compteur::ajouterDestructeur();
	
	delete listeOperation;
	delete operationDemarrage;
}
