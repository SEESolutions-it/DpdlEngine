
# Dpdl - Dynamic Packet Definition Language

				www.dpdl.biz


developed by
SEESolutions.it


## What is Dpdl?

Dpdl is a constraint device framework and library that can be used to encode,
store, control, visualize and query data efficiently on small memory footprint 
devices. Dpdl provides an efficient way to encode, allocate and query data from
a 'DpdlPacket', a highly compressed executable data container with built-in
database technology, that is encoded with a defined Dpdl code definition file.

Dpdl includes also a compact scripting engine and an extensible API interface
to facilitate the development of custom API extensions by using the Dpdl scripting
language. 

Dpdl supports common IoT protocol stacks such as Bluetooth(tm) and
CoAP (Constraint Device Application Protocol) and can be extended
with other protocols. Dpdl development has been started back in year 2003,
where mobile phones had very limited computer, memory and storage capacity.

![Dpdl stack](http://www.seesolutions.it/images/app/thumb/Dpdl_Dynamic_Packet_Definition_Language_components_thumb.jpg)

Sample Dpdl script (Bluetooth discovery):
```python
     int status = DPDLAPI_searchClientsOnServer()
     int status_discovery = dpdlFalse
     int service_discovery = dpdlFalse
     int counter = 0
     if(status == dpdlTrue)
	     while (status_discovery != dpdlTrue) && (service_discovery != dpdlTrue)
	         status_discovery = DPDLAPI_discoveryServerFinished()
	         service_discovery = DPDLAPI_serviceDiscoveryServerFinished()
	         print(".")
	         counter = counter+1
	         sleep(3000)
	     endwhile
		 string dev = "n"
		 int dev_found = 0
	     while(dev != "null")
	          dev = DPDLAPI_getServerVisibleBTAddr()
	          if(dev != "null")
	              println("bluetooth device visible: " + dev)
	              saveData(dev)
				  dev_found = dev_found + 1
	          fi
	     endwhile
     else
     	println("No working Bluetooth stack found")
     fi
```

## Why Dpdl?

Dpdl can be used to implement applications in various domains, in particular for small
memory footprint devices. The DpdlPacket data container is a highly optimized way to store 
and access data on devices that have limited memory and storage capabilities. 

Features:

* DpdlEngine is optimized to run on a wide range of platforms (J2ME, JavaME, J2SE)
* Packing data in a DpdlPacket is very convenient to optimize and speedup access to data.
  The speedup is x 25 times faster compared to a standard record store access.
* Dpdl scripting API provides access to the complete underlying Java platform API and to
  other external libraries via the loadObj(..) and getClass(..) methods
* The Dpdl scripting API can be easily extended with custom API extensions (via the DpdlExtension interface)
* Supports common IoT open source protocol stacks such as Bluetooth(tm) and CoAP
* Virtual filesystem for record stores
* Dpdl scripting language is simple and easy to learn
* Enables fast prototyping


## Which platforms are supported?

Dpdl runs on a wide range of platforms and provides also a small footprint java virtual machine,
released as open-source, that can  be compiled for almost every platform as soon as
an ANSI C compiler is available.

Dpdl is compatible with:

* J2ME MIDP (Mobile Information Device Profile) -> MIDP 1.0 and MIDP 2.0 (CLDC 1.0, CLDC 2.0)
* Java ME CLDC & GCF (JSR 360)
* Java ME Embedded Profile (JSR 361)
* Java versions >= 1.4 and later
* Java > 1.1 (but without 'loadObj' and 'getClass' methods)
* Platforms with ANSI C compiler where the included open source virtual machine (DpdlVM) can be compiled
	
	
	
## What is a DpdlPacket?

A DpdlPacket is a compact, compressed executable packet of data with built-in
database technology that can be created starting from a defined Dpdl code definition. 
A DpdlPacket can than be allocated and queried efficiently via API
interfaces available for Java and for the built-in Dpdl scripting language.
In particular Dpdl is very efficient on J2ME and JavaME platforms and
has a high degree of backward compatibility.

The Demo release package includes an encoded DpdlPacket (dpdl_PHONEBOOK.dpdl)
and the corresponding Dpdl code definition file (dpdl_PHONEBOOK.c) used to encode
the DpdlPacket.The next section 'How to run the examples' will describe how to 
execute and perform queries on a DpdlPacket.



## What does the DpdlEngine lite version provide?


The DpdlEngine lite release is freely available with some limitations,
and can be used to experiment the features of Dpdl and to develop small applications
or utility tools. All auxiliary Dpdl libraries are released under the open-source GNU
license.

DpdlEgine lite includes:

	- The 'DpdlClient' console application that allows to execute a set of commands
	  for interacting with the core DpdlEngine
	  
	- Dpdl scripting engine with API libraries
	
	- Example scripts (located in ./DpdlScripts/ and ./DpdlLibs/ folder)
	
	- Example DpdlPacket (dpdl_PHONEBOOK.dpdl) with corresponding
	  Dpdl code definition file
	


## What is the DpdlClient console application?

The DpdlClient console application included in the DpdlEngine Demo release is a small application
that exposes some functionalities of Dpdl via a simple command line console. Dpdl scripting code can be
executed and DpdlPacket handled. The same functionalities can be accessed via the java or Dpdl scripting API.

These are the console commands available:
```
Usage: 
 -l  List DpdlPackets installed
 -i  Install DpdlPacket
 -d  Deinstall DpdlPacket
 -la List DpdlPackets allocated
 -a  Allocate DpdlPacket
 -da Deallocate DpdlPacket
 -qp Query DpdlPacket
 -c Create DpdlPacket
 -libs  List Dpdl libraries
 -slib  Show library
 -api   List Dpdl API functions
 -exec  Type && Execute a Dpdl script, between <script>...  </script>
 -load  Load && Execute a Dpdl script file (relative path to./DpdlLibs/ eg. arraylistExample.h)
 -bench  Run a query benchmark test (on DpdlPacket dpdl_PHONEBOOK)
 -h  Help
 -q  quit
```

## How to run the Dpdl examples?


### Run Dpdl Scripting code

To run the Dpdl scripting examples start the DpdlClient by executing the following script:

on Linux/MacOS
```
./run_DpdlClient.sh
```

on Windows
```
./run_DpdlClient.bat
```


You can execute the Dpdl scripts, either loading them from a source file with the -load command,

or input the script directly in the command console with the -exec command, and closing with

the </script> tag

with 'load' command:
```
-load
enter the Dpdl script file to execute:
arraylistExample.h
```

with 'exec' command:
```python
-exec
<script>
string str = "this is a test"
println(str)
</script>
```
Note: the closing **</script>** tag


Here you can find the Dpdl scripting API doc

Dpdl allows to access all java classes of the underlying JRE environment,
providing access to the whole Java platform API via the loadObj(..) and the getClass(..)
Dpdl scripting API methods.

In this way Dpdl can access the classes or api of every external java library.

Example (using String java class with method 'contains(..)':
```python
object str = loadObj("String", "This is my Java object string")
bool contains = str.contains("Java")
if(contains)
	println("The string contains the word 'Java'")
else
	println("The string does NOT contain the word 'Java'")
fi
```

The class references resolved in the methods 'loadObj' and 'getClass' are defined via the class reference file:
./DpdlLibs/libs/classes.txt

NOTE: This file can be edited or complemented only in the registered, Licensed version of Dpdl.


**Example:** (Compress and de-compress a string of data)
```python

#main

object str = loadObj("String", "my data for Dpdl")
println("string to compress: " + str)

object byte_out = loadObj("ByteArrayOutputStream")
object zip_out = loadObj("GZIPOutputStream", byte_out)

println("compressing...")
zip_out.write(str.getBytes())
zip_out.close()
println("data compressed successfully")

object compressed_str = byte_out.toString()
println("compressed string: " + compressed_str)

println("decompressing...")
object byte_in = compressed_str.getBytes()

object byte_arr_in = loadObj("ByteArrayInputStream", byte_in)
object zip_in = loadObj("GZIPInputStream", byte_arr_in)

object in_reader = loadObj("InputStreamReader", zip_in)
object buf_reader = loadObj("BufferedReader", in_reader)

string decompressed_str = ""
string line = ""
while(line != null)
	line = buf_reader.readLine()
	if(line != null)
		decompressed_str = decompressed_str + line
	fi
endwhile
println("decompressed: " + decompressed_str)

```



**Examples:** 

The Dpdl script examples files are located in the folder ./DpdlLibs/


* Compresses and de-compresses a string of data with zip

	[dataCompress.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/dataCompress.h)
	
* Performs a discovery of bluetooth devices and saves the device addresses discovered in a record store
  
	[bluetoothDiscoverySave.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/bluetoothDiscoverySave.h)
  	
* Executes the bluetoothDiscoverySave.h script continuously in a dedicated Thread instance
	
	[dpdl_startup.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/dpdl_startup.h)
	
* Array definition, population and access
	
	[arraylistExample.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/arraylistExample.h)
	

* Downloads a html website from a URL and saves the content in a local file

	[downloadWebURL.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/downloadWebURL.h)
	

* Inline execution of Dpdl scripting code

	[dpdlCodeExecExample.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/dpdlCodeExecExample.h)
	

* Accepts connections from a bluetooth server application and intercepts commands

	[DpdlConsoleBT_client.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/DpdlConsoleBT_client.h)
	
	[DpdlConsoleBT_client.h_static](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/DpdlConsoleBT_client.h_static)
	
* Uses the Dpdl API library DoubleEmul and FloatEmul to emulate floating point and double precision math operations
	
	[dpdlFloatDoubleEmul.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/dpdlFloatDoubleEmul.h)
	
* Creates a graphical user interface with some UI components (Button, Panel, Checkbox, List, draw Panel) using Java Swing classes. The list is updated, the button command is intercepted with the
  'actionPerformed' function, the checkbox status is printed, and a text and rectangle is drawn at random location on the draw panel.
	
	[dpdlGUIExample.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/dpdlGUIExample.h)
	
* Set of 14 examples/tests. The examples make use of @TAG execution to allow execution of each individual example.
	
	[dpdlLibExamples.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/dpdlLibExamples.h)
	
	```
	-load
	dpdlLibExamples.h @TEST1
	```
	
	dpdlLibExamples.h @TEST2 etc..
	
	....
	

* Drawing functions on a UI Canvas on J2ME devices
	
	[J2MEDrawDemo.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/J2MEDrawDemo.h)
	
* Save and access data from a record store

	[recordStoreExample.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/recordStoreExample.h)
		

* Test read and write access to record stores

	[testRSConcurrency.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/testRSConcurrency.h)
	

* Simple console application to allocate and perform queries on the supplied DpdlPacket dpdl_PHONEBOOK. The script allows to perform single queries, or n sequential or random queries, and measures the execution
	time. Comment or uncomment the following line of code in the script -> i #abs(search_rand_int) 
	
	[testDpdlDB2.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/testDpdlDB2.h)
	
* BTObexServer (client/server)

  Sample application that implements sending of SMS via bluetooth to discovered devices. The messages to be sent are
  read from a record store. An auxiliary script (ImportantMsgWriter.h) can be used to store messages to be delivered
  in the record store
  
	[BTObexServer/BTObexServer.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/BTObexServer/BTObexServer.h)
	
	[BTObexServer/BTObexServer.h_static](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/BTObexServer/BTObexServer.h_static)
	
* HTTPServer:
  
  Simple client server application to send and receive broadcasted messages via HTTP protocol.
	
	[HTTPServer/HTTPServer.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/HTTPServer/HTTPServer.h)
	
	[HTTPClient/HTTPServer.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/HTTPServer/HTTPClient.h)
	
	How to run:
		1) start the server: HTTPServer/HTTPServer.h
		2) start the 1st client: HTTPServer/HTTPClient.h
		3) start the 2nd client, but first change the CLIENT_ID in the HTTPClient.h script
	
