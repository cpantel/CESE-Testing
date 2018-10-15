#ifndef _MAIN_H_
#define _MAIN_H_

#define BAJA 10
#define ALTA 100

struct state_t {
  int frecuencia;
  int acercamiento;
  int enviar_y_reiniciar;
};

struct state_t getState();

int AppMain(void);
int main(void);

#endif // _MAIN_H_
