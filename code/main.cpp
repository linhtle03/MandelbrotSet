// Include important C++ libraries/User defined header files here
#include <SFML/Graphics.hpp>
#include <iostream>
#include <complex.h>
#include <cmath>
#include "ComplexPlane.h"

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

float lerp(float a, float b, float t)
{
    return a + t * (b - a);
}

int is_in_set(complex<double> c)
{
	complex<double> z(0,0);
	for (int i = 0; i < MAX_ITER; i++)
	{
		z = z * z + c;
		if(abs(z) > 10)
		{
			return i;
		}
	}
	return 0;
}

//Beginning program
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

	// Construct an object of type ComplexPlane(this is after we do the ComplexPlane file)

	// Construct Font and Text objects
	Font font;
	if (!font.loadFromFile("font/KOMIKAP_.ttf"))
	{
		cout << "Error: Font File" << endl;
	}

	//Construct a VertexArray to draw color for each pixel
    vector<VertexArray> vertexArrays;

	// Create an enum class with CALCULATING and DISPLAYING, initialize to CALCULATING
    for (double x = 0.0; x < 1.0; x += 0.01)
	{
		for (double y = 0.0; y < 1.0; y += 0.01)
		{
			double point_x = lerp(-2.0, 2.0, x);
			double point_y = lerp(2.0, 2.0, y);
			int iters = is_in_set(complex<double>(point_x,point_y));
			if (iters == 0)
			{
				Vertex pointf(Vector2f(x * 1000, y *1000), Color::Red);
                window.draw(&pointf, point_x, Points);
				window.display();
			}
			else 
			{
				Vertex pointf(Vector2f(x * 1000, y *1000), Color::Green);
                window.draw(&pointf, point_y, Points);
				window.display();
			}

		}
	}

	// Begin the main loop
    while (window.isOpen())
	{
		Event event;
        while (window.pollEvent(event))
        {
		/*-------------------
		*****HandleInput*****
		---------------------*/
		// Handle the closing of the window
            if (event.type == Event::Closed)
            {
                window.close();
            }

			// Handle Event::MouseButtonPressed for zooming in and out
            if (event.type == sf::Event::MouseButtonPressed)
            {
				if (event.mouseButton.button == Mouse::Left)
				{
					//zoom in
					cout << "Left click detected: zooming in" << endl;
				}
				else if (event.mouseButton.button == Mouse::Right)
				{
					//zoom out
					cout << "Right click detected: zooming out" << endl;
				}
			}

			// Check if escape is pressed to exit the window
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
		}

		/*-------------------
		*****UpdateScene*****
		---------------------*/
		// If the state is CALCULATING

		// Double for loop to loop through all pixels in screen height/width
		for (int i = 0; i < resolution.y; i++) for(int j = 0; j < resolution.x; j++)
		{
		
		
			// Use mapPixelToCoords to find the Vector2f coordinate in the ComplexPlane View

			// Call ComplexPlane::countIteraions for Vector2f coordinate in the ComplexPlane(+store interations)

			// Declare R G B as Uint8 local variables to store RGB values for current pixel
			
			// Pass the number of iterations and the RGB values into ComplexPlane::iterationsToRGB

			// Set the color variable in the element of VertexArray that corresponds to the screen coordinate

			// Set the state to DISPLAYING

			// Call loadText from the ComplexPlane object
		}
		// End of for loop

		/*-------------------
		******DrawScene******
		---------------------*/
		//Clear out window
		window.clear();

		// Draw VertexArray

		// Draw Text

		// Display
		window.display();
	}
    return 0;
}