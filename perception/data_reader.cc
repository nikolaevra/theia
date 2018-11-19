//
// Created by ruslan.nikolaev on 11/18/18.
//

#include "perception/data_reader.hh"

namespace Reader {

DataReader::DataReader(const std::string &files_path)
    : data_path{files_path}, files_count{0} {
  std::cout << "Starting DataReader" << std::endl;
  std::cout << "Reading Images from path: " << files_path << std::endl;
}

cv::Mat DataReader::get_image(std::string &image_filename) {
  return imread(image_filename, cv::IMREAD_COLOR); // Read the file
}

void DataReader::start_stream(int limit) {
  std::ifstream infile(this->data_path);
  cv::Mat image;

  // Read in file contents line by line loading image specified at each
  // line of the file and passing it on to the downstream subscribers.
  if (infile.is_open()) {
    std::string line;

    while (getline(infile, line)) {
      // Read in the image as a cv::Mat.
      image = get_image(line);

      // Increment count of images that we have seen so far.
      this->files_count++;

      // Make early exit we have reached the limit of files to be read in.
      if (this->files_count == limit) {
        break;
      }

      // Notify downstream subscribers about the new image.
      this->notify_observers();
    }

    // At the end, close the file.
    infile.close();
  }
}

} // namespace Reader
