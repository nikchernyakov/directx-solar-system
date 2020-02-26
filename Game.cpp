#include "Game.h"
#include <iostream>

Game::Game()
{
	inputDevice = new InputDevice();
}

Game::~Game()
{

}

void Game::init()
{
	
}

void Game::doFrame()
{
	update();
	render();
}

void Game::update()
{
	
}

void Game::render()
{
	float color[] = { 0.0f, 0.0f, 0.2f, 0.0f };
	context->ClearRenderTargetView(rtv, color);

	annotation->BeginEvent(L"BeginDraw");
	drawObjects();
	annotation->EndEvent();
	
	swapChain->Present(1, 0);
}

void Game::drawObjects()
{
	
}
