#pragma once

#include <ctime>
#include "iou_tracker.hh"

namespace Perception {

Tracker::Tracker(const double sigma_l, const double sigma_h, const double sigma_iou, const int t_min):
    sigma_l{sigma_l}, sigma_h{sigma_h}, sigma_iou{sigma_iou}, t_min{t_min},
    active_tracks{std::vector<Track>{}}, finished_tracks{std::vector<Track>{}}
{

  std::cout << "Initializing Tracker" << std::endl;
}

void Tracker::track_iou_per_frame(std::vector<Detection> &detections)
{
  // Index of the box with the highest IOU
  int index;
  // Whether if a track was updated or not
  bool updated = false;

  // Update active tracks
  for (int i = 0; i < this->active_tracks.size(); i++) {
    Track track = this->active_tracks[i];

    // Get the index of the detection with the highest IOU.
    // Compares the last detection in the track with current detections
    index = highestIOU(track.boxes.back(), detections);

    if (index != -1 && intersectionOverUnion(track.boxes.back(), detections[index]) >= this->sigma_iou) {
      // If the box is good match for the track, then add it to the track.
      track.boxes.push_back(detections[index]);

      // If we found the max iou box of all time for the track, then update track's max iou score
      if (track.max_score < detections[index].score)
        track.max_score = detections[index].score;

      // Remove the best matching detection from the frame detections
      detections.erase(detections.begin() + index);
      this->active_tracks[i] = track;
      updated = true;
    }

    // If the track was not updated
    if (!updated) {
      // Check the conditions to finish the track
      if (track.max_score >= this->sigma_h && track.boxes.size() >= this->t_min)
        this->finished_tracks.push_back(track);

      this->active_tracks.erase(this->active_tracks.begin() + i);
      // Need to decrement i because of the previous line "erase" call
      i--;
    }

  } // End for active tracks

  // Create new tracks
  for (auto box : detections) {
    std::vector<Detection> b;
    b.push_back(box);
    // Track_id is set to 0 because we don't know if this track will "survive" or not
    std::time_t timestamp = std::time(nullptr);
    Track t = {b, box.score, timestamp, this->track_id};
    this->track_id ++;
    this->active_tracks.push_back(t);
  }
}

// TODO: Not implemented
void Tracker::notify(Comms::Publisher &pub)
{

}

Tracker::~Tracker()
{
  std::cout << "Killing Tracker" << std::endl;
}

} // namespace Perception
