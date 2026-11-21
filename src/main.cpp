#include <SFML/Graphics.hpp>
#include <cmath>
#include <time.h>
using namespace sf; 
using namespace std;

int main()
{
	Clock clock;

	//total time elapsed
	float t = 0.f;

	sf::RenderWindow window( sf::VideoMode( { 800, 600 } ), "circle!" );
	sf::CircleShape shape( 100.f );
	Vector2f size = Vector2f(window.getSize());
	Vector2f middle(size.x/2.0f, size.y/2.0f);
	shape.setOrigin({100.f, 100.f});
	shape.setPosition(middle);

	shape.setFillColor( sf::Color::Black );
	shape.setOutlineThickness(10.f);
	shape.setOutlineColor(Color::White);

	float base_radius = shape.getRadius();
	float radius = base_radius;
	float amplitude = 20.f;
	//radians per second
	float angular_freq = 3.14159265f;

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		//calculates the number of seconds since the previous frame
		float dt = clock.restart().asSeconds();
		t = t + dt;

		radius = base_radius + amplitude*sin(angular_freq*t);
		
		shape.setRadius(radius);
		// Keep the circle centered as its radius changes.
		shape.setOrigin({radius, radius});

		window.clear();
		window.draw( shape );
		window.display();
	}
}
