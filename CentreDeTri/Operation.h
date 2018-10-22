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

	virtual bool effectuerOperation(Dechet* dechet) { return false; }//fonction virtuelle pure: ...() =0; //à voir avec le main #specs pas claires=> non finalement^^
	Operation *getOperationSuivante(bool choix)const { return choix ? operationSuivanteFalse : operationSuivanteFalse; }
	virtual ~Operation() { delete operationSuivanteFalse; delete operationSuivanteTrue; Compteur::ajouterDestructeur(); }

protected:
	Operation() {
		operationSuivanteFalse = NULL; operationSuivanteFalse = NULL; Compteur::ajouterConstructeur();
	}
private:
	Operation* operationSuivanteTrue;
	Operation* operationSuivanteFalse;
	//Operation(Operation const& autre);// empêche la copie

	//ce qui est important c'est le type des operation : creation, op1, op2 etc #vraie donnée

	//Operateur de copie pas utilisé dans les faits on pourrait interdire la copie en le mettant en private 
	//# private Operation(Operation const& autre); dans les fonctions filles aussi. Si on voulait le définir 2 façons :

	//pas possible de faire : //operationSuivanteTrue = new Operation(autre.operationSuivanteTrue, autre.operationSuivanteFalse);
	//problème : perd la vraie nature de l'objet #operation1 etc
	//1 solution cast = peu élégante...
	/*
	if(dynamic_cast<Operation1*>(autre.operationSuivanteTrue))
	operationSuivanteTrue=new Operation1(new Operation(*autre.operationSuivanteTrue), new Operation(*autre.operationSuivanteFalse));
	else if(dynamic_cast<Operation2*>(autre.operationSuivanteTrue))
	operationSuivanteTrue=new Operation2(new Operation(*autre.operationSuivanteTrue), new Operation(*autre.operationSuivanteFalse));
	//etc
	if(dynamic_cast<Operation1*>(autre.operationSuivanteFalse))
	operationSuivanteFalse=new Operation1(new Operation(*autre.operationSuivanteTrue), new Operation(*autre.operationSuivanteFalse));
	else if(dynamic_cast<Operation2*>(autre.operationSuivanteFalse))
	operationSuivanteFalse=new Operation2(new Operation(*autre.operationSuivanteTrue), new Operation(*autre.operationSuivanteFalse));
	//etc

	//etc

	*/
	//2nde solution
	//vraie methode via un make qui renvoie un objet de son type #comme un constructeur (recursif via Operation(&peration)) ) en virtuel bien sur
	//#factory pattern
	//operationSuivanteFalse = autre.operationSuivanteFalse.make(new Operation(*autre.operationSuivanteTrue), new Operation(*autre.operationSuivanteFalse));
	//operationSuivanteTrue = autre.operationSuivanteTrue.make(new Operation(*autre.operationSuivanteTrue), new Operation(*autre.operationSuivanteFalse));


};
