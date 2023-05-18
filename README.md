# Parcial SPD.
## 📚Alumno : Abril Cortés.
---
## ⬆️⬇️Proyecto: Montacargas
![(img-proyecto)](https://api-reader.tinkercad.com/api/images/86w6PLoSuVv/t725.jpg)
---
## 📝Decripción.
El proyecto consiste en la elaboración de un montacargas, con el total de nueve pisos.
 El montacargas cuenta con tres botones, uno para subir, uno para bajar y otro para parar cuando el usuario lo desee. También cuenta con dos luces
 LEDS que indicaran cuando el montacargas esta en movimiento (LED verde) y cuando este en pausa (LED roja).
## 💻Código fuente
~~~c++

void loop()
{
	verificar_boton_anulacion();
  	if (!anulacionActivada) 
    {
    	subir_bajar_piso(BOTON_ASC);
    	subir_bajar_piso(BOTON_DESC);
    }
}
~~~
La función principal llama a la funciones **'verificarBotonAnulacion'** que verificará si el botón de pausa ha sido presionado, también llamará dos veces a **'subir_bajar_piso'**,
si es que el botón de pausa no se presiono una vez, que se le pasará como parametros los botones de ascender o descender para ver qué función cumplir.

## 📌subir_bajar_piso()
~~~c++

void subir_bajar_piso(int pin)
{
  int estadoAnterior = HIGH;
  int estadoActual = digitalRead(pin);
	
  if (estadoActual == LOW && estadoAnterior == HIGH) 
  {
    digitalWrite(LED_ROJA, LOW);
    digitalWrite(LED_VERDE, HIGH);
    subsuelo();
    if (pin == BOTON_ASC && contador < 9 )
    {
      Serial.println("Ascendiendo...\n");
      contador++;
      
    }
    else if (pin == BOTON_DESC && contador > 0)
    {
      Serial.println("Descendiendo...\n");      
      contador--;
    }

    delay(3000);
    mostrar_piso();
  }

  estadoAnterior = estadoActual;
}
~~~
La función **'subir_bajar_piso'** recibe un argumento **'pin'**, que se espera sea el pin conectado a un botón. La funcion va a verificar si ese botón fue presionado o no.
Luego, dependiendo del valor de **'pin'**, se decide si el ascensor debe subir o bajar. Si se cumple la condición, el contador se incrementa o decrementa en uno y se enciende
la LED verde que indica el movimiento del montacargas, despues de tres segundos se muestra el piso.

## 📌mostar_piso()
~~~c++

void mostrar_piso()
{
  switch (contador)
  {
	case 0:
      Serial.println("Esta en la planta baja.\n");
      digitalWrite(LED_A, HIGH);
      digitalWrite(LED_B, HIGH);
      digitalWrite(LED_C, HIGH);
      digitalWrite(LED_D, HIGH);
      digitalWrite(LED_E, HIGH);
      digitalWrite(LED_F, HIGH);
      digitalWrite(LED_G, LOW);
      break;
    case 1:
      Serial.println("Esta en el piso 1.\n");
      digitalWrite(LED_A, LOW);
      digitalWrite(LED_B, LOW);
      digitalWrite(LED_C, LOW);
      digitalWrite(LED_D, LOW);
      digitalWrite(LED_E, LOW);
      digitalWrite(LED_F, LOW);
      digitalWrite(LED_G, LOW);
      delay(1000);
      digitalWrite(LED_B, HIGH);
      digitalWrite(LED_C, HIGH);
      break;
    case 2:
      Serial.println("Esta en el piso 2.\n");
      digitalWrite(LED_A, LOW);
      digitalWrite(LED_B, LOW);
      digitalWrite(LED_C, LOW);
      digitalWrite(LED_D, LOW);
      digitalWrite(LED_E, LOW);
      digitalWrite(LED_F, LOW);
      digitalWrite(LED_G, LOW);
      delay(1000);
      digitalWrite(LED_A, HIGH);
      digitalWrite(LED_B, HIGH);
      digitalWrite(LED_D, HIGH);
      digitalWrite(LED_E, HIGH);
      digitalWrite(LED_G, HIGH);
      break;
    case 3:
      Serial.println("Esta en el piso 3.\n");
      digitalWrite(LED_A, LOW);
      digitalWrite(LED_B, LOW);
      digitalWrite(LED_C, LOW);
      digitalWrite(LED_D, LOW);
      digitalWrite(LED_E, LOW);
      digitalWrite(LED_F, LOW);
      digitalWrite(LED_G, LOW);
      delay(1000);
      digitalWrite(LED_A, HIGH);
      digitalWrite(LED_B, HIGH);
      digitalWrite(LED_C, HIGH);
      digitalWrite(LED_D, HIGH);
      digitalWrite(LED_G, HIGH);
      break;
    case 4:
      Serial.println("Esta en el piso 4.\n");
      digitalWrite(LED_A, LOW);
      digitalWrite(LED_B, LOW);
      digitalWrite(LED_C, LOW);
      digitalWrite(LED_D, LOW);
      digitalWrite(LED_E, LOW);
      digitalWrite(LED_F, LOW);
      digitalWrite(LED_G, LOW);
      delay(1000);
      digitalWrite(LED_B, HIGH);
      digitalWrite(LED_C, HIGH);
      digitalWrite(LED_F, HIGH);
      digitalWrite(LED_G, HIGH);
      break;
    case 5:
      Serial.println("Esta en el piso 5.\n");
      digitalWrite(LED_A, LOW);
      digitalWrite(LED_B, LOW);
      digitalWrite(LED_C, LOW);
      digitalWrite(LED_D, LOW);
      digitalWrite(LED_E, LOW);
      digitalWrite(LED_F, LOW);
      digitalWrite(LED_G, LOW);
      delay(1000);
      digitalWrite(LED_A, HIGH);
      digitalWrite(LED_C, HIGH);
      digitalWrite(LED_D, HIGH);
      digitalWrite(LED_F, HIGH);
      digitalWrite(LED_G, HIGH);
      break;
    case 6:
       Serial.println("Esta en el piso 6.\n");
      digitalWrite(LED_A, LOW);
      digitalWrite(LED_B, LOW);
      digitalWrite(LED_C, LOW);
      digitalWrite(LED_D, LOW);
      digitalWrite(LED_E, LOW);
      digitalWrite(LED_F, LOW);
      digitalWrite(LED_G, LOW);
      delay(1000);
      digitalWrite(LED_A, HIGH);
      digitalWrite(LED_C, HIGH);
      digitalWrite(LED_D, HIGH);
      digitalWrite(LED_E, HIGH);
      digitalWrite(LED_F, HIGH);
      digitalWrite(LED_G, HIGH);
      break;
    case 7:
      Serial.println("Esta en el piso 7.\n");
      digitalWrite(LED_A, LOW);
      digitalWrite(LED_B, LOW);
      digitalWrite(LED_C, LOW);
      digitalWrite(LED_D, LOW);
      digitalWrite(LED_E, LOW);
      digitalWrite(LED_F, LOW);
      digitalWrite(LED_G, LOW);
      delay(1000);
      digitalWrite(LED_A, HIGH);
      digitalWrite(LED_B, HIGH);
      digitalWrite(LED_C, HIGH);
      break;
    case 8:
      Serial.println("Esta en el piso 8.\n");
      digitalWrite(LED_A, LOW);
      digitalWrite(LED_B, LOW);
      digitalWrite(LED_C, LOW);
      digitalWrite(LED_D, LOW);
      digitalWrite(LED_E, LOW);
      digitalWrite(LED_F, LOW);
      digitalWrite(LED_G, LOW);
      delay(1000);
      digitalWrite(LED_A, HIGH);
      digitalWrite(LED_B, HIGH);
      digitalWrite(LED_C, HIGH);
      digitalWrite(LED_D, HIGH);
      digitalWrite(LED_E, HIGH);
      digitalWrite(LED_F, HIGH);
      digitalWrite(LED_G, HIGH);
      break;
    case 9:
      Serial.println("Esta en el piso 9.\n");
      digitalWrite(LED_A, LOW);
      digitalWrite(LED_B, LOW);
      digitalWrite(LED_C, LOW);
      digitalWrite(LED_D, LOW);
      digitalWrite(LED_E, LOW);
      digitalWrite(LED_F, LOW);
      digitalWrite(LED_G, LOW);
      delay(1000);
        digitalWrite(LED_A, HIGH);
      digitalWrite(LED_B, HIGH);
      digitalWrite(LED_C, HIGH);
      digitalWrite(LED_F, HIGH);
      digitalWrite(LED_G, HIGH);
      break;
    default:
      break;
  }
}
~~~
La función **'mostar_piso'** va mostrar por el display de 7 segmentos el numero de piso al cual se esta subiendo y queda, dependendiendo del valor del contador se imprimira 
ese mismo número.

## 📌verificar_boton_anulacion()
~~~c++

void verificar_boton_anulacion()
{
  if (digitalRead(BOTON_STOP) == LOW)
  {
    anulacionActivada = !anulacionActivada;
    Serial.println("Oprimio el boton de emergencia");
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_ROJA, HIGH);
    delay(100);
  }
}
~~~
La función **'verificar_boton_anulacion()'** verifica el estado del **'BOTON_STOP'**. Si el estado del botón es LOW,
invierte el valor de la variable **'anulacionActivada'**. Como esta funcion verifica si el botón de parar fue presionado se enciende la LED roja en el caso de fue si asi,
se le agrega una espera de un segundo para no leer muchas pulsasiones del botón rapidamente.

## 🔗Link al proyecto
* [🤓 Proyecto montacargas](https://www.tinkercad.com/things/8gPbLob4mPs-parcial-spd-1j-abril-cortes/editel?sharecode=mgVoKSp-gr2PYlhrvtVOdlKrJzS3NGDAfYM06j65zEU)
---
