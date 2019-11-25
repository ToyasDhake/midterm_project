#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <face.hpp>

class Gmock : public ::testing::Test {
 public:
  double get_Distance(std::unique_ptr<Face> node) {
     node->getDistance();
  }
};

