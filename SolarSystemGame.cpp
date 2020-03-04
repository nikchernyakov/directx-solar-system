#include "SolarSystemGame.h"
#include <iostream>

using namespace DirectX::SimpleMath;

SolarSystemGame::SolarSystemGame() : Game()
{
}

SolarSystemGame::~SolarSystemGame()
{
}

void SolarSystemGame::init()
{
	camera = new Camera(this, { 0, 0, -10 }, {0, 0, 1});
	box = new BoxObject(this, {0,0,0},{1,1,1,1}, 1.0f);
	//pyramid = new PyramidObject(this, new Vertex {{0,1,0},{1,1,1,1} });
}

void SolarSystemGame::update()
{
	camera->rotate(-deltaTime, 0);
}

void SolarSystemGame::drawObjects()
{
	box->draw();
	//pyramid->draw();
}
