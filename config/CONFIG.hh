//
// Created by ruslan.nikolaev on 11/18/18.
//
#pragma once

#include <iostream>

namespace Config {

struct TaskConfig {
  const double SIGMA_L = 0.3;
  const double SIGMA_H = 0.5;
  const double SIGMA_IOU = 0.3;
  const int T_MIN = 5;

  const std::string DATA_DIR = "data/";

  const int IMG_LIMIT = 1;
};

} // namespace Config
