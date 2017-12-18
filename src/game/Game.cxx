#include "Game.hxx"

std::vector<char> Game::getMines()
{
	return mines;
}

void Game::resetMines()
{
	mines = std::vector<char>((trc + 1) * getRows());
}

void Game::setEdgeMines()
{
}

void Game::generateMines()
{
}

std::vector<int> Game::returnSolution()
{
	return solution;
}

//std::vector<int> Game::returnCheckMines(int tile)
//{
//}

void Game::checkTile(int tile)
{
}

