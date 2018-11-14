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
 public:
  Tracker(const double sigma_l, const double sigma_h, const double sigma_iou, const int t_min);

  ~Tracker();

  void track_iou_per_frame(std::vector<Detection> &detections);

 private:
  std::vector<Track> active_tracks;
  std::vector<Track> finished_tracks;

  const double sigma_l;
  const double sigma_h;
  const double sigma_iou;
  const int t_min;
  unsigned int track_id = 1;
};
} // namespace Perception
