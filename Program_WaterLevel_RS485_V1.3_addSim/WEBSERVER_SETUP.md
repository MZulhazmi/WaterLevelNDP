# Web Server Settings Configuration - Setup Guide

## Fitur yang Ditambahkan

### 1. **Asynchronous Web Server**
   - Menggunakan library `ESPAsyncWebServer` untuk non-blocking web server
   - Port: 80
   - Akses via: `http://192.168.4.1`

### 2. **EEPROM Storage**
   - Menyimpan konfigurasi kalibrasi (M, C) dan interval
   - Lokasi EEPROM:
     - Calibration M: Alamat 0-3
     - Calibration C: Alamat 4-7
     - Interval Minutes: Alamat 8-11

### 3. **Trigger Web Server**
   - Tekan tombol "OK" (setting button) di menu SETTING untuk mengaktifkan web server
   - Web server akan berjalan selama 5 menit (dapat disesuaikan)
   - Otomatis shutdown setelah timeout

### 4. **Web Interface**
   - Form input untuk Calibration M (Multiplier)
   - Form input untuk Calibration C (Constant)
   - Form input untuk Interval (minutes)
   - Tombol Save (menyimpan ke EEPROM)
   - Tombol Cancel (menutup koneksi)

## Penggunaan

### Startup Pertama Kali:
```cpp
vEEPROM_LoadSettings();  // Dipanggil otomatis di setup()
```

### Mengaktifkan Web Server:
1. Sentuh tombol Settings (>)
2. Sentuh tombol OK
3. Web server akan aktif dan siap menerima koneksi WiFi

### Koneksi ke Web Server:
1. Cari SSID: "Water Level NDP"
2. Password: "password123"
3. Buka browser: `http://192.168.4.1`
4. Update nilai-nilai kalibrasi
5. Klik Save untuk menyimpan ke EEPROM

## Fungsi-Fungsi Utama

### EEPROM Functions:
- `vEEPROM_LoadSettings()` - Memuat settings dari EEPROM
- `vEEPROM_SaveSettings()` - Menyimpan settings ke EEPROM

### Web Server Functions:
- `vStartWebServer()` - Mengaktifkan AP dan web server
- `vStopWebServer()` - Menonaktifkan web server dan AP
- `vSetupWebServer()` - Setup route dan handler
- `getSettingsHTML()` - Generate HTML interface

## Library yang Diperlukan
```cpp
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <EEPROM.h>
```

Pastikan library sudah terinstall di Arduino IDE:
- **AsyncTCP** - Oleh Me-No-Dev
- **ESPAsyncWebServer** - Oleh Me-No-Dev
- **EEPROM** - Built-in library

## Notes
- Web server berjalan di task terpisah (Task3) dengan priority 3
- Tidak mengganggu operasi touch screen dan data acquisition
- Nilai-nilai tersimpan permanen di EEPROM
- Interface responsive dan mobile-friendly
