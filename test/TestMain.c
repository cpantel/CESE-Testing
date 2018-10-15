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
   struct state_t state = getState();
   enviarMensajeInicio_Expect();
   AppMain();
   TEST_ASSERT_EQUAL(BAJA, state.frecuencia);
   TEST_ASSERT_FALSE(state.acercamiento);
   TEST_ASSERT_FALSE(state.enviar_y_reiniciar);

}
