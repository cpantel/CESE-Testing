#include "unity.h"
#include "Main.h"
#include "MockFunctions.h"

void setUp(void) {

}

void tearDown(void) {

}

void testMainShouldCallEnviarMensajeInicio() {
   enviarMensajeInicio_Expect();
   AppMain();
}

void testMainInitialState() {
   enviarMensajeInicio_Expect();
   AppMain();
   TEST_ASSERT_EQUAL(BAJA, context.frecuencia_envio);
   TEST_ASSERT_FALSE(context.acercamiento);
   TEST_ASSERT_FALSE(context.enviar_y_reiniciar);
}

void testInit() {
   stateToABIERTO();
   TEST_ASSERT_EQUAL(BAJA, context.frecuencia_envio);
   TEST_ASSERT_FALSE(context.acercamiento);
   TEST_ASSERT_FALSE(context.enviar_y_reiniciar);
}

void testEvaluarAcercamiento() {
   stateToABIERTO();
   sensor.acercamiento = 0;
   evaluarAcercamiento();
   TEST_ASSERT_EQUAL(BAJA, context.frecuencia_envio);
   TEST_ASSERT_FALSE(context.acercamiento);
   TEST_ASSERT_FALSE(context.enviar_y_reiniciar);

   sensor.acercamiento = 1;
   evaluarAcercamiento();
   TEST_ASSERT_EQUAL(ALTA, context.frecuencia_envio);
   TEST_ASSERT_FALSE(sensor.acercamiento);
   TEST_ASSERT_TRUE(context.acercamiento);
   TEST_ASSERT_TRUE(context.enviar_y_reiniciar);
}
/*
void testEvaluarModoAltoPorOcupacion() {
   stateToABIERTO();

   sensor.ocupacion = 1;
   evaluarModo();

   TEST_ASSERT_EQUAL(ALTA, context.frecuencia_envio);
   TEST_ASSERT_TRUE(context.enviar_y_reiniciar);

}
*/
void testSensoresNormal() {
   sensor.acercamiento = 0;
   sensor.ocupacion = 0;
   sensor.luz = 0;
   sensor.motor_bajando = 0;
   sensor.motor_subiendo = 0;
   sensor.fin_carrera_abajo = 0;

   sensor.fin_carrera_arriba = 1;
   TEST_ASSERT_TRUE(sensoresNormal());

   sensor.acercamiento = 1;
   TEST_ASSERT_FALSE(sensoresNormal());
}

void testState() {
  stateToABIERTO();

  TEST_ASSERT_EQUAL(ABIERTO,context.state);
  sensor.acercamiento = 1;

  evaluarModo();
  TEST_ASSERT_EQUAL(ACERCAMIENTO,context.state);
  
  

}


