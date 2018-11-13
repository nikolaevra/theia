#include "iou_tracker.hh"

namespace Perception {
Tracker::Tracker() { std::cout << "Initializing Tracker" << std::endl; }

Tracker::~Tracker() { std::cout << "Killing Tracker" << std::endl; }

// TODO: redefine track_iou to process one frame at a time
std::vector<Track>
track_iou(const std::vector<std::vector<Detection>> &detections,
          const double sigma_l, const double sigma_h, const double sigma_iou,
          const int t_min) {
  std::cout << "track_iou function" << std::endl;
  std::vector<Track> active_tracks;
  std::vector<Track> finished_tracks;
  int frame = 0;
  int track_id = 1; // Starting ID for the Tracks
  int index;        // Index of the box with the highest IOU
  bool updated;     // Whether if a track was updated or not
  int numFrames = detections.size();

  std::cout << "Num of frames > " << numFrames << std::endl;

  for (frame; frame < numFrames; frame++) {
    std::vector<Perception::Detection> frameBoxes = detections[frame];

    /// Update active tracks
    for (int i = 0; i < active_tracks.size(); i++) {
      Track track = active_tracks[i];
      updated = false;
      // Get the index of the detection with the highest IOU
      index = highestIOU(track.boxes.back(), frameBoxes);
      // Check is above the IOU threshold
      //			std::cout << " --- IOU Best match = " <<
      //intersectionOverUnion(track.boxes.back(), frameBoxes[index]) <<
      //std::endl;
      if (index != -1 &&
          intersectionOverUnion(track.boxes.back(), frameBoxes[index]) >=
              sigma_iou) {
        track.boxes.push_back(frameBoxes[index]);

        if (track.max_score < frameBoxes[index].score)
          track.max_score = frameBoxes[index].score;
        // Remove the best matching detection from the frame detections
        frameBoxes.erase(frameBoxes.begin() + index);
        active_tracks[i] = track;
        updated = true;
      }

      // If the track was not updated...
      if (!updated) {
        // Check the conditions to finish the track
        if (track.max_score >= sigma_h && track.boxes.size() >= t_min)
          finished_tracks.push_back(track);

        active_tracks.erase(active_tracks.begin() + i);
        // Workaround used because of the previous line "erase" call
        i--;
      }

    } // End for active tracks

    /// Create new tracks
    for (auto box : frameBoxes) {
      std::vector<Perception::Detection> b;
      b.push_back(box);
      // Track_id is set to 0 because we dont know if this track will
      // "survive" or not
      Track t = {b, box.score, frame, 0};
      active_tracks.push_back(t);
    }
    //		std::cout << "I tracked frame " << frame << std::endl;
  } // End of frames

  /// Finish the remaining tracks
  for (auto track : active_tracks)
    if (track.max_score >= sigma_h && track.boxes.size() >= t_min)
      finished_tracks.push_back(track);
  std::cout << "Num of finished tracks > " << finished_tracks.size()
            << std::endl;

  /// Enumerate only the remaining tracks aka the ones finished
  for (int i = 0; i < finished_tracks.size(); i++) {
    finished_tracks[i].id = track_id;
    track_id++;
  }

  return finished_tracks;
}
}
