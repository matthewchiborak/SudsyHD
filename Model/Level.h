#ifndef LEVEL_H
#define LEVEL_H

class Level
{
public:
	Level();
	
	void setWidth(int value);
	int getWidth() const;
	void setHeight(int value);
	int getHeight() const;

private:
	int width;
	int height;
};

#endif