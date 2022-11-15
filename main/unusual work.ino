#define ADC_REF 5 //la tension de référence de l'ADC est de 5v. Si l'interrupteur Vcc du seeeduino
                    //la carte passe à 3V3, l'ADC_REF doit être à 3.3
#define GROVE_VCC 5 //VCC de l'interface grove est normalement 5v
#define FULL_ANGLE 679 // L'angle maximal du grove: angle_sensor est 679°
 
// cette variable entière va conserver la valeur de la lumière
int luminosite = 0;


// boucle d'initialisation. 
void setup()
{
Serial.begin(9600);
  
pinMode(A5, INPUT);
pinMode(A1, INPUT);
pinMode(3, OUTPUT);

}

//boucle d'infini. 
void loop()
{
    // mesure la tension sur la broche A5 et on la stocke dans la variable "luminosite". 
   luminosite = analogRead(A5);
  Serial.println("luminosité"); 
  Serial.println(luminosite);
  
  // on utilise quelques formules de maths pour calculer la valeur du potentiomètre. 
  float voltage;
    int sensor_value = analogRead(A1);
  voltage = (float)sensor_value*ADC_REF/1023;
    int seuil = (voltage*FULL_ANGLE)/GROVE_VCC;
  Serial.println("pot");
  Serial.println(seuil);

   // allume la LED
  if (luminosite<seuil) {digitalWrite(3, HIGH);}

   // désactiver la LED
  if (luminosite>seuil) {digitalWrite(3, LOW);}

   delay(200);
}
