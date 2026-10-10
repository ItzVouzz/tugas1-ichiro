# 🤖 MAINAN ROBOT

Proyek ini adalah simulasi terminal berbasis C++ tentang permainan sepak bola yang terdapat striker dan bola, di mana striker bertugas untuk mencari bola lalu menendangnya masuk ke gawang.

## 🚀 Panduan Running

1. **Compile** semua file menggunakan _command_ berikut:

```bash
g++ -I include src/*.cpp -o main
```

2. **Eksekusi** program dengan menjalankan perintah berikut sesuai sistem operasi Anda:

- Untuk **Windows**:

```bash
.\main
```

- Untuk **Linux / macOS**:

```bash
./main

```

## 🧪 Skenario Uji

Untuk mengubah koordinat robot maupun bola, Anda dapat melakukannya dengan mengubah isi dari file `config.txt`.

- **Sensor tidak mendeteksi bola:** Apabila bola tidak dalam jangkauan kamera robot, maka robot akan melakukan patroli keliling untuk mencari bola.
- **Robot menembak bola:** Apabila bola bisa langsung ditendang ke area gawang, maka robot akan langsung menendang sesuai arah di mana bola akan masuk ke dalam gawang.
- **Respawn bola:** Apabila bola yang ditendang tidak masuk ke dalam gawang dan malah menembus lapangan, maka bola akan di-_respawn_ kembali di titik `(0,0)`.

## 🧠 Alur State Kecerdasan Striker

Robot memiliki **3 fase** yang berjalan secara berulang (_Sense-Think-Act_), yaitu:

1. **Sense:** Berfungsi untuk menciptakan area pandang robot agar robot bisa mendeteksi bola di depan.
2. **Think:** Logika yang akan menentukan _state_ yang akan digunakan berdasarkan jarak dan posisi ideal.
3. **Act:** Bertugas mengeksekusi tugas fisik berdasarkan _state_ yang sedang aktif.

Di dalam fase _Act_, robot memiliki **4 _state_** utama:

- `SEARCH_BALL`: Bertugas untuk melakukan patroli guna mencari bola apabila bola tidak terdeteksi oleh kamera.
- `APPROACH_BALL`: Aktif apabila bola sudah terdeteksi oleh kamera. Berfungsi untuk mendekati bola dan memposisikan robot agar persis berada di belakang bola.
- `ALIGN_TO_GOAL`: Berfungsi mengatur orientasi agar robot menghadap tepat ke arah bola dan gawang.
- `KICK`: Robot menentukan sudut tendangan berdasarkan posisinya terhadap gawang lalu mengeksekusi tendangan pada bola.

**AI Digunakan untuk membantu menjelaskan logika state pada striker, menjelaskan konsep matematika vektor dan fisika pada program serta untuk mempercantik README.md**
