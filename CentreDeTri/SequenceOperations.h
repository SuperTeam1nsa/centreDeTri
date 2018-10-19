#pragma once
#include "Operation.h"
#include "Compteur.h"
class SequenceOperations
{
public:
	SequenceOperations() { Compteur::ajouterConstructeur(); };
	SequenceOperations(SequenceOperations const& autre) {
		listeOperation = new Operation(*autre.listeOperation);
		operationDemarrage = listeOperation;
		Compteur::ajouterConstructeurCopie();
	}
	~SequenceOperations();
	SequenceOperations* ajouterOperation(Operation* operation) {
		listeOperation = operation;
		//chainage de la liste chainee contenue dans operation (false=precedant, true=suivant) ds le constructeur de opération
		return this;
	}
	void definirOperationDemarrage(Operation* operation) { operationDemarrage = operation; listeOperation = operation; }
	Operation* getOperationDemarrage() const { return operationDemarrage; }
private:
	Operation* listeOperation; //or operation à un ptr++ et un ptr-- => liste chaine element courant
	Operation* operationDemarrage;
};
