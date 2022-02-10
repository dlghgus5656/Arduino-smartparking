#include<Servo.h> //servo라이브러리 사용
Servo servo;
const int AlphaPin = 11;
const int DeltaPin = 12; //사용 핀
long continu = 0; //더 큰 수를 받기위해 long함수 사용
int value = 0; //초기 값 0

void setup() {
  pinMode(AlphaPin,OUTPUT);
  pinMode(DeltaPin,INPUT); //핀들을 출력상태로
  servo.attach(7); //attach함수를 사용해 서보모터를 7번 핀으로 컨트롤하기로 설정
  Serial.begin(9600); //통신속도를 설정 9600비트 속도
}

void loop() {
  long continu, interval;

  digitalWrite(AlphaPin, HIGH);
  delay(10);
  digitalWrite(AlphaPin, LOW); //digitalWrite을 사용해 11번 핀의 출력을 온 오프함

  continu = pulseIn(DeltaPin, HIGH); //continu에  pulseIn 함수를 사용해 12번핀에 들어오는 펄스신호의 길이를 감지하게 한다.

  interval = continu/58; //입력된 펄스의 시간을 58로 나눈다.

  Serial.print(interval);
  Serial.print("cm");  //cm단위로 시리얼포트를 통해 출력한다.
  Serial.println();

  delay(200);

  if (interval < 20) //interval값이 20보다 작을때 참이되는 조건문 생성
  {
    servo.write(90); //servo.write 함수를 사용해 각도를 서보모터의 각도를 90도로 설정
    delay(1000);
  }
  else if (interval > 40) //interval값이 40보다 클 때 참이되는 조건문 생성
  {
    servo.write(0); //servo.write 함수를 사용해 각도를 서보모터의 각도를 0도로 설정(제자리로 돌아가기 위함)
    delay(3000);
  }
}
