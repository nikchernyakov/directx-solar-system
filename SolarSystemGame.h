#pragma once
#include "Game.h"
#include "BoxObject.h"

using namespace DirectX::SimpleMath;

class SolarSystemGame : public Game
{
public:
	SolarSystemGame();
	~SolarSystemGame();

	void init() override;
protected:
	void update() override;
	void drawObjects();

private:
	BoxObject* box;
};
