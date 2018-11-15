#pragma once

#include "publisher.hh"

namespace Comms {
class Subscriber {
 public:
  /// Constructor.
  Subscriber() = default;

  /// Method for the Publisher to notify me about updates.
  virtual void notify(Publisher &pub) = 0;

  /// Destructor.
  virtual ~Subscriber() = default;
};

} // namespace Comms