#pragma once

#include <qd_single.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/reporters/catch_reporter_event_listener.hpp>

class QDSetupListener : public Catch::EventListenerBase {
 public:
  using EventListenerBase::EventListenerBase;

  void testRunStarting([[maybe_unused]] Catch::TestRunInfo const& info) override {
    unsigned int old_cw = 0;
    fpu_fix_start(&old_cw);
  }
};
