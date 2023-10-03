#!/bin/sh
echo "starting Dpdl-Client..."
java --add-opens java.base/sun.net.www.protocol.http=ALL-UNNAMED --add-opens java.base/sun.net.www.protocol.https=ALL-UNNAMED -cp ./lib/:./lib/mjcoap.jar -Djava.library.path=./lib/native -jar DpdlEngine_V1.0_release.jar
echo $?