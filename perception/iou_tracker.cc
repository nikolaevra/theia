#include "iou_tracker.hh"

namespace Perception {
    Tracker::Tracker() {
        std::cout << "Initializing Tracker" << std::endl;
    }

    Tracker::~Tracker() {
        std::cout << "Killing Tracker" << std::endl;
    }

    std::vector<Track>
    Tracker::track_iou(std::vector<Detection> detections, double sigma_l, double sigma_h, double sigma_iou, int t_min) {
        std::vector<Track> tracks_active;
        std::vector<Track> tracks_finished;

        for (const auto & detection : detections) {

        }
        return std::vector<Track>();
    }
}
