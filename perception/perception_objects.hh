#include <utility>

#pragma once

#include <vector>

namespace Perception {

struct Detection {
  const int xmin;
  int ymin;
  int xmax;
  int ymax;
  float score;
};

class Track {
  const std::vector<Detection> _detections;
  const float _timestamp;
  const int track_id;

public:
  // Constructor.
  Track(std::vector<Detection> detections, float timestamp, int id)
      : _detections{std::move(detections)}, _timestamp{timestamp},
        track_id{id} {};

  // Default Destructor.
  ~Track() = default;
};
} // namespace Perception
