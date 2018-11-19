//
// Created by ruslan.nikolaev on 11/18/18.
//

#pragma once

/// Forward declare to avoid cyclical dependencies.
namespace Comms{
    class Publisher;
}

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