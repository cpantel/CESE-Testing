#ifndef _MAIN_H_
#define _MAIN_H_

#define BAJA 10
#define ALTA 100

struct state_t {
  int frecuencia_envio;
  int acercamiento;
  int enviar_y_reiniciar;
};

struct sensor_t {
  int acercamiento;
};

struct state_t state;

struct sensor_t sensor;

int AppMain(void);
int main(void);
void init(void);

#endif // _MAIN_H_