* CoAP (client/server):

	Client server application that implements PUT, GET, OBSERVE requests via CoAP (Constraint Device Application Protocol).
	Once the dpdlCoAPServer.h is started, the observe client (dpdlCoAPClient.h) can be initialized in a 2nd console,
	and a second client (dpdlCoAPClient2.h) that performs PUT requests can be initialized in a 3rd console by starting
	it in a dedicated thread via the script 'startClientThread.h'
	
	[CoAP/dpdlCoAPServer.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/CoAP/dpdlCoAPServer.h)
	
	[CoAP/dpdlCoAPClient.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/CoAP/dpdlCoAPClient.h)
	
	[CoAP/dpdlCoAPClient2.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/CoAP/dpdlCoAPClient2.h)
	
	[CoAP/startClientThread.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/CoAP/startClientThread.h)
	
	How to run:
		1) start the server: CoAP/dpdlCoAPServer.h
		2) start the 1st client: CoAP/dpdlCoAPClient.h
		3) start the 2nd client in a thread instance: CoAP/startClientThread.h



A set of useful examples can be found in the Dpdl script 'dpdlLibExamples.h', where different Tests/examples
can be executed individually by supplying the @TAG attribute along with the filename,
i.e. @TEST1 .....@TEST14

with load command:
```
-load
enter the Dpdl script name to execute:
dpdlLibExamples.h @TEST1
```


