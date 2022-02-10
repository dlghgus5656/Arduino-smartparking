#include <LiquidCrystal.h> //LCD 라이브러리 사용
LiquidCrystal lcd(12,11,2,3,4,5);//RS E D4 D5 D6 D7 LCD초기화함수

const int AlphaPin1 = 6;
const int DeltaPin1 = 7;
const int AlphaPin2 = 8;
const int DeltaPin2 = 9;
const int AlphaPin3 = 10;
const int DeltaPin3 = 13; //사용 핀
long continu1 = 0;
long continu2 = 0;
long continu3 = 0; //더 큰 수를 받기위해 long함수 사용
int value = 0; //초기 값 0
void setup() {
lcd.begin(16,2); //16글자 2행 LCD모니터 시작
  pinMode(AlphaPin1,OUTPUT);
  pinMode(DeltaPin1,INPUT);
  pinMode(AlphaPin2,OUTPUT);
  pinMode(DeltaPin2,INPUT);
  pinMode(AlphaPin3,OUTPUT);
  pinMode(DeltaPin3,INPUT); //핀들을 출력상태로
  Serial.begin(9600); //통신속도를 설정 9600비트 속도
  
}

void loop() {

//단위를 출력
  long continu1, interval1;
  
  long continu2,interval2;

  digitalWrite(AlphaPin2, HIGH);
  delay(5);
  digitalWrite(AlphaPin2, LOW); //digitalWrite을 사용해 8번 핀의 출력을 온 오프함

  continu2 = pulseIn(DeltaPin2, HIGH); //continu2에  pulseIn 함수를 사용해 9번핀에 들어오는 펄스신호의 길이를 감지하게 한다.

  interval2 = continu2/58; // 입력된 펄스의 시간을 58로 나눈다.

  Serial.print(interval2);
  Serial.print("cm"); //cm단위로 시리얼포트를 통해 출력한다.
  Serial.println();

  delay(200);
    
    long continu3, interval3;

  digitalWrite(AlphaPin3, HIGH);
  delay(5);
  digitalWrite(AlphaPin3, LOW); //digitalWrite을 사용해 10번 핀의 출력을 온 오프함

  continu3 = pulseIn(DeltaPin3, HIGH); //continu3에  pulseIn 함수를 사용해 13번핀에 들어오는 펄스신호의 길이를 감지하게 한다.

  interval3 = continu3/58;

  Serial.print(interval3);
  Serial.print("cm"); //cm단위로 시리얼포트를 통해 출력한다.
  Serial.println();
  
  digitalWrite(8,HIGH);
  
delayMicroseconds(10);//마이크로세컨드 단위로 일시중지한다.
digitalWrite(8,LOW);
long continu=pulseIn(9,HIGH);//왕복 시간을 구해준다.
long interval=continu/58; //값을 58로 나눈다.
Serial.println(interval);

if(interval2<20 && interval3<20) //논리곱 연산자를 사용해 왼쪽과 오른쪽이 모두 참일때 참이되는 if조건문을 만든다.
{
lcd.clear();//LCD 초기화
lcd.setCursor(0,0); //첫번째행 첫번째열 부터 출력
lcd.print("smart parking");
lcd.setCursor(0,1);//열, 행위치,커서출력 두번째행에 첫번째열 부터 출력
lcd.print("no spot");
 }
else if(interval2<20 || interval3<20) // 해당 interval(입력된 펄스 값을 58로 나눈 값)이 20보다 작을때 실행한다.
{
lcd.clear();//LCD 초기화
lcd.setCursor(0,0); //첫번째행 첫번째열 부터 출력
lcd.print("smart parking");
lcd.setCursor(0,1);//열, 행위치,커서출력 두번째행에 첫번째열 부터 출력
lcd.print("now empty spot 1");
 }
else
{
lcd.clear();//LCD 초기화
lcd.setCursor(0,0); //첫번째행 첫번째열 부터 출력
lcd.print("smart parking");
lcd.setCursor(0,1);//열, 행위치,커서출력 두번째행에 첫번째열 부터 출력
lcd.print("now empty spot 2");
 }
}
