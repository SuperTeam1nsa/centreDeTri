#pragma once
#include "Operation.h"
#include "Compteur.h"
class SequenceOperations
{
public:
	SequenceOperations() :listeOperation(NULL), operationDemarrage(NULL) { Compteur::ajouterConstructeur(); };

	~SequenceOperations() {
		Compteur::ajouterDestructeur();
		//delete listeOperation;
		if (operationDemarrage != NULL)
			delete operationDemarrage;
	}
	SequenceOperations* ajouterOperation(Operation* operation) {
		listeOperation = operation;
		if (operationDemarrage == NULL)
			operationDemarrage = operation;
		//chainage de la liste chainee contenue dans operation (false=precedant, true=suivant) ds le constructeur de opération
		return this;
	}
	void definirOperationDemarrage(Operation* operation) { operationDemarrage = operation; }
	Operation* getOperationDemarrage() const { return operationDemarrage; }
	SequenceOperations(SequenceOperations const& autre) {
		listeOperation = new Operation(*autre.listeOperation);
		operationDemarrage = listeOperation;
		Compteur::ajouterConstructeurCopie();
	}
private:
	Operation* listeOperation; //or operation à un ptr++ et un ptr-- => liste chaine element courant
	Operation* operationDemarrage;
};
