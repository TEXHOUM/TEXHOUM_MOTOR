// Библиотека для управления моторами постоянного тока с помощью драйвера L298N
// Library for controlling DC motors using the L298N driver

// Версия: 1.0
// Автор библиотеки: Коркин Максим, Пятов Антон

#ifndef TEXHOUM_MOTOR_h
#define TEXHOUM_MOTOR_h
#include <Arduino.h>

class	MOTOR {
  public:
    MOTOR(byte dig, byte pwm);	//	Инициализация (pin digital, pin pwm)
    void start(int speed);		  //	Запуск мотора (скорость от -255 до 255)
    void stop();                //  Остановка мотора
  private:
    byte _pin_DIG;		//	Номер цифрового пина
    byte _pin_PWM;		//	Номер ШИМ пина
};

extern MOTOR motor1;
extern MOTOR motor2;
extern MOTOR motor3;
extern MOTOR motor4;

#endif
