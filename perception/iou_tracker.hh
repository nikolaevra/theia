//
// IOU Tracker as presented in
// http://elvera.nue.tu-berlin.de/files/1517Bochinski2017.pdf
//

#pragma once

#include "perception_objects.hh"
#include <iostream>

namespace Perception {

class Tracker {
  Tracker();

  ~Tracker();

  std::vector<Track> track_iou(std::vector<Detection> detections, double sigma_l,
                               double sigma_h, double sigma_iou, int t_min);
};
} // namespace Perception
