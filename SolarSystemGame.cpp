#include "SolarSystemGame.h"

using namespace DirectX::SimpleMath;

SolarSystemGame::SolarSystemGame() : Game()
{
}

SolarSystemGame::~SolarSystemGame()
{
}

void SolarSystemGame::init()
{
	gWorld = Matrix::Identity;
	
	Vector3 eye = { 0, -2, -2 };
	Vector3 at = { 0, 1, 0 };
	Vector3 up = { 0, 1, 0 };
	gView = Matrix::CreateLookAt(eye, at, up);

	gProjection = Matrix::CreatePerspectiveFieldOfView(
		60, screenWidth / static_cast<float>(screenHeight),
		0.01f, 100.0f);

	box = new BoxObject(this, {0,0,0},{1,1,1,1}, 1.0f);
	//pyramid = new PyramidObject(this, new Vertex {{0,1,0},{1,1,1,1} });
}

void SolarSystemGame::update()
{
	
}

void SolarSystemGame::drawObjects()
{
	box->draw();
	//pyramid->draw();
}
