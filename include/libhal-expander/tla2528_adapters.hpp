#pragma once
#include <libhal-expander/tla2528.hpp>
#include <libhal/adc.hpp>
#include <libhal/input_pin.hpp>
#include <libhal/output_pin.hpp>

namespace hal::expander {

class tla2528_output_pin : public hal::output_pin
{
public:
  ~tla2528_output_pin();
  friend tla2528_output_pin make_output_pin(
    tla2528& p_tla2528,
    hal::byte p_channel,
    hal::output_pin::settings const& p_settings);

private:
  tla2528_output_pin(tla2528& p_tla2528,
                     hal::byte p_channel,
                     hal::output_pin::settings const& p_settings);
  void driver_configure(settings const& p_settings);
  void driver_level(bool p_high);
  bool driver_level();
  tla2528* m_tla2528 = nullptr;
  hal::byte m_channel;
};
/**
 * @brief create a hal::output_pin driver using the tla2528 driver
 *
 * @param p_tla2528 tla2528 controling the output pin
 * @param p_channel pin acting as an output pin
 * @param p_settings output pin settings, default is push-pull and no resistor
 * @throws hal::argument_out_of_domain - if p_channel out of range (>7)
 * @throws hal::resource_unavailable_try_again - if an adapter has already been
 * been made for the pin
 * @throws hal::operation_not_supported - if the settings could not be achieved.
 */
tla2528_output_pin make_output_pin(
  tla2528& p_tla2528,
  hal::byte p_channel,
  hal::output_pin::settings const& p_settings = {
    .resistor = pin_resistor::none });

class tla2528_input_pin : public hal::input_pin
{
public:
  ~tla2528_input_pin();
  friend tla2528_input_pin make_input_pin(
    tla2528& p_tla2528,
    hal::byte p_channel,
    hal::input_pin::settings const& p_settings);

private:
  tla2528_input_pin(tla2528& p_tla2528,
                    hal::byte p_channel,
                    hal::input_pin::settings const& p_settings);
  void driver_configure(settings const& p_settings);
  bool driver_level();
  tla2528* m_tla2528 = nullptr;
  hal::byte m_channel;
};
/**
 * @brief create a hal::input_pin driver using the tla2528 driver
 *
 * @param p_tla2528 tla2528 controling the input pin
 * @param p_channel pin acting as an input pin
 * @param p_settings input pin settings, default is no resistor
 * @throws hal::argument_out_of_domain - if p_channel out of range (>7)
 * @throws hal::resource_unavailable_try_again - if an adapter has already been
 * been made for the pin
 * @throws hal::operation_not_supported - if the settings could not be achieved.
 */
tla2528_input_pin make_input_pin(tla2528& p_tla2528,
                                 hal::byte p_channel,
                                 hal::input_pin::settings const& p_settings = {
                                   .resistor = pin_resistor::none });

class tla2528_adc : public hal::adc
{
public:
  ~tla2528_adc();
  friend tla2528_adc make_adc(tla2528& p_tla2528, hal::byte p_channel);

private:
  tla2528_adc(tla2528& p_tla2528, hal::byte p_channel);
  float driver_read();
  tla2528* m_tla2528 = nullptr;
  hal::byte m_channel;
};
/**
 * @brief create a hal::adc driver using the tla2528 driver
 *
 * @param p_tla2528 tla2528 controling the adc
 * @param p_channel pin acting as an adc
 * @throws hal::argument_out_of_domain - if p_channel out of range (>7)
 * @throws hal::resource_unavailable_try_again - if an adapter has already been
 * been made for the pin
 */
tla2528_adc make_adc(tla2528& p_tla2528, hal::byte p_channel);

}  // namespace hal::expander
