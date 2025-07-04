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

#include <libhal-expander/pca9685.hpp>
#include <libhal-util/serial.hpp>
#include <libhal-util/steady_clock.hpp>

#include <resource_list.hpp>

void application()
{
  using namespace std::chrono_literals;
  using namespace hal::literals;

  auto console = resources::console();
  auto i2c = resources::i2c();

  hal::print(*console, "[pca9685] Application Starting...\n\n");

  hal::expander::pca9685 pca9685(*i2c, 0b100'0000);
  auto pwm0 = pca9685.get_pwm_channel<0>();
  auto pwm1 = pca9685.get_pwm_channel<1>();
  auto pwm2 = pca9685.get_pwm_channel<2>();
  auto pwm3 = pca9685.get_pwm_channel<3>();
  auto pwm4 = pca9685.get_pwm_channel<4>();
  auto pwm5 = pca9685.get_pwm_channel<5>();
  auto pwm6 = pca9685.get_pwm_channel<6>();
  auto pwm7 = pca9685.get_pwm_channel<7>();
  auto pwm8 = pca9685.get_pwm_channel<8>();
  auto pwm9 = pca9685.get_pwm_channel<9>();
  auto pwm10 = pca9685.get_pwm_channel<10>();
  auto pwm11 = pca9685.get_pwm_channel<11>();
  auto pwm12 = pca9685.get_pwm_channel<12>();
  auto pwm13 = pca9685.get_pwm_channel<13>();
  auto pwm14 = pca9685.get_pwm_channel<14>();
  auto pwm15 = pca9685.get_pwm_channel<15>();

  // Setting the frequency of one channel will set the frequency of all channels
  pwm0.frequency(1.0_kHz);

  while (true) {
    for (float duty_cycle = 0.0f; duty_cycle < 1.05f; duty_cycle += 0.05f) {
      resources::sleep(50ms);
      pwm0.duty_cycle(duty_cycle);
      pwm1.duty_cycle(duty_cycle);
      pwm2.duty_cycle(duty_cycle);
      pwm3.duty_cycle(duty_cycle);
      pwm4.duty_cycle(duty_cycle);
      pwm5.duty_cycle(duty_cycle);
      pwm6.duty_cycle(duty_cycle);
      pwm7.duty_cycle(duty_cycle);
      pwm8.duty_cycle(duty_cycle);
      pwm9.duty_cycle(duty_cycle);
      pwm10.duty_cycle(duty_cycle);
      pwm11.duty_cycle(duty_cycle);
      pwm12.duty_cycle(duty_cycle);
      pwm13.duty_cycle(duty_cycle);
      pwm14.duty_cycle(duty_cycle);
      pwm15.duty_cycle(duty_cycle);
    }
  }
}
