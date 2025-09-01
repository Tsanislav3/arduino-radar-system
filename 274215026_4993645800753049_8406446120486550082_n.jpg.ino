
#include <Servo.h> // Добавя библиотеката за управление на серво мотори

const int trigPin = 10; // Дефинира пина, към който е свързан Trig на ултразвуковия сензор
const int echoPin = 11; // Дефинира пина, към който е свързан Echo на сензора

long duration;// Променлива за времето на пътуване на ултразвуковия сигнал
int distance;// Изчислено разстояние до обекта
Servo myServo; // Създава обект за серво мотор
void setup() { // Задава Trig пина като изход
  pinMode(trigPin, OUTPUT); // Задава Trig пина като изход
  pinMode(echoPin, INPUT);  // Задава Echo пина като вход
  Serial.begin(9600); // Стартира серийната комуникация на 9600 bps
  myServo.attach(12); // Свързва серво мотора към пин D12
}
void loop() {
  
  for(int i=15;i<=165;i++){  
  myServo.write(i);  // Завърта сервото до текущия ъгъл
  delay(30); // Кратка пауза за стабилизиране
  distance = calculateDistance(); // Изчислява разстоянието
  Serial.print(i);  // Изпраща ъгъла
  Serial.print(","); 
  Serial.print(distance); // Изпраща разстоянието
  Serial.print("."); // Край на пакета
  }
  //Повтаря предишните редове от 165 до 15 градуса
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
// Функция за изчисляване на разстоянието, измерено от ултразвуковия сензор
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Задава trigPin в състояние HIGH за 10 микросекунди
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Чете echoPin, връща времето за преминаване на звуковата вълна в микросекунди
  distance= duration*0.034/2;
  return distance;
}
