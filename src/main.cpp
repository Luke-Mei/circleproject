#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf; 
using namespace std;

int main()
{
	Clock clock;
	//changes the constant speed of radius change
	//Before the animation's speed was dependent on the frame rate.
	float speed = 40.f;

	sf::RenderWindow window( sf::VideoMode( { 800, 600 } ), "circle!" );
	sf::CircleShape shape( 100.f );
	Vector2f size = Vector2f(window.getSize());
	Vector2f middle(size.x/2.0f, size.y/2.0f);
	shape.setOrigin({100.f, 100.f});
	shape.setPosition(middle);

	shape.setFillColor( sf::Color::Black );
	shape.setOutlineThickness(10.f);
	shape.setOutlineColor(Color::White);

	float radius = shape.getRadius();
	float maxRadius = 120.f;
	float minRadius = 80.f;
	bool growing = true;

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		//calculates the number of seconds since the previous frame
		float dt = clock.restart().asSeconds();
		if (growing) {
			radius = radius + speed*dt;
		} else {
			radius = radius - speed*dt;
		}

		if (radius > maxRadius){
			growing = false;
		}else if (radius < minRadius){
			growing = true;
		}

		shape.setRadius(radius);
		// Keep the circle centered as its radius changes.
		shape.setOrigin({radius, radius});

		window.clear();
		window.draw( shape );
		window.display();
	}
}
