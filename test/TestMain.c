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
