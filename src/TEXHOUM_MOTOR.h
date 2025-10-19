// Библиотека для управления моторами постоянного тока с помощью драйвера L298N
// Library for controlling DC motors using the L298N driver

// Автор библиотеки: Коркин Максим, Пятов Антон

#ifndef TEXHOUM_MOTOR_h
#define TEXHOUM_MOTOR_h
#include <Arduino.h>

class MOTOR {
public:
  MOTOR(byte dig, byte pwm);       // Инициализация (pin digital, pin pwm)
  void start(int speed);           // Запуск мотора (скорость от -100 до 100)
  void stop();                     // Остановка мотора
  void move(int speed, int time);  // Запуск мотора на заданное время (скорость от -100 до 100, время в миллисекундах)
private:
  byte _pin_DIG;  //	Номер цифрового пина
  byte _pin_PWM;  //	Номер ШИМ пина
  int _speed;     //  Текущая заданная скорость
};

extern MOTOR motor1;
extern MOTOR motor2;
extern MOTOR motor3;
extern MOTOR motor4;

#endif
