#!/bin/sh
echo "starting Dpdl-Client..."
java -cp ./lib/mjcoap.jar -jar DpdlEngine_V1.0_release.jar -load bluetoothDiscoverySave.h
echo $?
