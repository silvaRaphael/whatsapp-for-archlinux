gcc -o app main.c -Wall $(pkg-config --cflags --libs gtk+-3.0 webkit2gtk-4.0)