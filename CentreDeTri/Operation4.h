#pragma once
#include "Operation.h"
#include "Compteur.h"


class Operation4 :
	public Operation
{
public:
	Operation4(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {
		Compteur::ajouterConstructeur();
	}
	virtual ~Operation4() { Compteur::ajouterDestructeur(); }
	virtual bool effectuerOperation(Dechet* dechet)  override {
		std::cout << "retour op4 : " << bool((dechet->getCouleur() == "brun") &&
			(dechet->getMateriel() == Dechet::NOURRITURE)) << std::endl;
		return (dechet->getCouleur() == "brun") &&
			(dechet->getMateriel() == Dechet::NOURRITURE);
	}

};