### DpdlPacket installation, allocation and query

The Demo release of Dpdl includes an encoded DpdlPacket (dpdl_PHONEBOOK.dpdl) that has 48877 data entries (name, phoneNR, e-email).

The packet is approximately 1,2 MB in size and has been encoded with the following Dpdl source script (dpdl_PHONEBOOK.c):

```c++
/*######################################################
                    Dpdl
                    
     Dynamic Packet Definition Language
             www.seesolutions.it

  This is a sample script written in Dpdl
  (Dynamic Packet Definition Language) showing
  how services can be implemented on the Dpdl platform.
  
  The script is compiled into an executable DpdlPacket
  that can be installed, allocated and queried efficiently
  on memory constraint devices.

  (c)opyright 2003
  SEE Solutions
  
  contact: info@seesolutions.it
  
  -----------------------------------------------------
  Example:        Phone-Book
  #######################################################
**/
call(dpdlInterpreter)
::module dpdl_PHONEBOOK
::module_SPEC 23452
::model 836
::dpdlVersion 1.0

OPTIONS {
    TARGET = CDC & CLDC
    KVM = 1.0
    ZIP = true
    CHECKSUM = true
    SIGNATURE = true
    ENCRYPTION(RSA) = false
}

#defineDpdlEncoding UTF-8

#defineDB phone_bz | ./Test/BolzanoPhone.csv | null null

#defineSQL query_ SELECT name, phoneNR, e-mail FROM phone_bz end

#defineProtocol-cHtml phonebook_visual phone_book.html

import extern SystemData

catch DPDL_Script OnInit() {
    include("dpdllib.h") nl
    println("OnInit()") nl
}

import virtual DATA none  {
        class BolzanoPhone volatile phonebook_visual {
              DATA::string const name;
              DATA::string using phoneNR;
              DATA::string using  e-mail;
              #defineGUI Default <PhoneBook>  <Enter name and surname:>
              
              catch DPDL_Script OnDecode() {
                 include("dpdllib.h") nl
                 include("dpdlRS.h") nl
                 println("OnDecode()") nl
                 string time = getTime() nl
                 println("storing access time..." + time) nl
                 int rs_id = createRS("AccessStats", AUTHMODE_ANY, dpdlTrue, dpdlTrue) nl
                 int rec_id = addRecord(rs_id, time) nl
                 int status = closeRS(rs_id) nl
                 println("done status: " + status) nl
              }
        }
}
#defineD BolzanoPhone source phone_bz SQL query {
                CHUNK entry [6];
                struct BTree DENSE_INDEX hashing *name
                entry.content { name , phoneNR , e-mail }
                entry.name TAG(0xef) const (string) = 20;
                entry.phoneNR TAG(0xefe) (string) = 15;
                entry.e-mail TAG(0xefee) (string) = 30;
}

```


