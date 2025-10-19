#include "TEXHOUM_MOTOR.h"

// инициализация модуля
MOTOR::MOTOR(byte dig, byte pwm) {
  _pin_DIG = dig;
  pinMode(_pin_DIG, OUTPUT);  // инициализация цифрового пина
  _pin_PWM = pwm;
  pinMode(_pin_PWM, OUTPUT);  // инициализация ШИМ пина
  digitalWrite(_pin_DIG, LOW);
  analogWrite(_pin_PWM, 0);
}
// Запуск мотора
void MOTOR::start(int speed) {
  _speed = constrain(speed, -100, 100);             // ограничиваем скорость speed допустимым диапазоном и записываем её как параметр мотора _speed
  int voltage = map(_speed, -100, 100, -255, 255);  // переводим скорость в вольтаж, пропорционально перенося значение между диапазонами
  if (voltage >= 0) {
    digitalWrite(_pin_DIG, LOW);
    analogWrite(_pin_PWM, voltage);
  }
  if (voltage < 0) {
    digitalWrite(_pin_DIG, HIGH);
    analogWrite(_pin_PWM, (255 + voltage));
  }
}

// Остановка мотора
void MOTOR::stop() {
  digitalWrite(_pin_DIG, LOW);
  analogWrite(_pin_PWM, LOW);
}

// Запуск мотора на заданное время
void MOTOR::move(int speed, int time) {
  _speed = constrain(speed, -100, 100);             // ограничиваем скорость speed допустимым диапазоном
  int voltage = map(_speed, -100, 100, -255, 255);  // переводим скорость в вольтаж, пропорционально перенося значение между диапазонами
  // запускаем моторы
  if (voltage >= 0) {
    digitalWrite(_pin_DIG, LOW);
    analogWrite(_pin_PWM, voltage);
  }
  if (voltage < 0) {
    digitalWrite(_pin_DIG, HIGH);
    analogWrite(_pin_PWM, (255 + voltage));
  }
  delay(time);  // ждём
  //останавливаем моторы
  digitalWrite(_pin_DIG, LOW);
  analogWrite(_pin_PWM, LOW);
}

// моторы, согласно схеме
MOTOR motor1(26, 7);
MOTOR motor2(24, 5);
MOTOR motor3(22, 4);
MOTOR motor4(14, 6);
