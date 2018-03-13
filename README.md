# Arkavquarium
An imitation of the popular old school game Insaniquarium written in C++.

## SOP Pengerjaan
### SOP Umum
1. Untuk kedepannya kompilasi menggunakan `cmake` sehingga untuk setiap file header dan implementasi tambahkan CMakeLists.txt (nanti gw aja yg bikin gpp) supaya ga perlu compile satu-satu, delete driver lalala kyk pas alstrukdat kemaren. UNTUK KEDEPANNYA YA. INI UNTUK KE DEPANNYA. KE. DE. PAN. NYA. buat milestone 1 tanggal 15 Maret karena cuma buat header doang blm perlu pake `cmake`.
2. PLIS INI DIPERHATIIN BIAR ENAK WKWKWKWK

### Isi Repository
Kalau mau ngebikin header liat dulu jenisnya (`data_structure` atau `object`) dan naroh di direktorinya jangan sampe salah  
Deskripsi folder dan isinya:
```
arkavquarium_oop/
├── build/
│   └── // semua executable hasil compile
├── driver/
│   └── // semua file main/driver yang akan di-compile
├── libs/
│   ├── data_structures/
│   │   ├── // semua file header dan implementasi struktur data dan CMakeLists-nya, contoh:
│   │   ├── LinkedList/
│   │   │   ├── LinkedList.hpp
│   │   │   ├── LinkedList.cpp
│   │   │   └── CMakeLists.txt
│   │   └── Point/
│   │       ├── Point.hpp
│   │       ├── Point.cpp
│   │       └── CMakeLists.txt
│   └── objects/
│       │   ├── // semua file header dan implementasi object pada game dan CMakeLists-nya, contoh:
│       ├── Fish/
│       │   ├── Fish.hpp
│       │   ├── Fish.cpp
│       │   └── CMakeLists.txt
│       └── Aquarium/
│           ├── Aquarium.hpp
│           ├── Aquarium.cpp
│           └── CMakeLists.txt
└── CMakeLists.txt
```

### Kompilasi pake cmake
NANTI AJA BUAT MILESTONE SELANJUTNYA GAPERLU SEKARANG :)