#pragma once
#include "Operation.h"
#include "UsineTraitement.h"
class OperationTraitement :
	public Operation
{
	friend class UsineTraitement;
public:
	OperationTraitement(UsineTraitement* usineTraitement) :Operation() { this->usineTraitement = usineTraitement; };
	virtual ~OperationTraitement() { delete usineTraitement; }

	bool effectuerOperation(Dechet* dechet)const override {/*???????? en lien avec UsineTraitement ??? (retour false comme ça ^^)*/ return false; }
protected:
	void creerDechetTraiteRecyclable(Dechet* dechet) { UsineTraitement::creerDechetTraiteRecyclable(dechet); }//car inside via friend, juste namespace les ::
	void creerDechetTraiteNonRecyclable(Dechet* dechet) { UsineTraitement::creerDechetTraiteNonRecyclable(dechet); }
	void creerDechetTraiteCompostable(Dechet* dechet) { UsineTraitement::creerDechetTraiteCompostable(dechet); }
private:
	UsineTraitement *usineTraitement;
};
