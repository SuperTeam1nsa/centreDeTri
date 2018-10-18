#pragma once
#include "Dechet.h"
#include "Compteur.h"

class Operation
{
public:
	Operation(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) {
		this->operationSuivanteFalse = operationSuivanteFalse;
		this->operationSuivanteTrue = operationSuivanteFalse;
		Compteur::ajouterConstructeur();
	};
	Operation(Operation const& autre) {
		operationSuivanteTrue = new Operation(*autre.operationSuivanteTrue);
		operationSuivanteFalse = new Operation(*autre.operationSuivanteFalse);
	}
	virtual bool effectuerOperation(Dechet* dechet) { return false; }//fonction virtuelle pure //à voir avec le main #specs pas claires=> non finalement^^
	Operation *getOperationSuivante(bool choix)const { return choix ? operationSuivanteFalse : operationSuivanteFalse; }
	virtual ~Operation() { delete operationSuivanteFalse; delete operationSuivanteTrue; Compteur::ajouterDestructeur();};

protected:
	Operation() { operationSuivanteFalse = NULL; operationSuivanteFalse = NULL; };
private:
	Operation* operationSuivanteTrue;
	Operation* operationSuivanteFalse;

};
