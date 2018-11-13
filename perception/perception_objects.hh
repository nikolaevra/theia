#pragma once

#include <vector>

namespace Perception {

struct Detection {
    // x-component of top left coordinate
    float x;
    // y-component of top left coordinate
    float y;
    // width of the box
    float w;
    // height of the box
    float h;
    // score of the box;
    float score;
};

struct Track {
  std::vector<Detection> boxes;
  float max_score;
  int start_frame;
  int id;
};

} // namespace Perception
