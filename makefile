CC=g++
LIBS=-lpthread `pkg-config --libs opencv` -lsqlite3
CFLAGS=-std=c++11 -Wall -fPIC
DEST=bin

all : hades hadesd

clean :
	rm hades hadesd

hades : hades.cpp
	$(CC) hades.cpp -o $(DEST)/hades $(LIBS) $(CFLAGS)

hadesd : hadesd.cpp
	$(CC) hadesd.cpp -o $(DEST)/hadesd $(LIBS) $(CFLAGS)

ACC=/opt/android/android-21/bin/arm-linux-androideabi-g++
ACFLAGS=-std=c++11 -Wall -pie

a_hades: hades.cpp
	$(ACC) hades.cpp -o $(DEST)/hades $(LIBS) $(ACFLAGS)

a_hadesd: hadesd.cpp
	$(ACC) hadesd.cpp -o $(DEST)/hadesd $(ACFLAGS)

a_all : a_hades a_hadesd
	adb push bin/hades /sdcard/
	adb push bin/hadesd /sdcard/
	adb shell /sdcard/pp

a_install : a_all
	adb shell "mount -o rw,remount /system"
	adb push bin/hades /system/bin/
	adb push bin/hadesd /system/bin/
	adb shell "mount -o ro,remount /system"

a_install_hadesd : a_hadesd
	adb shell "mount -o rw,remount /system"
	adb push bin/hadesd /system/bin/
	adb shell "mount -o ro,remount /system"
