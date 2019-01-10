#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
}

Game::~Game() {}

float vertices[] = { 1.0f, 1.0f, -5.0f, -1.0f, 1.0f, -5.0f, -1.0f, -1.0f, -5.0f,
					 1.0f, 1.0f, -5.0f, 1.0f, -1.0f, -5.0f, -1.0f, -1.0f, -5.0f,

					 1.0f, 1.0f, -5.0f, 1.0f, -1.0f, -5.0f, 1.0f, -1.0f, -7.0f,
					 1.0f, 1.0f, -5.0f, 1.0f, 1.0f, -7.0f, 1.0f, -1.0f, -7.0f, 

					 1.0f, 1.0f, -5.0f, 1.0f, 1.0f, -7.0f, -1.0f, 1.0f, -7.0f,
					 1.0f, 1.0f, -5.0f, -1.0f, 1.0f, -5.0f, -1.0f, 1.0f, -7.0f,

					 -1.0f, -1.0f, -7.0f, -1.0f, 1.0f, -5.0f, -1.0f, 1.0f, -7.0f,
					 -1.0f, -1.0f, -7.0f, -1.0f, 1.0f, -5.0f, -1.0f, -1.0f, -5.0f,

					 -1.0f, -1.0f, -7.0f, 1.0f, -1.0f, -7.0f, -1.0f, -1.0f, -5.0f,
					 1.0f, -1.0f, -5.0f, 1.0f, -1.0f, -7.0f, -1.0f, -1.0f, -5.0f,

					 1.0f, 1.0f, -7.0f, 1.0f, -1.0f, -7.0f, -1.0f, -1.0f, -7.0f,
					 1.0f, 1.0f, -7.0f, -1.0f, 1.0f, -7.0f, -1.0f, -1.0f, -7.0f};


float colors[] = { 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
					0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,

					1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
					1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,

					0.0f, 1.0f, 0.0f,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f, 0.0f,
					0.0f, 1.0f, 0.0f,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f, 0.0f,

					1.0f, 1.0f, 0.0f,  1.0f, 1.0f, 0.0f,  1.0f, 1.0f, 0.0f,
					1.0f, 1.0f, 0.0f,  1.0f, 1.0f, 0.0f,  1.0f, 1.0f, 0.0f,

					0.0f, 1.0f, 1.0f,  0.0f, 1.0f, 1.0f,  0.0f, 1.0f, 1.0f,
					0.0f, 1.0f, 1.0f,  0.0f, 1.0f, 1.0f,  0.0f, 1.0f, 1.0f,

					1.0f, 1.0f, 1.0f,  1.0f, 1.0f, 1.0f,  1.0f, 1.0f, 1.0f,
					1.0f, 1.0f, 1.0f,  1.0f, 1.0f, 1.0f,  1.0f, 1.0f, 1.0f};

unsigned int vertex_index[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
								10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
								20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
								30, 31, 32, 33, 34, 35};

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				moveLeft();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
			//	moveRight();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
			//	moveUp();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
			//	moveDown();
			}
		}
		update();
		render();
	}

}

void Game::initialize()
{
	isRunning = true;

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	cout << "Update up" << endl;
}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	cout << "Drawing" << endl;

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	//glDrawArrays(GL_TRIANGLES, 0, 3);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}


void Game::unload()
{
	cout << "Cleaning up" << endl;
}

void Game::moveLeft()
{
	for (int i = 0; i < 36; i++)
	{
		vertices[i] -= 0.05;
	}
}

void Game::moveRight()
{
}

void Game::moveUp()
{
}

void Game::moveDown()
{
}

