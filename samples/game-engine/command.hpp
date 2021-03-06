#pragma once 

#include <memory>

#include "actor.hpp"

namespace ptc {

namespace engine {

class Command {

  public:
    virtual
    ~Command();

  public:
    virtual void
    execute(std::shared_ptr<Actor> actor) = 0;

};

} // namespace engine

} // namespace ptc
