/**
 * @file InventBuzzer.h
 * @brief Declaration of InventBuzzer class to control a buzzer device.
 * @author Leandro Bitencourt
 * @date jan 2026
 */
#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class InventBuzzer {
 public:
  InventBuzzer(const uint8_t pin);
  void play(const uint8_t repeat, const uint16_t duration);
  void stop();
  void update();

 private:
  uint8_t _pin;
  uint8_t _repeat = 0;
  uint16_t _duration = 0;
  uint32_t _buzzingTime = 0;
  bool _playing = false;
  bool _stateBuzzer = false;
};

#endif  // BUZZER_H