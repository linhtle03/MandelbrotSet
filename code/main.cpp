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
		"Mandelbrot Set", Style::Fullscreen);

	// Create a an SFML View for the main action
	View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

    vector<VertexArray> vertexArrays;

    std::srand(time(0));

    while (window.isOpen())
    {
		window.display();
	}
    return 0;
}