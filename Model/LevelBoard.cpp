#include "LevelBoard.h"

#include <iostream>

LevelBoard::LevelBoard()
	: Level()
{
}

//void LevelBoard::addPlayerObject(std::unique_ptr<BoardObject> object)
//{
//	if (this->playerObjects.size() < 1)
//		this->currentPlayer = object.get();
//
//	this->playerObjects.push_back(object.get());
//	this->boardObjects.push_back(std::move(object));
//}

//void LevelBoard::move(const Point direction)
//{
//	std::cout << "Level Board Move: " << direction << "\n";
//}
//
//void LevelBoard::interact()
//{
//	std::cout << "Level Board Interact\n";
//}
