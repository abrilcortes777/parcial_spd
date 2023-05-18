// C++ code
//
#define LED_VERDE 5
#define LED_ROJA 6
#define BOTON_ASC 13
#define BOTON_STOP 12
#define BOTON_DESC 11
#define LED_A 8
#define LED_B 7
#define LED_C A3
#define LED_D A2
#define LED_E A1
#define LED_F 9
#define LED_G 10
int contador = 0;
bool anulacionActivada = false;
void setup()
{
  pinMode(LED_ROJA, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_C, OUTPUT);
  pinMode(LED_D, OUTPUT);
  pinMode(LED_E, OUTPUT);
  pinMode(LED_F, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(BOTON_ASC, INPUT_PULLUP);
  pinMode(BOTON_STOP, INPUT_PULLUP);
  pinMode(BOTON_DESC, INPUT_PULLUP);
  Serial.begin(9600);
}
void loop()
{
	verificar_boton_anulacion();
  	if (!anulacionActivada) 
    {
    	subir_bajar_piso(BOTON_ASC);
    	subir_bajar_piso(BOTON_DESC);
    }
}
void subir_bajar_piso(int pin)
{
  int estadoAnterior = HIGH;
  int estadoActual = digitalRead(pin);
	
  if (estadoActual == LOW && estadoAnterior == HIGH) 
  {
    digitalWrite(LED_ROJA, LOW);
    digitalWrite(LED_VERDE, HIGH);
    
    if (pin == BOTON_ASC && contador < 9 )
    {
      Serial.println("Ascendiendo...\n");
      contador++;
      
    }
    else if (pin == BOTON_DESC && contador >= 0)
    {
      Serial.println("Descendiendo...\n");      
      contador--;
    }

    delay(3000);
    mostrar_piso();
  }

  estadoAnterior = estadoActual;
}

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
