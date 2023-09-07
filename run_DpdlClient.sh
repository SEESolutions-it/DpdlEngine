#!/bin/sh
echo "starting Dpdl-Client..."
java -cp ./lib/mjcoap.jar:./lib/bitcoinj-core-0.16.jar -jar DpdlEngine_V1.0_release.jar
echo $?
