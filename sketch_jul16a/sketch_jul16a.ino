// 아날로그 입력 핀 정의
const int VRxPin = A0;
const int VRyPin = A1;

// 매핑 함수: 0~1023 범위를 -1.0~1.0 범위로 변환
float mapJoystickValue(int value) {
    return ((float)value - 512.0) / 512.0;
}

void setup() {
    // 시리얼 통신 시작
    Serial.begin(9600);
}

void loop() {
    // 조이스틱 X, Y 값 읽기
    int xValue = analogRead(VRxPin);
    int yValue = analogRead(VRyPin);
    
    // 0~1023 값을 -1.0~1.0 값으로 변환
    float xMapped = mapJoystickValue(xValue);
    float yMapped = mapJoystickValue(yValue);
    
    // 변환된 값 출력
    Serial.print("X: ");
    Serial.print(xMapped);
    Serial.print("\tY: ");
    Serial.println(yMapped);
    
    // 100ms 대기
    delay(100);
}