#pragma once
#include "Dechet.h"
#include "Compteur.h"

class Operation
{
public:
	Operation(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) {
		this->operationSuivanteFalse = operationSuivanteFalse;
		this->operationSuivanteTrue = operationSuivanteTrue;
		Compteur::ajouterConstructeur();
	}
	Operation(Operation const& autre) { //liste sans information réelle => que copier ? => une liste de même taille

		Operation* aux = autre.operationSuivanteTrue;
		Operation* actuel = this;
		Operation* precedant = NULL;
		while (aux != NULL) {
			aux = aux->operationSuivanteTrue;
			actuel->operationSuivanteTrue = new Operation(NULL, NULL);
			actuel->operationSuivanteFalse = precedant;
			precedant = actuel;
			actuel = actuel->operationSuivanteTrue;
		}

		//operationSuivanteTrue = new Operation(autre.operationSuivanteTrue, autre.operationSuivanteFalse);
		//operationSuivanteFalse = new Operation(autre.operationSuivanteTrue, autre.operationSuivanteFalse);
	}
	virtual bool effectuerOperation(Dechet* dechet) { return false; }//fonction virtuelle pure //à voir avec le main #specs pas claires=> non finalement^^
	Operation *getOperationSuivante(bool choix)const { return choix ? operationSuivanteFalse : operationSuivanteFalse; }
	virtual ~Operation() { delete operationSuivanteFalse; delete operationSuivanteTrue; Compteur::ajouterDestructeur(); }

protected:
	Operation() {
		operationSuivanteFalse = NULL; operationSuivanteFalse = NULL; Compteur::ajouterConstructeur();
	}
private:
	Operation* operationSuivanteTrue;
	Operation* operationSuivanteFalse;

};
