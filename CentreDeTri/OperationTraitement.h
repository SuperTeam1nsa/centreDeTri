#pragma once
//#include "UsineTraitement.h"
#include "Operation.h"
#include "Compteur.h"
class UsineTraitement;
class OperationTraitement :
	public Operation
{

public:
	OperationTraitement(UsineTraitement* usineT);
	OperationTraitement(OperationTraitement const& autre);
	virtual ~OperationTraitement();

	bool effectuerOperation(Dechet* dechet) override {/*???????? en lien avec UsineTraitement ??? (retour false comme ça ^^)*/ return false; }
protected:
	void creerDechetTraiteRecyclable(Dechet* dechet);//car inside via friend, juste namespace les ::
	void creerDechetTraiteNonRecyclable(Dechet* dechet);
	void creerDechetTraiteCompostable(Dechet* dechet);
private:
	UsineTraitement *usineTraitement;

};
