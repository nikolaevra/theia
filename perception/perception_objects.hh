#pragma once

#include <vector>
#include <ctime>

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
  // List storing all the detections.
  std::vector<Detection> boxes;
  // Max score even encountered in the track.
  float max_score;
  // Timestamp from the moment track was created.
  std::time_t start_frame;
  // Track unique id number.
  unsigned int id;
};

} // namespace Perception
