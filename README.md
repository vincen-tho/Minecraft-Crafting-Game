# Tugas Besar IF2210 Minecraft Crafting Game

Permainan berbasis CLI yang menerapkan konsep Pemrograman Berorientasi Objek. Pada permainan ini pemain dapat melakukan crafting sebuah TOOL dari beberapa item yang tersedia dengan menyusun item tersebut pada crafting table sesuai dengan recipes. 

## Makefile Commands

Kasih `-s` kalau gak mau Makefile-nya nge-echo command.



### How To Run

Nge-run `src/main.cpp`

```
make -s run
```

Run `src/$(FOLDER)/main.cpp`

```
make drive_test TDIR=$(FOLDER)
```

Run test

```
make test
```

Hasil akan ada di folder `tests/`

Run check

```
make check
```

Hasil export dari test, akan di-check.

## What's Inside
This template consists of:
- config folder containing all the config files (items and recipes)
- tests folder containing two sample test files (input and answer)
- main.cpp containing the sample main code
- check.cpp containing the code for checking
- makefile for compiling and testing

## Running the Makefile
Make sure you are using Linux with C++17. WSL also works if you are using Windows.
```
sudo apt-get install make g++
make all
```
Using the sample main file, it should return that 1 out of 2 tests passed.

## Authors

| NIM      | NAMA                          |
|----------|-------------------------------|
| 13520006 | Vionie Novencia Thanggestyo   | 
| 13520015 | Jaya Mangalo Soegeng Rahardjo | 
| 13520093 | Vincent Ho                    |
| 13520135 | Muhammad Alif Putra Yasa      |
| 13520165 | Ghazian Tsabit Alkamil        |
