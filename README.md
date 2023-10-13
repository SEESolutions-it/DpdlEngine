
# Dpdl - Dynamic Packet Definition Language

				www.seesolutions.it



developed by
**SEE Solutions**


## What is Dpdl?


Dpdl is a **constrained device programming language** framework that can be used to encode,
store, control, visualize and query data efficiently on small memory footprint 
devices and to support rapid application development. Dpdl comes with a very compact and portable
**Scripting Engine** and an **extensible API interface** for the development of mobile
applications and embedded system software.

The Dpdl language constructs and syntax is kept simple and follows an object oriented paradigm
enabling to access the full Java platform API and external java libraries directly within Dpdl scripts.

Standard **ANSI C code** (a subset of C90) and the **OCaml** functional programming language
can be **embedded and executed directly within Dpdl scripts** (interpreted and compiled code).
This makes Dpdl suitable for a wide variety of use-cases and in particular also for hardware programming.

**DpdlEngine stack overview**

![Dpdl stack](http://www.seesolutions.it/images/app/thumb/Dpdl_Dynamic_Packet_Definition_Language_components_thumb.jpg)

Common IoT protocol stacks such as **Bluetooth(tm)** and **CoAP** (Constrained Application Protocol)
are integrated by default and third party libraries and functions can be added as extensions.

By combining the portability and vast API availability of Java, the expressiveness of OCaml and
the power of C programming language, Dpdl is provides a powerful development platform for industrial
applications, education and research.

Dpdl is designed to be simple, very compact, robust, extendible and portable to almost every platform.

### Dpdl ( Java API + OCaml + Embedded C ) = Powerful and Versatile

Sample Dpdl script (Bluetooth device discovery using Dpdl high level BT API):
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

A list of 14 examples/tests can be found in the following Dpdl script, as explained later:

[dpdlLibExamples.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/dpdlLibExamples.h)


## Why Dpdl?

Dpdl can be used to implement applications in various domains, in particular for small
memory footprint devices, and is very suitable for rapid applications development, teaching and research.

The DpdlPacket data container is a highly optimized way to store, search and access data
on devices that have limited memory and storage capabilities. 

**Dpdl can be used:**

	* As rapid application development environment
	* As an embedded scripting engine for applications
	* A library module
	* As utility tool
	
	
### Features

* **DpdlEngine is optimized to run on a vast range of platforms** (J2ME, JavaME, J2SE, any other JVM >= 1.4 Spec, compiled DpdlVM for target platform)
* **Built-in Dpdl scripting engine with support for custom function extensions** (DpdlExtension interface)
* **Dpdl scripting API provides access to the complete underlying Java JRE platform and to API libraries** via the loadObj(..) and getClass(..) methods
* **ANSI C code and OCaml language can be embedded and executed** directly within Dpdl scripts (interpreted/compiled code), a subset of C90 standard, POSIX compliant
* **Support for common IoT protocol stacks such as Bluetooth(tm)** (JSR-82) and
**CoAP (Constrained Application Protocol)** (IETF standard RFC 7252)
* **Packing data in a DpdlPacket is a convenient way to optimize and speedup access to data**
The speedup is x 25 times faster compared to a standard record store access
* **Virtual filesystem** for record stores
* **Double precision floating point emulation** layer
* **XML** with XPath parser
* **JSON**
* **Fast Prototyping**


### Access to the complete JRE Java platform API and external java libraries


The Dpdl scripting language API allows to access all classes and methods of the underlying Java Platform (JRE) and external java libraries
via the **loadObj(..)** and **getClass(..)** methods.

**Example:** using a java HashMap (which is resolved to java.util.HashMap)
```python
object map, s

map=loadObj("HashMap")
map.put(1,"Dpdl")
map.put(2,"Packet")
map.put(3,"Definition")
map.put(4,"Language")

s=map.get(1)
println(s)
s=map.get(4)
println(s)
```

With the Dpdl API functions all java libraries defined in class definition configuration file can be accessed.
The default configuration includes Java 5 Platform API (1.5), and bluecove Bluetooth JSR-82

#### Dpdl API access documentation (default configuration)


[Java 5 API](http://www.seesolutions.it/apidoc/Java_Platform_API_1_5.html)

[Bluetooth JSR-82 API](http://www.seesolutions.it/apidoc/Bluetooth_JSR82_API.html)


The default configuration can be extended or updated to resolve additional java APIs (editing of class definition configuration file)


### Embedded C code

Dpdl allows the embedding and execution of **ANSI C code** directly within Dpdl scripts. The C code is interpreted via a native Dpdl library that has
a very small footprint and **includes all essential C libraries** and language constructs (subset of ISO standard C90 and **POSIX** compliant) with
**no external dependencies**.

Custom libraries and functions can be integrated and linked via a straight forward implementation configuration approach.


Example Dpdl script with embedded C code:
```c
# main
# starting with Dpdl, pushing parameters on the stack and embedding C code

println("testing embedded C code in Dpdl")

int n = 6
double x = 10.0
string a = "test"

dpdl_stack_push(n, x, a)

>>c
	#include <stdio.h>
	
	int main(int argc, char **argv){
		printf("Hello C from Dpdl!\n");
		printf("\n");
		printf("num params: %d\n", argc);
		int cnt;
	    for (cnt = 0; cnt < argc; cnt++){
	        printf("	param %d: %s\n", cnt, argv[cnt]);
	    }
	    return 0;
	}
<<
int exit_code = dpdl_exit_code()

println("embedded C exit code: " + exit_code);

# again Dpdl...

object str = loadObj("String", "Dpdl embedded C")
bool b = str.contains("C")
println("Dpdl contains C: " + b)
```

This is a more complete example of the usage of embedded C code within Dpdl:

[dpdlEmbeddedC.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/dpdlEmbeddedC.h)


### Embedding of other programming languages

Currently the functional programming language 'OCaml' (https://ocaml.org/) is supported, and can be embedded
directly within Dpdl scripts.

Example Dpdl script with embedded 'OCaml' code:
```python
println("testing Dpdl embedded OCaml..")


# parameter to instruct the Dpdl runtime to compile the embedded code (faster execution). Without this option the code is interpreted
dpdl_stack_push("compile")

# we add a variable to the dpdl stack so that we can access it in the embedded OCaml
dpdl_stack_var_put("mydpdlvar", "Dpdl interacts with OCaml")

>>ocaml
external get_binding

let dpdl_var = get_binding "mydpdlvar"
print_endline "mydpdlvar:"
print_endline dpdl_var 

let string_of_float f =
  let s = format_float "%.12g" f in
  let l = string_length s in
  let rec loop i =
    if i >= l then s ^ "."
    else if s.[i] = '.' || s.[i] = 'e' then s
    else loop (i + 1)
  in
    loop 0
    
    print_endline "Output:"
    print_string f 
    print_string "\n";
<<

int exit_code = dpdl_exit_code()

println("embedded OCaml exit code: " + exit_code);

```

Other programming languages may also be supported in future. Please feel free to suggest your opinion on the
Discussion section on the DpdlEngine GitHub repository

## Supported Platforms

Dpdl runs on a wide range of platforms and provides also a small footprint java virtual machine,
released as open-source that can  be compiled for almost every platform as soon as
an ANSI C compiler is available for the target platform.

### Dpdl is compatible with:

* J2ME MIDP (Mobile Information Device Profile) -> MIDP 1.0 and MIDP 2.0 (CLDC 1.0, CLDC 2.0)
* Java ME CLDC & GCF (JSR 360)
* Java ME Embedded Profile (JSR 361)
* Java versions >= 1.4 and later
* Java > 1.1 (but without 'loadObj' and 'getClass' methods)
* Platforms with ANSI C compiler where the included open source virtual machine (DpdlVM) can be compiled

DpdlEngine V1.0 has been tested on:

	* MacOS arm64
	* Linux x86_64
	* Raspberry PI (arm)
	* Windows 64-bit
	* Android
	* JavaME
	* J2ME (MIDP 2.0)
		
		
	
## Roadmap

Dpdl is currently developed by SEE Solutions and the following integrations has been defined: 

* Native API support for Tensorflow and Tensorflow lite
* OpenAI integration
* Blockchain integration (Bitcoin and Ethereum smart contracts)
* Nostr client API


## Documentation

The Dpdl framework and API documentation are available via the following links:
 
[Dpdl scripting API Documentation](https://github.com/SEESolutions-it/DpdlEngine/blob/main/doc/Dpdl_API.md)

[Dpdl Documentation](https://github.com/SEESolutions-it/DpdlEngine/blob/main/doc/Dpdl_documentation.md)


## Download 'DpdlEngine lite' release package (Free version)

The 'DpdlEngine lite' release (V1.0) can be downloaded and used for Free (with some limitations),
from the following download link form:

[DpdlEngine lite DOWNLOAD form](http://www.seesolutions.it/lang_en/index_download.html)

Documentation and Updates are updated regularly on the official DpdlEngine GitHub repository:
[DpdlEngine GitHub](https://github.com/SEESolutions-it/DpdlEngine)

Check the 'DpdlEngine lite' release limitations/restrictions, compared to the full DpdlEngine version, in the last section of this document.

Suggestion and contributions to enhance Dpdl are very welcome and can be submitted on the discussion section on GitHub:
[Dpdl discussion](https://github.com/SEESolutions-it/DpdlEngine/discussions)


## What is a DpdlPacket?

A DpdlPacket is a compact, highly compressed executable packet of data with built-in
database technology that can be created based on a defined Dpdl code definition. 
A DpdlPacket can than be allocated and queried efficiently via API
interfaces available for Java and for the built-in Dpdl scripting language.
In particular Dpdl is very efficient on J2ME and JavaME platforms and
has a high degree of backward compatibility.

A DpdlPacket contains 1 - n chunks of compressed data that can be allocated, queried and
deallocated when data is not used.

### DpdlPacket

![DpdlPacket](http://www.seesolutions.it/images/app/thumb/Dpdl_Framework_FlowChart_thumb.jpg)

The DpdlEngine lite release package includes an encoded DpdlPacket (dpdl_PHONEBOOK.dpdl)
and the corresponding Dpdl code definition file [dpdl_PHONEBOOK.c](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlScripts/dpdl_PHONEBOOK_BZ.c) used to encode
the DpdlPacket. Refer to the [Dpdl_documentation](https://github.com/SEESolutions-it/DpdlEngine/blob/main/doc/Dpdl_documentation.md)
for how to allocate, execute and perform queries on a DpdlPacket.

Example of DpdlPacket code definiiton (dpdl_PHONEBOOK.c)
```cpp
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


The database technology in Dpdl has been developed since year 2003 and started with a BsC thesis.

[Advanced database techniques in Dpdl : dynamic packet definition language ; a portable data protocol for small embedded systems](https://ubz-primo.hosted.exlibrisgroup.com/permalink/f/pok0fm/39UBZ_ALMA_DS21103210480001241)


## What is the DpdlClient console application?

The DpdlClient console application included in the 'DpdlEngine lite' release is a small console application
that exposes some functionalities of Dpdl via a simple command line console. Dpdl scripting code can be
executed and DpdlPackets handled. The same functionalities can be accessed via the java or Dpdl scripting API.

These are the console commands available:
```
Usage: 
 -l  List DpdlPackets installed
 -i  Install DpdlPacket
 -d  Uninstall DpdlPacket
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


## What does the free 'DpdlEngine lite' version provide?


The 'DpdlEngine lite' release is available for Free with some limitations (see section below),
and can be used to exploit the features of Dpdl and to develop small applications
or utility tools. Some auxiliary Dpdl libraries are released under the open-source GNU
license.


'DpdlEgine lite' includes:

	- The 'DpdlClient' console application that allows to execute a set of commands
	  for interacting with the core DpdlEngine
	  
	- Dpdl scripting engine with API libraries
	
	- Example scripts (located in ./DpdlScripts/ and ./DpdlLibs/ folder)
	
	- Example DpdlPacket (dpdl_PHONEBOOK.dpdl) with corresponding
	  Dpdl code definition file
	


## Dpdl Scripting examples

A set of examples implemented with Dpdl scripting language can be found in the script './DpdlLibs/dpdlLibExamples.h',
where different Tests/Examples can be executed individually via tagged execution, by supplying the @TAG attribute along with the filename.
i.e. @TEST1 .....@TEST14

To execute the individual examples enter DpdlClient console:
```
-load
enter the Dpdl script name to execute:
dpdlLibExamples.h @TEST1
```

The Dpdl script examples files are located in the folder ./DpdlLibs/

* Set of 14 examples/tests. The examples make use of @TAG execution to allow execution of each individual example.
	
	[dpdlLibExamples.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/dpdlLibExamples.h)
	
	```
	-load
	dpdlLibExamples.h @TEST1
	```
	
	dpdlLibExamples.h @TEST2 etc..
	
	....
	
* Compresses and de-compresses a string of data with zip

	[dataCompress.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/dataCompress.h)

* Parse JSON and access data types

	[testDpdlJSON.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/testDpdlJSON.h)
	
* Embedded C code execution within Dpdl script
	
	[dpdlSimpleC.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/dpdlSimpleC.h)
		
* Extended Embedded C code execution within Dpdl scripts
	
	[dpdlEmbeddedC.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/dpdlEmbeddedC.h)
	
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

	Client server application that implements PUT, GET, OBSERVE requests via CoAP (Constrained Application Protocol).
	The clients can create resources and perform PUT, GET or OBSERVE requests on the resources created.
	
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



## 'DpdlEngine lite' release limitations/restrictions

	
The 'DpdlEngine lite' release software package is available for Free and has the following limitations/restrictions:

* At startup, the DpdlEngine requires the execution of a validation script.
The script simply accesses a html website at www.seesolutions.it for validation (NO data is collected, it's a simple get html.
	  
The validation script can be inspected here: 
[./DpdlLibs/DemoDpdl_validator/validateDpdlDemo.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/DemoDpdl_validator/validateDpdlDemo.h)

* The DpdlEngine parameters and configuration file 'DpdlEngine.ini' can be customized only in the registered version
	
* The class definition file (classes.txt), used for dynamic loading and resolving of library classes via loadObj(..) and getClass(..) methods can be edited only in the registered version of Dpdl.
	
* The execution of Dpdl scripts is limited to 500 lines of code, embedded C code and OCaml is limited to 100 lines of code
	
* The Dpdl scripting API function 'systemExec' is available only in the registered version of Dpdl
	
* The interface API to develop custom API extensions (DpdlExtension) is available only in the registered version of Dpdl
	
* The compilation/encoding of DpdlPackets via Dpdl code definition files (ex. dpdl_PHONEBOOK.c) is available only in the registered version of Dpdl
	
* The full Java API is available only in the registered Dpdl version (but Dpdl scripting API is fully available)

**NOTE:** The native Dpdl library for embedded C support within Dpdl scripts is currently available for MacOS, Linux x86_64, Raspberry Pi. 
More builds will follow. Eventually it might be necessary to recompile it for some versions of the platform.
Contact us if this is the case.


## How to buy a full DpdlEngine license?

To buy a full DpdlEngine license with no limitations/restrictions, regular updates and support,
please write to the following e-mail address: 

info@seesolutions.it

We will propose an appropriate license plan tailored for your needs and budget.




