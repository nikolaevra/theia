#pragma once

#include <string> // std::string
#include <map> // std::map
#include <utility> // std::pair
#include "subscriber.hh"

namespace Comms
{

class Publisher {
  /// Store pointers to all subscribers in a map, so that we can
  /// easily find them when unsubscribe is called.
  std::map<std::string, Subscriber *> subscribers;

 public:
  /// Constructor.
  Publisher() = default;

  /// Attach new subscribers to subscribers list.
  void attach(const std::string &name, const Subscriber *o) {
    subscribers.insert(std::pair<std::string, Subscriber *>{name, o});
  }

  /// Detach subscribers from subscribers list.
  void detach(const std::string &name) {
    // Remove the subscriber from the list.
    subscribers.erase(name);
  }

  /// Notify all subscribers about updated status of publisher.
  void notifyObservers() {
    for (const auto &sub:subscribers) {
      sub.second->notify(*this);
    }
  }
  virtual ~Publisher() = 0;
};

} // namespace Comms