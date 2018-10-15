#include "Functions.h"
#include "Main.h"
#include "stdio.h"

void init(){
  context.frecuencia_envio = BAJA;
  context.acercamiento = 0;
  context.enviar_y_reiniciar = 0;
  context.state = ABIERTO;
}

void evaluarAcercamiento(){

  if (sensor.acercamiento) {
    context.acercamiento = 1;
    sensor.acercamiento = 0;
    context.frecuencia_envio = ALTA;
    context.enviar_y_reiniciar = 1;
  }
}

int sensoresNormal() {
  return (
    sensor.acercamiento == 0 &&
    sensor.ocupacion == 0 &&
    sensor.luz == 0 &&
    sensor.motor_bajando == 0 &&
    sensor.motor_subiendo == 0 &&
    sensor.fin_carrera_arriba == 1 &&
    sensor.fin_carrera_abajo == 0
  );
}

void evaluarModo() {
  if (sensor.acercamiento) {
    context.state = ACERCAMIENTO;
    context.frecuencia_envio = ALTA;
    context.enviar_y_reiniciar = 1;
  } 
}

int AppMain(void)
{
  init();
  enviarMensajeInicio();
  


  return 0;
}

#ifndef TEST
int main(void)
{
  return AppMain();
}
#endif // TEST


