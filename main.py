import serial
from pynput.mouse import Controller

# 시리얼 포트 설정
ser = serial.Serial('/dev/ttyACM0', 9600)

# 마우스 컨트롤러 설정
mouse = Controller()

def map_value(value, from_min, from_max, to_min, to_max):
    # 값의 범위를 변환하는 함수
    return to_min + (float(value - from_min) / float(from_max - from_min) * (to_max - to_min))

while True:
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').rstrip()
        try:
            x_str, y_str = line.split('\t')
            x = float(x_str)
            y = float(y_str)

            # 조이스틱 값을 마우스 움직임으로 변환
            mouse_x = map_value(x, -1.0, 1.0, -500, 500)
            mouse_y = map_value(y, -1.0, 1.0, -500, 500)

            # 마우스 이동
            mouse.move(mouse_x, mouse_y)
        except ValueError:
            # 잘못된 데이터 형식을 읽었을 경우 무시
            continue
