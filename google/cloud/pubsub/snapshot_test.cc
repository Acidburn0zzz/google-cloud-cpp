// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "google/cloud/pubsub/snapshot.h"
#include <gmock/gmock.h>
#include <sstream>

namespace google {
namespace cloud {
namespace pubsub {
inline namespace GOOGLE_CLOUD_CPP_PUBSUB_NS {
namespace {

TEST(Snapshot, Basics) {
  Snapshot in("p1", "s1");
  EXPECT_EQ("p1", in.project_id());
  EXPECT_EQ("s1", in.snapshot_id());
  EXPECT_EQ("projects/p1/snapshots/s1", in.FullName());

  auto copy = in;
  EXPECT_EQ(copy, in);
  EXPECT_EQ("p1", copy.project_id());
  EXPECT_EQ("s1", copy.snapshot_id());
  EXPECT_EQ("projects/p1/snapshots/s1", copy.FullName());

  auto moved = std::move(copy);
  EXPECT_EQ(moved, in);
  EXPECT_EQ("p1", moved.project_id());
  EXPECT_EQ("s1", moved.snapshot_id());
  EXPECT_EQ("projects/p1/snapshots/s1", moved.FullName());

  Snapshot in2("p2", "s2");
  EXPECT_NE(in2, in);
  EXPECT_EQ("p2", in2.project_id());
  EXPECT_EQ("s2", in2.snapshot_id());
  EXPECT_EQ("projects/p2/snapshots/s2", in2.FullName());
}

TEST(Snapshot, OutputStream) {
  Snapshot in("p1", "s1");
  std::ostringstream os;
  os << in;
  EXPECT_EQ("projects/p1/snapshots/s1", os.str());
}

}  // namespace
}  // namespace GOOGLE_CLOUD_CPP_PUBSUB_NS
}  // namespace pubsub
}  // namespace cloud
}  // namespace google