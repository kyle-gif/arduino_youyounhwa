// 아날로그 입력 핀 정의
const int VRxPin = A0;
const int VRyPin = A1;

void setup() {
    Serial.begin(9600); // 시리얼 통신 시작
}

void loop() {
    // 조이스틱 X, Y 값 읽기
    int xValue = analogRead(VRxPin);
    int yValue = analogRead(VRyPin);
    
    // 0~1023 값을 -1.0~1.0 값으로 변환
    float xMapped = ((float)xValue - 512.0) / 512.0;
    float yMapped = ((float)yValue - 512.0) / 512.0;
    
    // 변환된 값 전송
    Serial.print(xMapped);
    Serial.print("\t");
    Serial.println(yMapped);
    
    // 100ms 대기
    delay(100);
}
