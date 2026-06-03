# Xe điều khiển Bluetooth dùng STM32

Dự án xe điều khiển từ xa sử dụng vi điều khiển STM32, module Bluetooth HC-05 và mạch điều khiển động cơ. Xe nhận lệnh điều khiển qua UART từ điện thoại, sau đó điều khiển hai động cơ DC để di chuyển tiến, lùi, trái, phải hoặc dừng.

## Tính năng chính

* Điều khiển xe qua Bluetooth HC-05.
* Giao tiếp UART với tốc độ baudrate 9600.
* Điều khiển 2 động cơ DC.
* Hỗ trợ các hướng di chuyển:

  * Tiến
  * Lùi
  * Rẽ trái
  * Rẽ phải
  * Dừng
* Điều chỉnh tốc độ bằng PWM.
* Code được tách thành các module riêng như `car`, `motor`, `pwm`.

## Phần cứng sử dụng

* STM32F103C8T6
* Module Bluetooth HC-05
* Driver động cơ L298N hoặc module tương đương
* 2 động cơ DC
* Nguồn cấp cho STM32 và động cơ
* Khung xe robot

## Giao tiếp điều khiển

Xe nhận ký tự từ điện thoại thông qua Bluetooth:

| Ký tự     | Chức năng         |
| --------- | ----------------- |
| `F`       | Tiến              |
| `B`       | Lùi               |
| `L`       | Rẽ trái           |
| `R`       | Rẽ phải           |
| `S`       | Dừng              |
| `0` - `9` | Điều chỉnh tốc độ |

## Cấu trúc thư mục

```text
Xe_dieu_khien_STM32/
├── Core/              # Source code chính do STM32CubeMX sinh ra
├── Drivers/           # Thư viện HAL và CMSIS
├── MDK-ARM/           # Project Keil uVision
├── myLib/             # Thư viện tự viết
│   ├── car.c / car.h
│   ├── motor.c / motor.h
│   └── pwm.c / pwm.h
└── Project_Xe_dieu_khien_Bluetooth.ioc
```

## Nguyên lý hoạt động

Điện thoại gửi lệnh điều khiển qua Bluetooth HC-05. Module HC-05 truyền dữ liệu UART đến STM32. STM32 đọc từng ký tự nhận được, sau đó gọi hàm điều khiển xe tương ứng.

Ví dụ:

* Nhận `F` → xe chạy tiến.
* Nhận `B` → xe chạy lùi.
* Nhận `L` → xe rẽ trái.
* Nhận `R` → xe rẽ phải.
* Nhận `S` → xe dừng.
* Nhận số từ `0` đến `10` → thay đổi tốc độ PWM.

## Công nghệ sử dụng

* Ngôn ngữ C
* STM32 HAL Library
* STM32CubeMX
* Keil uVision
* UART Interrupt
* PWM Timer
* GPIO Control


