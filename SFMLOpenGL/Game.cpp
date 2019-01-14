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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		rotationAngleY += 0.00005f;

		if (rotationAngleY > 360.0f)
		{
			rotationAngleY -= 360.0f;
		}
	}
	else
	{
		rotationAngleY = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		rotationAngleX += 0.00005f;

		if (rotationAngleX > 360.0f)
		{
			rotationAngleX -= 360.0f;
		}
	}
	else
	{
		rotationAngleX = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		rotationAngleZ += 0.00005f;

		if (rotationAngleZ > 360.0f)
		{
			rotationAngleZ -= 360.0f;
		}
	}
	else
	{
		rotationAngleZ = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		displacementVec.x = -0.005;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		displacementVec.x = 0.005;
	}
	else
	{
		displacementVec.x = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		displacementVec.y = 0.005;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		displacementVec.y = -0.005;
	}
	else
	{
		displacementVec.y = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_scale += 0.000005;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_scale -= 0.000005;
	}
	else
	{
		m_scale = 1;
	}


	for (int i = 0; i < 36; i++)
	{
		MyVector3 tempVec{ vertices[i * 3], vertices[(i * 3) + 1], vertices[(i * 3) + 2] + 6 };
		tempVec = MyMatrix3::rotationX(rotationAngleX) * tempVec;
		tempVec = MyMatrix3::rotationY(rotationAngleY) * tempVec;
		tempVec = MyMatrix3::rotationZ(rotationAngleZ) * tempVec;
		tempVec = MyMatrix3::scale(m_scale) * tempVec;
		tempVec += displacementVec;
		vertices[i * 3] = tempVec.x;
		vertices[i * 3 + 1] = tempVec.y;
		vertices[i * 3 + 2] = tempVec.z - 6;
	}
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

