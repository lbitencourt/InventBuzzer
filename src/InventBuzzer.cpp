#include <Arduino.h>

#include "InventBuzzer.h"

InventBuzzer::InventBuzzer(const uint8_t pin) : _pin(pin) {
  pinMode(_pin, OUTPUT);
}

void InventBuzzer::play(const uint8_t repeat, const uint16_t duration) {
  _repeat = repeat;
  _duration = duration;
  _stateBuzzer = true;
  _playing = true;
  _buzzingTime = millis();
  digitalWrite(_pin, HIGH);  // ligar o buzzer
}

void InventBuzzer::stop() {
  _playing = false;
  digitalWrite(_pin, LOW);  // desligar o buzzer
}

void InventBuzzer::update() {
  if (!_playing) {
    return;
  }

  if (_repeat <= 0) {
    stop();
    return;
  }

  if (millis() - _buzzingTime >= _duration) {
    _stateBuzzer = !_stateBuzzer;
    digitalWrite(_pin, _stateBuzzer ? HIGH : LOW);

    if (!_stateBuzzer) {
      _repeat--;
    }
    _buzzingTime = millis();
  }
}