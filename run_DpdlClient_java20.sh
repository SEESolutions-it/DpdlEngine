#!/bin/sh
echo "starting Dpdl-Client..."
java --add-opens java.base/sun.net.www.protocol.http=ALL-UNNAMED --add-opens java.base/sun.net.www.protocol.https=ALL-UNNAMED -cp ./lib/mjcoap.jar -jar DpdlEngine_V1.0_release.jar
echo $?