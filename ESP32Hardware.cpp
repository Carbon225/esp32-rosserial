#include "ESP32Hardware.h"
#include "esp_timer.h"

#include "driver/uart.h"
#include "esp_log.h"

#include "esp32hardware_config.h"

static const char TAG[] = "esp32_hardware";

ESP32Hardware::ESP32Hardware()
{
	
}


void ESP32Hardware::init()
{
    ESP_LOGD(TAG, "init");
    const uart_config_t uart_config = {
        .baud_rate = ROS_UART_BAUD,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .rx_flow_ctrl_thresh = 122,
    };
    ESP_ERROR_CHECK(uart_param_config(ROS_UART_NUM, &uart_config));
    ESP_ERROR_CHECK(uart_set_pin(ROS_UART_NUM, ROS_UART_TX, ROS_UART_RX, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));
    ESP_ERROR_CHECK(uart_driver_install(ROS_UART_NUM, ROS_UART_BUF_SIZE, ROS_UART_BUF_SIZE, 0, NULL, 0));
}


int ESP32Hardware::read()
{
    uint8_t buf = 0;
    int length = uart_read_bytes(ROS_UART_NUM, &buf, 1, 1);
    return length > 0 ? buf : -1;
}

void ESP32Hardware::write(uint8_t *data, int length)
{
    uart_write_bytes(ROS_UART_NUM, (char *)data, length);
}

unsigned long ESP32Hardware::time()
{
    return (unsigned long) esp_timer_get_time() / 1000UL;
}

