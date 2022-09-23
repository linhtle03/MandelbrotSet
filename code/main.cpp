#include <SFML/Graphics.hpp>
#include "ComplexPlane.h"
using namespace std;
#include <complex.h>

int main ()
{
    Vector2f resolution;

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	RenderWindow window(VideoMode(resolution.x, resolution.y), 
		"Mandelbrot Set", Style::Default);

	// Create a an SFML View for the main action
	View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

    vector<VertexArray> vertexArrays;

    std::srand(time(0));

    while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// catch the resize events
			if (event.type == sf::Event::Resized)
			{
				// update the view to the new size of the window
				sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
			}
		}
		window.display();
	}
    return 0;
}