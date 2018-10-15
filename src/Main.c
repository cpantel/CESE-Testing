#include "Functions.h"
#include "Main.h"
#include "stdio.h"

int AppMain(void)
{

  state.frecuencia_envio = BAJA;
  state.acercamiento = 0;
  state.enviar_y_reiniciar = 0;

  enviarMensajeInicio();

  return 0;
}

#ifndef TEST
int main(void)
{
  return AppMain();
}
#endif // TEST


