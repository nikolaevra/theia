//
// Created by ruslan.nikolaev on 11/18/18.
//

#include <iostream>

#include "perception/publisher.hh"
#include "perception/subscriber.hh"

namespace Comms {

void Publisher::notify_observers() {
  for (const auto &sub : this->subscribers) {
    sub.second->notify(*this);
  }
}

void Publisher::detach(const SubscriptionType &name) {
    std::cout << "Removing subscriber" << std::endl;

  // Remove the subscriber from the list.
  subscribers.erase(name);
}

void Publisher::attach(const SubscriptionType &name, std::shared_ptr<Subscriber> o) {
  std::cout << "Attaching new subscriber" << std::endl;

  subscribers.insert(std::pair<const SubscriptionType, std::shared_ptr<Subscriber>>(name, o));
}

} // namespace Comms