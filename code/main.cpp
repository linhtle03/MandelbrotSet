#include <SFML/Graphics.hpp>
#include "ComplexPlane.h"
using namespace std;
#include <complex.h>

int main ()
{
    Vector2f resolution;

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	float aspectRatio = resolution.x/resolution.y;

	VideoMode vm(resolution.x, resolution.y);
	RenderWindow window(vm, "Mandelbrot", Style::Default);

    vector<VertexArray> vertexArrays;

    std::srand(time(0));

    while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		window.clear();
		window.display();
	}
    return 0;
}