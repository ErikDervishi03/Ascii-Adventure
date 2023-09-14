#include "hpp-files/Logic.hpp"

Logic::Logic(WINDOW* win) {

	entitiesOBJ = new Entities(win);

	InfoPlayer = entitiesOBJ->ReturnPlayerOBJ();

	collision = new Collision(entitiesOBJ);

	eventi = new Events(entitiesOBJ);

	Status = Game;
}

Events *Logic::ReturnEventsOBJ()
{
    return eventi;
}

Entities *Logic::ReturnEntitiesOBJ()
{
    return entitiesOBJ;
}

void Logic::InitEntities(int NumberOfMap = 1){
	entitiesOBJ->Insert(player, X_PLAYERSPAWN , Y_PLAYERSPAWN);
	InfoPlayer = entitiesOBJ->ReturnPlayerOBJ();

	if(NumberOfMap == 1){
		entitiesOBJ->Insert(money, 23, 4);
		entitiesOBJ->Insert(enemy, 21, 11);
		entitiesOBJ->Insert(enemy, 34, 6);
		entitiesOBJ->Insert(enemy, 55, 9);
		entitiesOBJ->Insert(money, 78, 8);
	}
	else if(NumberOfMap == 2){
		entitiesOBJ->Insert(enemy, 16, 9);
		entitiesOBJ->Insert(money, 31, 12);
		entitiesOBJ->Insert(enemy, 38, 9);
		entitiesOBJ->Insert(money, 54, 12);
		entitiesOBJ->Insert(powerup, 68, 14);
		entitiesOBJ->Insert(enemy, 77, 10);
	}
	else if(NumberOfMap == 3){
		entitiesOBJ->Insert(money, 22, 5);
		entitiesOBJ->Insert(powerup, 22, 14);
		entitiesOBJ->Insert(enemy, 30, 11);
		entitiesOBJ->Insert(enemy, 32, 6);
		entitiesOBJ->Insert(money, 60, 6);
		entitiesOBJ->Insert(money, 73, 13);
		entitiesOBJ->Insert(enemy, 79, 10);
	}
	else if(NumberOfMap == 4){
		entitiesOBJ->Insert(money, 37, 7);
		entitiesOBJ->Insert(enemy, 51, 7);
		entitiesOBJ->Insert(enemy, 29, 13);
		entitiesOBJ->Insert(money, 53, 13);
		entitiesOBJ->Insert(money, 68, 11);
		entitiesOBJ->Insert(powerup, 22, 10);
	}
	else if(NumberOfMap == 5){
		entitiesOBJ->Insert(money, 42, 5);
		entitiesOBJ->Insert(enemy, 25, 9);
		entitiesOBJ->Insert(enemy, 49, 9);
		entitiesOBJ->Insert(money, 73, 10);
		entitiesOBJ->Insert(money, 24, 13);
		entitiesOBJ->Insert(powerup, 45, 14);
	}
}

void Logic::GiveDynamicity()
{
    ens tmp = entitiesOBJ->ReturnList();
	
    while (tmp) {
        if (!tmp->death_flag) {
            if (tmp->type == enemy ) {
                if (counter_bot < 9) {
                    // Move to the right
                    tmp->xForce = 1;
                } else if (counter_bot >= 9 && counter_bot < 18) {
                    // Move to the left
                    tmp->xForce = -1;
                }
            }

            entitiesOBJ->ClearPosition(tmp);

            eventi->Gravity(tmp);

            collision->ManageCollisions(tmp);

            entitiesOBJ->MoveEntity(tmp);

            entitiesOBJ->DecreaseForce(tmp);

            entitiesOBJ->Display(tmp);
        }

        tmp = tmp->next;
    }

    // Increment the counters
    counter_bot++;
	counter++;
	if(counter > 3)
		counter = 0;
	if(counter_bot == 18)
		counter_bot = 0;
}