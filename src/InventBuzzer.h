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
  uint8_t _repeat;
  uint16_t _duration;
  uint32_t _buzzingTime;
  bool _playing;
  bool _stateBuzzer;
};

#endif  // BUZZER_H