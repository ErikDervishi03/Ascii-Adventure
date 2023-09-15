#include "events.hpp"


class Collision {
protected:

	Entities* entitiesOBJ;


	WINDOW* curwin;


	ens ListOfEntities;

public:

	Collision(Entities* MyEntities);

	void ManageJump(ens Entity);

	void OutOfBounds();

	void ManageCollisions(ens Entity, int mappa);
};