#pragma once
#include "Dechet.h"
#include <utility>
#include "Compteur.h"

class Operation
{
public:
	Operation(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse);

	virtual bool effectuerOperation(Dechet* dechet) { return false; }
	Operation *getOperationSuivante(bool choix)const { return choix ? operationSuivanteTrue : operationSuivanteFalse; }
	virtual ~Operation();

	//voir commentaire constructeur par copie dans operation.cpp #bonus
	virtual Operation* makeObject(Operation const& autre) { return new Operation(autre); }
	Operation(Operation const& autre);
protected:
	Operation() {
		operationSuivanteTrue = NULL; operationSuivanteFalse = NULL; Compteur::ajouterConstructeur();
	}
private:
	Operation* operationSuivanteTrue;
	Operation* operationSuivanteFalse;

};
