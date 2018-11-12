#pragma once

namespace Perception {
    class Detection {
        int _xmin;
        int _ymin;
        int _xmax;
        int _ymax;

    public:
        // Constructor
        Detection(int xmin, int ymin, int xmax, int ymax): _xmin{xmin}, _ymin{ymin}, _xmax{xmax}, _ymax{ymax} {};

        // Destructor
        ~Detection() = default;

        // Get detections as vector
        std::vector<int> make_vector() {
            return std::vector<int>{_xmin, _ymin, _xmax, _ymax};
        }

        int get_xmin(){
            return _xmin;
        }

        int get_xmax(){
            return _xmax;
        }

        int get_ymin(){
            return _ymin;
        }

        int get_ymax(){
            return _ymax;
        }
    };

    class Track {
        std::vector<Detection> _detections;
        float _timestamp;
        int track_id;

    public:
        Track(std::vector<Detection> detections, float timestamp): _detections{detections}, _timestamp{timestamp};
        ~Track() = default;
    };
}