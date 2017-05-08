#include "ia.hpp"

namespace ptc {

namespace invader {

unsigned int IA::MAX_NB_MOVES = 12;

IA::IA(const std::vector<std::shared_ptr<HorizontalActor>>& actors)
   : actors_{actors}
   , leftCmd_{std::make_shared<MoveLeftCommand>()}
   , rightCmd_{std::make_shared<MoveRightCommand>()}
   , dir_{IA::Dir::RIGHT}
   , nbMoves_{6} { }

void
IA::update(float delta) {

  static float TIME_BEFORE_MV = 0.5f;

  static float RIGHT_BOUND = 0.0f;

  if (elapsed_ >= TIME_BEFORE_MV) {
    IA::CmdPtr cmd = nullptr;
    if (dir_ == IA::Dir::RIGHT) {
      cmd = rightCmd_;
    } else if (dir_ == IA::Dir::LEFT) {
      cmd = leftCmd_;
    }
    // Updates every enemies
    for (auto actor : actors_) {
      cmd->execute(actor, delta);
    }
    elapsed_ = 0.0f;

    // Changes direction whevener the enemies have
    // reached the other side.
    --nbMoves_;
    if (nbMoves_ == 0) {
      if (dir_ == IA::Dir::RIGHT) {
        dir_ = IA::Dir::LEFT;
      } else {
        dir_ = IA::Dir::RIGHT;
      }
      nbMoves_ = MAX_NB_MOVES;
    }
  }
  elapsed_ += delta;

}

} // namespace invader

} // namespace ptc