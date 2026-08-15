/**
 * @file InventBuzzer.h
 * @brief Declaration of IBuzzer interface and InventBuzzer class to control a buzzer device.
 * @author Leandro Bitencourt
 * @date jan 2026
 */
#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class IBuzzer {
 public:
  virtual ~IBuzzer() = default;
  virtual void play(const uint8_t repeat, const uint16_t duration) = 0;
  virtual void stop() = 0;
  virtual void update() = 0;
};

class InventBuzzer : public IBuzzer {
 public:
  InventBuzzer(const uint8_t pin);
  void play(const uint8_t repeat, const uint16_t duration) override;
  void stop() override;
  void update() override;

 private:
  uint8_t _pin;
  uint8_t _repeat = 0;
  uint16_t _duration = 0;
  uint32_t _buzzingTime = 0;
  bool _playing = false;
  bool _stateBuzzer = false;
};

#endif  // BUZZER_H