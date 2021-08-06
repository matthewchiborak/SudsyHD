#ifndef VIEW_H
#define VIEW_H

#include "IView.h"

class View: public IView
{
public:
	View(Point windowSize, IGameModel& model);

	void draw() override;
	void clearMemory() override;

private:
	void setUp();

	Camera camera;
};

#endif