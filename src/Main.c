#include "Functions.h"
#include "Main.h"
#include "stdio.h"

void init(){
  state.frecuencia_envio = BAJA;
  state.acercamiento = 0;
  state.enviar_y_reiniciar = 0;
}

void evaluarAcercamiento(){

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


