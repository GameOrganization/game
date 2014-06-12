#define SFML_STATIC
#include "SFML/Audio.hpp"

int main(int argc, char *argv[]) {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sound.wav"))
        return -1;
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    while (sound.getStatus() == sf::Sound::Playing) {
        //don't max CPU core for no reason
        sf::sleep(sf::milliseconds(100));
    }
    return 0;
}
