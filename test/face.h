#ifndef TEST_FACE_H_
#define TEST_FACE_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "face.hpp"


class ParentMock : public Face {
 public:
  // mock method for Ki
  MOCK_METHOD0(getDistance, double());
};

#endif /* TEST_FACE_H_ */
