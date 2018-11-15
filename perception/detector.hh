#pragma once

#include "publisher.hh"

namespace Perception
{
class Detector: public Comms::Publisher
{
 public:
  /// Constructor.
  Detector();

  /// Destructor.
  ~Detector() override;
};
} // namespace Perception
