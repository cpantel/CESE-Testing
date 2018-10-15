#ifndef _MAIN_H_
#define _MAIN_H_

#define BAJA 10
#define ALTA 100

enum state_t { ABIERTO, ACERCAMIENTO, ACTUANDO };

struct context_t {
  int frecuencia_envio;
  int acercamiento;
  int enviar_y_reiniciar;
  enum state_t state;
};

struct sensor_t {
  int acercamiento;
  int ocupacion;
  int luz;
  int motor_bajando;
  int motor_subiendo;
  int fin_carrera_arriba;
  int fin_carrera_abajo;
};

struct context_t context;

struct sensor_t sensor;


int AppMain(void);
int main(void);
void stateToABIERTO(void);
void evaluarAcercamiento(void);
void evaluarModo(void);
int sensoresNormal();

#endif // _MAIN_H_
