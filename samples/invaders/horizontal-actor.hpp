#pragma once 

#include <SFML/System/Vector2.hpp>

#include "../game-engine/actor.hpp"

namespace ptc {

namespace engine {

class HorizontalActor : public Actor {

  public:
    HorizontalActor(sf::Vector2f pos, sf::Vector2f scale);

  public:
    virtual void
    update(float delta);

  public:
    void
    moveLeft(float delta);

    void
    moveRight(float delta);

};

} // namespace engine

} // namespace ptc
