// Include important C++ libraries/User defined header files here
#include <SFML/Graphics.hpp>
#include <iostream>
#include <complex.h>
#include "ComplexPlane.h"

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

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

    std::srand(time(0));
	// Create an enum class with CALCULATING and DISPLAYING, initialize to CALCULATING

	// Begin the main loop
    while (window.isOpen())
	{
		Vertex pointf(Vector2f(resolution.x, resolution.y), Color::Red);
		window.draw(&pointf, 1, Points);
		window.display();

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