#pragma once
#include "Dechet.h"
#include <utility>
#include "Compteur.h"

class Operation
{
public:
	Operation(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) {
		this->operationSuivanteFalse = operationSuivanteFalse;
		this->operationSuivanteTrue = operationSuivanteTrue;
		Compteur::ajouterConstructeur();
	}

	virtual bool effectuerOperation(Dechet* dechet) { return false; }
	Operation *getOperationSuivante(bool choix)const { return choix ? operationSuivanteTrue : operationSuivanteFalse; }
	virtual ~Operation() {
		Compteur::ajouterDestructeur();
		if (operationSuivanteFalse != NULL)
			delete operationSuivanteFalse;
		if (operationSuivanteTrue != NULL)
			delete operationSuivanteTrue;
	}
protected:
	Operation() {
		operationSuivanteTrue = NULL; operationSuivanteFalse = NULL; Compteur::ajouterConstructeur();
	}
public:
	virtual Operation* makeObject(Operation const& autre) { return new Operation(autre); }
	Operation(Operation const& autre) {

		if (autre.operationSuivanteFalse != NULL)
			operationSuivanteFalse = (autre.operationSuivanteFalse)->makeObject(*autre.operationSuivanteFalse);
		else
			operationSuivanteFalse = NULL;
		if (autre.operationSuivanteTrue != NULL)
			operationSuivanteTrue = (autre.operationSuivanteTrue)->makeObject(*autre.operationSuivanteTrue);
		else
			operationSuivanteTrue = NULL;
		Compteur::ajouterConstructeurCopie();
		/* On a rajouté une méthode makeObject par rapport à l'UML pour faire une copie propre on aurait pu:

	1) Empêcher la copie :
		private Operation(Operation const& autre);

	2)solution cast = peu élégante...
	if(dynamic_cast<Operation1*>(autre.operationSuivanteTrue))
	operationSuivanteTrue=new Operation1(*autre.operationSuivanteTrue);
	else if(dynamic_cast<Operation2*>(autre.operationSuivanteTrue))
	operationSuivanteTrue=new Operation2(*autre.operationSuivanteTrue);
	//etc
	if(dynamic_cast<Operation1*>(autre.operationSuivanteFalse))
	operationSuivanteFalse=new Operation1(*autre.operationSuivanteFalse);
	else if(dynamic_cast<Operation2*>(autre.operationSuivanteFalse))
	operationSuivanteFalse=new Operation2(*autre.operationSuivanteFalse);
	//etc

	3) Solution du factory pattern (exploitée ici):
	via un makeObject qui renvoie un new objet de son type #comme un constructeur en virtuel bien sur
	makeObject fera appel au cstr par copie avec 1 seul param  (recursif du même coup)
	operationSuivanteFalse = autre.operationSuivanteFalse->makeObject(*autre.operationSuivanteFalse);
	operationSuivanteTrue = autre.operationSuivanteTrue->makeObject(*autre.operationSuivanteFalse);

	rq: pas possible de faire : operationSuivanteTrue = new Operation(autre.operationSuivanteTrue, autre.operationSuivanteFalse);
	problème : perd la vraie nature de l'objet #operation1 etc
	rq2: Certains operateurs par copie sont là uniquement pour faire appel à Compteur::ajouterConstructeurCopie()
	rq3: c++ 11 and up : #decltype,declval, result_of = pas adaptés
	operationSuivanteFalse = new std::remove_reference<decltype(*autre.operationSuivanteFalse)>::type(*autre.operationSuivanteFalse);
	decltype(e) will return the "declared type of e", which is known at compile-time.
It is impossible to retrieve the actual type of a derived class at run-time using decltype. If you want to "clone" depending on the run-time type of a polymorphic object, you can use virtual and override.

Remarque finale: en tout état de fait, on ne se sert pas de ce constructeur par copie, c'est juste pour faire
les choses bien et en cas de modification ultérieure du programme qu'il a été créé.
	*/

	}

private:
	Operation* operationSuivanteTrue;
	Operation* operationSuivanteFalse;

};
