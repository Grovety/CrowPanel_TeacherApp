#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void ble_client_init(void);
void ble_send_message(const char* message);

#ifdef __cplusplus
}
#endif
