#include "Functions.h"
#include "Main.h"
#include "stdio.h"

int AppMain(void)
{
  enviarMensajeInicio();
  return 0;
}

#ifndef TEST
int main(void)
{
  return AppMain();
}
#endif // TEST


