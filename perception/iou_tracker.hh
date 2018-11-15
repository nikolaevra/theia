//
// IOU Tracker as presented in
// http://elvera.nue.tu-berlin.de/files/1517Bochinski2017.pdf
//

#pragma once

#include "perception_objects.hh"
#include "utils.hh"
#include "subscriber.hh"
#include <iostream>

namespace Perception {

class Tracker: public Comms::Subscriber {
 public:
  /// Constructor.
  Tracker(const double sigma_l, const double sigma_h, const double sigma_iou, const int t_min);

  /// Main method to track the object from frame to frame. Given a list of
  /// new detections, the tracker updates all tracks that are active and
  /// finished.
  void track_iou_per_frame(std::vector<Detection> &detections);

  /// Method to provide to the published so that it can notify us about updates.
  void notify(Comms::Publisher &pub) override;

  /// Destructor.
  ~Tracker() override;

 private:
  /// Store all the active tracks that are happening in the video right now.
  std::vector<Track> active_tracks;

  /// Store all the finished tracks that have been reaped.
  std::vector<Track> finished_tracks;

  /// Store all the constants required for tracker.
  const double sigma_l;
  const double sigma_h;
  const double sigma_iou;
  const int t_min;

  /// Keep track of the track id's so that we can continuously increment
  /// the tracks and not act like we are seeing same object twice.
  /// Will have to get more suffisticated than an int later on.
  unsigned int track_id = 1;
};

} // namespace Perception
