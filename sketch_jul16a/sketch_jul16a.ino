const int joyX = A0; // 조이스틱의 X축 핀
const int joyY = A1; // 조이스틱의 Y축 핀
const int buttonPin2 = 2; // 버튼 핀
const int buttonPin3 = 3; // 버튼 핀
unsigned long startTime = 0;
unsigned long elapsedTime = 0;
int xValue, yValue;

void setup() {
    Serial.begin(115200);
    pinMode(joyX, INPUT);
    pinMode(joyY, INPUT);
    pinMode(buttonPin2, INPUT_PULLUP); // 버튼 핀 2를 내부 풀업 저항으로 설정
    pinMode(buttonPin3, INPUT_PULLUP); // 버튼 핀 3을 내부 풀업 저항으로 설정
    startTime = millis();
}

void loop() {
    elapsedTime = millis() - startTime;
    if(elapsedTime <= 3600000){
        xValue = analogRead(joyX); // X축 값 읽기
        yValue = analogRead(joyY); // Y축 값 읽기
    }
    else{
        xValue = analogRead(joyY); // X축 값 읽기
        yValue = analogRead(joyX); // Y축 값 읽기
    }

    bool button2Pressed = digitalRead(buttonPin2) == LOW;
    bool button3Pressed = digitalRead(buttonPin3) == LOW;

    // 시리얼로 값 전송
    Serial.print(xValue);
    Serial.print(",");
    Serial.print(yValue);
    Serial.print(",");
    Serial.print(button2Pressed ? 1 : 0); // 버튼 2 상태 전송 (1 또는 0)
    Serial.print(",");
    Serial.println(button3Pressed ? 1 : 0); // 버튼 3 상태 전송 (1 또는 0)
    Serial.println(elapsedTime / 1000);
    delay(10);
}