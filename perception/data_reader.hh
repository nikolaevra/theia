//
// Created by ruslan.nikolaev on 11/18/18.
//

#pragma once

#include <fstream>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#include "perception/publisher.hh"

namespace Reader {

class DataReader: public Comms::Publisher {

public:
    /// Constructor.
    explicit DataReader(const std::string &files_path);

    /// Destructor.
    ~DataReader() override = default;

    /// Loads image from the image_filename provided in arguments.
    inline cv::Mat get_image(std::string &image_filename);

    /// Starts reading image filename line by line from the data_path file.
    void start_stream(int limit);

private:
    /// Store the path to the file with all images to be read in.
    std::string data_path;

    /// Keep count of how many images have been read in over time.
    int files_count;
};

} // namespace Reader