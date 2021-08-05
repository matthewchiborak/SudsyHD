#ifndef VIEW_H
#define VIEW_H

#include "IView.h"

class View: public IView
{
public:
	View(IGameModel& model);

};

#endif