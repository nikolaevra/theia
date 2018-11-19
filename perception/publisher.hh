//
// Created by ruslan.nikolaev on 11/18/18.
//

#pragma once

#include <map>     // std::unordered_map
#include <memory>  // std::shared_ptr, std::make_shared
#include <string>  // std::string
#include <utility> // std::pair

#include "perception/subscription_types.hh"

/// Forward declare to avoid cyclical dependencies.
namespace Comms {
class Subscriber;
}

namespace Comms {

class Publisher {
public:
  /// Constructor.
  Publisher() = default;

  /// Attach new subscribers to subscribers list.
  void attach(const SubscriptionType &name, std::shared_ptr<Subscriber> o);

  /// Detach subscribers from subscribers list.
  void detach(const SubscriptionType &name);

  /// Notify all subscribers about updated status of publisher.
  void notify_observers();

  /// Pure virtual constructor.
  virtual ~Publisher() = 0;

private:
  /// Store pointers to all subscribers in a map, so that we can
  /// easily find them when unsubscribe is called.
  std::map<const SubscriptionType, std::shared_ptr<Subscriber>> subscribers;
};

} // namespace Comms