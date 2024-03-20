//Declaração de variáveis
int led = 6;
int buzina = 7;
int sensor_temp = A0;
int temp_analogica = 0; 
int temp_celsius = 0;
int motor = 13;


void setup()
{
  //Ajustando as portas
  pinMode(led, OUTPUT);
  pinMode(buzina, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(sensor_temp, INPUT);
 
  Serial.begin(9600);
  
  //Deixando os dispositivos desligando
 
 //Testando os dispositivos
  Serial.println("Testando o motor: ");
  digitalWrite(motor,HIGH);
  delay(3000);
  Serial.println("Motor Desligado");
  digitalWrite(motor,LOW);

  Serial.println("Testando o led: ");
  digitalWrite(led,HIGH);
  delay(3000);
  Serial.println("led Desligado");
  digitalWrite(led,LOW);
  
  Serial.println("Testando a buzina: ");
  digitalWrite(buzina,HIGH);
  delay(3000);
  Serial.println("Buzina Desligada");
  digitalWrite(buzina,LOW);


}

void loop()
{
  //medição da temperatura analógica
  temp_analogica = analogRead(sensor_temp);
  
  //Transformação para temperatura em Celsius
  temp_celsius = map(((analogRead(sensor_temp) - 20) * 3.04), 0, 1023, -40, 125);
  
  //Mostrar leituras
  Serial.print("Medida ANALÓGICA da Temperatura: ");
  Serial.print(temp_analogica);
  Serial.println("");
  
  Serial.print("Temperatura em Celsius: ");
  Serial.print(temp_celsius);
  Serial.print("oC");
  Serial.println("");
  
  
  
  if( temp_celsius < 30 ){
    digitalWrite(led, LOW);
    digitalWrite (buzina, LOW);
    digitalWrite(motor, LOW);
  }
    
    
  if (temp_celsius >= 30 && temp_celsius <= 50){
    digitalWrite(motor, HIGH);
    digitalWrite(led, LOW);
    digitalWrite (buzina, LOW);
  }
  
  if( temp_celsius>50 ){
     digitalWrite(led, HIGH);
     digitalWrite(buzina, HIGH);
    digitalWrite(motor, LOW);
  }
  delay(2000);
}