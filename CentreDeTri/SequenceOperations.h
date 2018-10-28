#pragma once
#include "Operation.h"
#include "Compteur.h"
class SequenceOperations
{
public:
	SequenceOperations() :listeOperation(NULL), operationDemarrage(NULL) { Compteur::ajouterConstructeur(); };

	~SequenceOperations() {
		Compteur::ajouterDestructeur();
		if (operationDemarrage != NULL)
			delete operationDemarrage;
	}
	//Dans le sens que liste d'operation pointe sur la dernière operation et demarrage
	//sur la première, car le chainage est déjà fait quand on crée les operations
	//Donc l'ajouter à la suite ne fait pas vraiment sens 
	//(#après quoi ? L'operationSuivanteVraie? L'operationSuivanteFalse?)
	SequenceOperations* ajouterOperation(Operation* operation) {
		listeOperation = operation;
		if (operationDemarrage == NULL)
			operationDemarrage = operation;
		//chainage des éléments contenu dans operation (suivantTrue, suivantFalse) dans le constructeur de opération
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
	Operation* listeOperation; //or operation a getOperationSuivante(bool) => chainage des éléments
	Operation* operationDemarrage;
};
