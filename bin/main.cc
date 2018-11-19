//
// Created by ruslan.nikolaev on 11/18/18.
//

#include "perception/task_runner.hh"
#include "config/CONFIG.hh"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Task::TaskRunner vision_task = Task::TaskRunner{Config::TaskConfig{}};
    vision_task.start_tracking();
}