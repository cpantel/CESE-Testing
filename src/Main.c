#include "Functions.h"
#include "Main.h"
#include "stdio.h"

struct state_t state;

struct state_t getState() {
  return state;
}

int AppMain(void)
{

  state.frecuencia = BAJA;
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


