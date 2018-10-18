#pragma once
#include "Operation.h"
#include "UsineTraitement.h"
#include "Compteur.h"

class OperationTraitement :
	public Operation
{
public:
	OperationTraitement(UsineTraitement* usineTraitement) :Operation() { this->usineTraitement = usineTraitement; Compteur::ajouterConstructeur(); };
	virtual ~OperationTraitement() { delete usineTraitement; Compteur::ajouterDestructeur(); }

	bool effectuerOperation(Dechet* dechet) override {/*???????? en lien avec UsineTraitement ??? (retour false comme ça ^^)*/ return false; }
protected:
	void creerDechetTraiteRecyclable(Dechet* dechet) { usineTraitement->creerDechetTraiteRecyclable(dechet); }//car inside via friend, juste namespace les ::
	void creerDechetTraiteNonRecyclable(Dechet* dechet) { usineTraitement->creerDechetTraiteNonRecyclable(dechet); }
	void creerDechetTraiteCompostable(Dechet* dechet) { usineTraitement->creerDechetTraiteCompostable(dechet); }
private:
	UsineTraitement *usineTraitement;
};
