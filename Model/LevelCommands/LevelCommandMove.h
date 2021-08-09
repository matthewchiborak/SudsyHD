#ifndef LEVEL_COMMAND_MOVE_H
#define LEVEL_COMMAND_MOVE_H

#include <vector>

#include "LevelCommand.h"
#include "../BoardObjects/BoardObject.h"

class LevelCommandMove: public LevelCommand
{
public:
	LevelCommandMove();

	void execute() override;

	void addPlayer(BoardObject& object);
	void switchPlayer(bool next);
	BoardObject* getCurrentPlayer();

private:
	int currentPlayer;
	std::vector<BoardObject*> players;
};

#endif