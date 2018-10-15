#include "Functions.h"
#include "Main.h"
#include "stdio.h"

void stateToABIERTO(){
  context.frecuencia_envio = BAJA;
  context.acercamiento = 0;
  context.enviar_y_reiniciar = 0;
  context.state = ABIERTO;
}

void stateToACERCAMIENTO(void){
  context.frecuencia_envio = ALTA;
  context.enviar_y_reiniciar = 1;
  context.state = ACERCAMIENTO;
}

void stateToACTUANDO(void){
  context.frecuencia_envio = ALTA;
  context.enviar_y_reiniciar = 1;
  context.state = ACTUANDO;
}


void evaluarModo(){
  switch (context.state) {

    case ABIERTO:
      if (sensor.acercamiento) {
        stateToACERCAMIENTO();
        sensor.acercamiento = 0;
      }
    break;
    case ACERCAMIENTO:
      if (! sensoresNormal()) {
        stateToACTUANDO();
      }
    break;
    case ACTUANDO:
      if (sensoresNormal()) {
        stateToABIERTO();
      }
    break;
    default:
    break;
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

int AppMain(void)
{
  stateToABIERTO();
  enviarMensajeInicio();
  


  return 0;
}

#ifndef TEST
int main(void)
{
  return AppMain();
}
#endif // TEST


