Dpdl - Dynamic Packet Definition Language

			www.dpdl.io


provided by
SEE Solutions


# System requirements

'DpdlEngine lite' V1.0 requires a compatible Java Runtime Environment (JRE) >= version 1.5 specification

There are many java virtual machines available, the official Java JRE from Oracle can be downloaded from java.com website:
https://www.java.com/en/download/manual.jsp

The native Dpdl API library 'libdpdlnativeapi' is platform dependant and is available for the following platforms:
	* MacOS 13.4 (ARM)
	* Linux x86_64 (x84 64bit)
	* Raspberry PI (ARM
	
the native libraries are located in the corresponding platform/arch folder under './lib/native/'

Additional platforms can be compiled by us on your request by writing to info@seesolutions.it


# How to run

To start the DpdlClient console application simply run the following command:

On Linux/MacOS/Unix
```
sh runDpdlClient.sh
```

On Windows
```
runDpdlClient.bat
```

NOTE: If the latest version of Java has been installed use the following startup script:
```
sh run_DpdlClient_java20.sh
```


# Bluetooth stack compatibility

To use the Dpdl bluetooth API a compabible bluetooth stack needs to be available on the operating system.

Currently the available bluetooth implementation (JSR-82 ) interfaces with the Linux BlueZ, J2ME, JavaME, Mac OS X,
WIDCOMM, BlueSoleil and Microsoft Bluetooth stack found in Windows XP SP2 or Windows Vista and WIDCOMM and Microsoft Bluetooth stack on Windows Mobile.











