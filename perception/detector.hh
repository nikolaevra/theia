//
// Created by ruslan.nikolaev on 11/18/18.
//

#pragma once

#include "perception/subscriber.hh"
#include "perception/publisher.hh"

namespace Perception {

class Detector : public Comms::Publisher, public Comms::Subscriber {
public:
  /// Constructor.
  Detector() = default;

  /// Destructor.
  ~Detector() override = default;

  void notify(Comms::Publisher &pub) override;
};

} // namespace Perception
