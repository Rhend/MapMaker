#include <SFML/Graphics.hpp>
#include <iostream>

//~ Internationalization Dependances
#include <libintl.h>
#include <locale.h>
#include "xmlParsing/pugixml.hpp"
#include "MapConfigReader.h"

//~ Alias for gettext
#define _(STRING)    		gettext(STRING)

using namespace std;

int main()
{

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_file("resources/config/config.xml");

    std::cout << "Load result: " << result.description() << ", mesh name: " << doc.child("MapMakerRoot").text() << std::endl;

    MapConfigReader reader("resources/samples/maison1etageSimple.xml");
    vector<shared_ptr<Quartier>> quartiers = reader.getQuartiersFromConfig();
    for (vector<shared_ptr<Quartier>>::iterator it = quartiers.begin(); it != quartiers.end(); )
    {
        Quartier quartier = **it;
        quartier.toString();
        ++it;
    }

//
//    //~ i18n: initializes the entire current locale of the program as per environment variables set by the user
//	setlocale(LC_ALL, "");
//
//	//~ i18n: Indicate the path of the i18n catalog file
//	bindtextdomain("helloworld", "resources/lang");
//	//~ i18n: sets the message domain
//	textdomain("helloworld");
//
//    cout << _("Little GetText test!") << endl << endl;
//
//    // Create the main window
//    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");
//
//    // Load a sprite to display
//    sf::Texture texture;
//    if (!texture.loadFromFile("resources/cb.bmp"))
//        return EXIT_FAILURE;
//    sf::Sprite sprite(texture);
//
//	// Start the game loop
//    while (app.isOpen())
//    {
//        // Process events
//        sf::Event event;
//        while (app.pollEvent(event))
//        {
//            // Close window : exit
//            if (event.type == sf::Event::Closed)
//                app.close();
//        }
//
//        // Clear screen
//        app.clear();
//
//        // Draw the sprite
//        app.draw(sprite);
//
//        // Update the window
//        app.display();
//    }

    return EXIT_SUCCESS;
}
