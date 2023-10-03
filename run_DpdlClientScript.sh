#!/bin/sh
echo "starting Dpdl-Client..."
java -cp ./lib/:./lib/mjcoap.jar -Djava.library.path=./lib/native -jar DpdlEngine_V1.0_release.jar -load bluetoothDiscoverySave.h
echo $?
