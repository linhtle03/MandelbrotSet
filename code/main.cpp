// Include important C++ libraries/User defined header files here
#include <SFML/Graphics.hpp>
#include <iostream>
#include <complex.h>
#include "ComplexPlane.h"

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main ()
{
	// Get the screen resolution and create an SFML window
    Vector2f resolution;

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	//Calculate the aspect ratio of the monitor
	float aspectRatio = resolution.x/resolution.y;

	VideoMode vm(resolution.x, resolution.y);
	RenderWindow window(vm, "Mandelbrot", Style::Default);

	//Construct a VertexArray to draw color for each pixel
    vector<VertexArray> vertexArrays;

    std::srand(time(0));

    while (window.isOpen())
	{
		Vertex pointf(Vector2f(resolution.x, resolution.y), Color::Red);
		window.draw(&pointf, 1, Points);
		window.display();
		Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
				if (event.mouseButton.button == Mouse::Left)
				{
					//zoom in
					cout << "Something should be calculated so that this can zoom in" << endl;
				}
				else if (event.mouseButton.button == Mouse::Right)
				{
					//zoom out
					cout << "Something should be calculated so that this can zoom out" << endl;
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
		}
		window.display();
	}
    return 0;
}