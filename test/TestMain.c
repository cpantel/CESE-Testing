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
   TEST_ASSERT_EQUAL(BAJA, state.frecuencia_envio);
   TEST_ASSERT_FALSE(state.acercamiento);
   TEST_ASSERT_FALSE(state.enviar_y_reiniciar);
}

void testInit() {
   init();
   TEST_ASSERT_EQUAL(BAJA, state.frecuencia_envio);
   TEST_ASSERT_FALSE(state.acercamiento);
   TEST_ASSERT_FALSE(state.enviar_y_reiniciar);

}

