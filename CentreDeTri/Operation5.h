#pragma once
#include "Operation.h"
#include "Compteur.h"

class Operation5 :
	public Operation
{
public:
	Operation5(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {Compteur::ajouterConstructeur();};
	virtual ~Operation5() {};
	bool effectuerOperation(Dechet* dechet) const override { Compteur::ajouterDestructeur(); return (dechet->getCouleur() == "vert" | dechet->getMateriel() == Dechet::VEGETAL); }

};
