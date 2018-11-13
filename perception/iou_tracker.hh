//
// IOU Tracker as presented in
// http://elvera.nue.tu-berlin.de/files/1517Bochinski2017.pdf
//

#pragma once

#include "perception_objects.hh"
#include "utils.hh"
#include <iostream>

namespace Perception {

class Tracker {
  Tracker();

  ~Tracker();

  std::vector<Track>
  track_iou(const std::vector<std::vector<Detection>> &detections,
            const double sigma_l, const double sigma_h, const double sigma_iou,
            const int t_min);
};
} // namespace Perception
