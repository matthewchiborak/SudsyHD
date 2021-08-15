#ifndef LEVEL_COMMAND_MOVE_H
#define LEVEL_COMMAND_MOVE_H

#include <vector>

#include "LevelCommandPoint.h"
#include "../BoardObjects/BoardObject.h"

class Level;

class LevelCommandMove: public LevelCommandPoint
{
public:
	LevelCommandMove(Level& level);

	bool execute(Point point) override;

	void addPlayer(BoardObject& object);
	void switchPlayer(bool next);
	BoardObject* getCurrentPlayer();

private:
	int currentPlayer;
	std::vector<BoardObject*> players;
	Level* level;

	void checkAndRemoveNullPlayers();
};

#endif