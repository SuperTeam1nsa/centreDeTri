#pragma once
#include "UsineTraitement.h"
#include "Compteur.h"

class OperationTraitement :
	public Operation
{
private:
	UsineTraitement *usineTraitement;
public:
	OperationTraitement(UsineTraitement* usineT) :Operation() { this->usineTraitement = usineT; Compteur::ajouterConstructeur(); };
	OperationTraitement(OperationTraitement const& autre) {
		usineTraitement = new UsineTraitement(*autre.usineTraitement);
		Compteur::ajouterConstructeurCopie();
	}
	virtual ~OperationTraitement() { delete usineTraitement; Compteur::ajouterDestructeur(); }

	bool effectuerOperation(Dechet* dechet) override {/*???????? en lien avec UsineTraitement ??? (retour false comme ça ^^)*/ return false; }
protected:
	void creerDechetTraiteRecyclable(Dechet* dechet) { usineTraitement->creerDechetTraiteRecyclable(dechet); }//car inside via friend, juste namespace les ::
	void creerDechetTraiteNonRecyclable(Dechet* dechet) { usineTraitement->creerDechetTraiteNonRecyclable(dechet); }
	void creerDechetTraiteCompostable(Dechet* dechet) { usineTraitement->creerDechetTraiteCompostable(dechet); }

};
