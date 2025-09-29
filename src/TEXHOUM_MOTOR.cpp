#include "TEXHOUM_MOTOR.h"

// инициализация модуля
MOTOR::MOTOR(byte dig, byte pwm) {
  _pin_DIG=dig; pinMode(_pin_DIG, OUTPUT);  // инициализация цифрового пина
  _pin_PWM=pwm; pinMode(_pin_PWM, OUTPUT);  // инициализация ШИМ пина
  digitalWrite(_pin_DIG, LOW);
  analogWrite(_pin_PWM, 0);
}
// Запуск мотора
void MOTOR::start(int speed){
  if (speed >= 0) {
    digitalWrite(_pin_DIG, LOW);
    analogWrite(_pin_PWM, speed);
  }
  if (speed < 0) {
    digitalWrite(_pin_DIG, HIGH);
    analogWrite(_pin_PWM, (255+speed));
  }
}

// Остановка мотора
void MOTOR::stop(){
    digitalWrite(_pin_DIG, LOW);
    analogWrite(_pin_PWM, LOW);
}

// моторы, согласно схеме
MOTOR motor1(26, 7);
MOTOR motor2(24, 5);
MOTOR motor3(22, 4);
MOTOR motor4(14, 6);
