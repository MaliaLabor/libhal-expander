// Copyright 2024 - 2025 Khalil Estell and the libhal contributors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <libhal-micromod/micromod.hpp>

#include <resource_list.hpp>

resource_list initialize_platform()
{
  using namespace hal::literals;

  hal::micromod::v1::initialize_platform();

  return {
    .reset = +[]() { hal::micromod::v1::reset(); },
    .console = &hal::micromod::v1::console(hal::buffer<128>),
    .clock = &hal::micromod::v1::uptime_clock(),
    .status_led = &hal::micromod::v1::led(),
    // NOTE: no i2c yet! Will add after mod-stm32f1-v4
    // .i2c = &hal::micromod::v1::i2c(),
  };
}
