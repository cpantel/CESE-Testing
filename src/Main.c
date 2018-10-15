#include "Functions.h"
#include "Main.h"
#include "stdio.h"

void init(){
  state.frecuencia_envio = BAJA;
  state.acercamiento = 0;
  state.enviar_y_reiniciar = 0;
}

void evaluarAcercamiento(){

  if (sensor.acercamiento) {
    state.acercamiento = 1;
    sensor.acercamiento = 0;
    state.frecuencia_envio = ALTA;
    state.enviar_y_reiniciar = 1;
  }
}

void evaluarModo() {
  if (sensor.ocupacion ) {
    state.frecuencia_envio = ALTA;
    state.enviar_y_reiniciar = 1;
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


