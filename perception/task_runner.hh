//
// Created by ruslan.nikolaev on 11/18/18.
//

#pragma once

#include <memory>

#include "config/CONFIG.hh"
#include "perception/data_reader.hh"
#include "perception/detector.hh"
#include "perception/iou_tracker.hh"
#include "perception/subscription_types.hh"

namespace Task {

class TaskRunner {
public:
  /// Constructor.
  explicit TaskRunner(const Config::TaskConfig config)
      : detector{std::make_shared<Perception::Detector>()},
        tracker{std::make_shared<Perception::Tracker>(
            config.SIGMA_L, config.SIGMA_H, config.SIGMA_IOU, config.T_MIN)},
        reader{std::make_shared<Reader::DataReader>(config.DATA_DIR)} {
    std::cout << "Building TaskRunner" << std::endl;

    // Attach Detector as a subscriber to the DataReader.
    reader->attach(SubscriptionType::Detector, detector);

    // Attach Tracker as a subscriber to the Detector.
    detector->attach(SubscriptionType::Tracker, tracker);
  }

  /// Destructor.
  ~TaskRunner() = default;

  /// Main method to start reading in data using the DataReader.
  void start_tracking() {
    std::cout << "Starting Tracking" << std::endl;

    reader->start_stream(config.IMG_LIMIT);
  };

private:
  /// Store the main task config structure.
  const Config::TaskConfig config;

  /// Store the detector.
  std::shared_ptr<Reader::DataReader> reader;

  /// Store the detector.
  std::shared_ptr<Perception::Detector> detector;

  /// Store the tracker.
  std::shared_ptr<Perception::Tracker> tracker;
};

} // namespace Task