To run the example

1. start the DpdlClient by executing the following script:

on Linux/MacOS
```
./run_DpdlClient.sh
```

on Windows
```
./run_DpdlClient.bat
```

2. install the DpdlPacket (dpdl_PHONEBOOK.dpdl) which is located in the folder ./DpdlServices/data/

	execute the command -i and enter the packet name: 
	
	```
	-i
	enter the DpdlPacket to install:
	dpdl_PHONEBOOK
	```
	


3. allocate the DpdlPacket and the corresponding data chunk:

	execute the command -a and enter the packet name and data chunk name to allocate:
	
	```
	-a
	enter the DpdlPacket to allocate ($dpdl_packet:$chunk_name:)
	dpdl_PHONEBOOK:BolzanoPhone
	```
	
	The DpdlPacket will be de-compressed and allocated ready to query. The 1st time a packet is allocated it takes 
	some time, subsequent allocations are immediate

	
4. run the query console example script

	execute the command -load and enter the query console example script:
	
	```
	-load
	enter the Dpdl script name to execute:
	testDpdlDB2.h
	```
	
	
	The script allows to perform either a single query, or n sequential or random queries, and measures the execution
	time for searching and accessing data:
	
		1) To perform a single query (press 'q')
		
		2) To execute senquential or random queries, for each of the data entries (press ENTER)
		   and than enter 'armin' as constraint base name, wich is part of the key of each data entry:
		   i.e. "armin 1, armin 2, ..."
		   
		   For random vs. sequential queries comment or uncomment the following line of code in the script
		   -> i #abs(search_rand_int) 
		
		

## DpdlEngine lite release limitations/restrictions

	
The DpdlEngine lite release software package has the following limitations/restrictions:

* At startup, the DpdlEngine requires the execution of a validation script.
The script simply accesses a html website at www.seesolutions.it for validation.
	  
The validation script can be inspected here: 
[./DpdlLibs/DemoDpdl_validator/validateDpdlDemo.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/DemoDpdl_validator/validateDpdlDemo.h)

* The DpdlEngine parameters and configuration file 'DpdlEngine.ini' cannot be customized
	
* The class reference file (classes.txt), used for dynamic loading of library classes via loadObj(..) and getClass(..) methods can be edited only in the registered version of Dpdl.
	
* The execution of Dpdl scripts is limited to 500 lines of code
	
* The Dpdl scripting API function 'systemExec' only executes the system commands in the registered version of Dpdl
	
* The interface to develop custom API extensions (DpdlExtension) is available only in the registered version of Dpdl
	
* The compilation of DpdlPackets via Dpdl code definition files (ex. dpdl_PHONEBOOK.c) is available only in the registered version of Dpdl
	
* The full Java API is available only in the registered Dpdl version (but Dpdl scripting API is available)

