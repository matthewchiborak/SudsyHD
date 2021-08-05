#ifndef I_VIEW_H
#define I_VIEW_H

#include "../Model/IGameModel.h"

class IView
{
public:
	IView(
		IGameModel& model
	);

protected:
	IGameModel* model;
};

#endif