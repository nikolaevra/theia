#pragma once

#include "perception_objects.hh"

// Return the IoU between two boxes
inline float intersectionOverUnion(Perception::Detection box1,
                                   Perception::Detection box2);

// Returns the index of the bounding box with the highest IoU
inline int highestIOU(Perception::Detection box,
                      std::vector<Perception::Detection> boxes);
