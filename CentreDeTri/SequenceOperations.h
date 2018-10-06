#pragma once
#include "Operation.h"
class SequenceOperations
{
public:
	SequenceOperations() {};
	~SequenceOperations();
	SequenceOperations* ajouterOperation(Operation* operation) {
		listeOperation = operation;
		//chainage de la liste chainee contenue dans operation (false=precedant, true=suivant) ds le constructeur de opération

	}
	void definirOperationDemarrage(Operation* operation) { operationDemarrage = operation; listeOperation = operation; }
	Operation* getOperationDemarrage() const { return operationDemarrage; }
private:
	Operation* listeOperation; //or operation à un ptr++ et un ptr-- => liste chaine element courant
	Operation* operationDemarrage;
};

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

	Operation* aux;
	listeOperation = operationDemarrage;
	while (listeOperation != NULL)
	{
		aux = listeOperation->getOperationSuivante(true);
		delete listeOperation;
		listeOperation = aux;
		//on suit la liste en supprimant au passage //cf note sur le simplement chaine du à la création et absnece de mutateur => getop(false)=quel bt ?
	}
}
