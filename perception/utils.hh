#pragma once

#include "perception/perception_objects.hh"

// Return the IoU between two boxes
float intersectionOverUnion(Perception::Detection box1,
                                   Perception::Detection box2);

// Returns the index of the bounding box with the highest IoU
int highestIOU(Perception::Detection box,
                      std::vector<Perception::Detection> boxes);
