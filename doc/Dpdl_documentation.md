# Dpdl Documentation

				www.dpdl.biz
	
	


## Dpdl scripting language

**Features:**
* Basic types supported (**int, byte, double, long, string, bool, array[], object**)
* Native Threads
* API: native API, Dpdl API, MIDP API, JRE
* Access to the full underlying Java Platform API (JRE) or other external java libraries
* Record Store creation and access
* Static script execution: static code declarations (*.h_static) are executed only once in a Thread
* Support for custom function extensions


### Variable Type definition

Dpdl support the following type definitions:
```python
int i = 1
byte b = 0x01 
double d = 1.0
long l = 1000L
string s = "mystr"
bool t = true | false
array[] = "1 1.0 0x01 test"
object myobj = getClass(..)
```

Arrays support multiple types and can be accessed via a [ArrayList](https://docs.oracle.com/javase/1.5.0/docs/api/java/util/ArrayList.html) object

Example:
```python
myarray[] = "1 1.0 0x01 test Dpdl Dynamic Packet Definition Language"

myarray2[0]  = myarray.getObj()

object myarrayobj = myarray2[0]

bool b = myarrayobj.contains("Dpdl")

println("array contains Dpdl: " + b) 
```

### Function and Control flow

**function** definition
```python
func myFunction(string param, object param....)

end
```

**if** statement
```python
if(<expression>)

fi
```

**if else** statement
```python
if(<expression>)

elseif

else

fi
```

**while** statement
```python
while(<expression>)

endwhile
```


### Dpdl native functions


### DpdlObject

Dpdl can access the underlying classes of a give JRE implementation or any other external libraries.

Static classes can be accessed via **getClass(..)** method and instance classes via **loadObj(..)** method.

The class references are resolved via the classes.tx file located in the folder ./DpdlLibs/libs/.
NOTE: Only the full registered version of Dpdl allows editing of this file. The default DpdlEngine lite configuration contains
the class references of JRE 1.5

Example:
```python
# static class loading
object calendar = getClass("Calendar")
object cal_inst = calendar.getInstance()
int day_ = cal_inst.get(calendar.DATE)
println("day: " + day_)

# instance class loading
object str = loadObj("String", "Test MyString")
int idx = str.indexOf(" ")
string substr = str.substring(idx)
println(substr)
```


### Extensions

The Dpdl language can be extended by implementing specific interfaces for custom
function and variable declarations.

The implemented extensions can be registered via settings in the "Extensions" section
defined in the DpdlEngine.ini configuration file.

Example of a custom print function, myprintln(..):
```java
import dpdl.dpdlDpdlEngine.scripting.BasicDpdlExtension;

public class MyTestDpdlExtension extends BasicDpdlExtension{

    public Object dpdlCall(String name,ArrayList param) throws DpdlException {
			// implement you methods here
    }
}
```

## DpdlClient

DpdlClient is a console application that allows to use Dpdl via commands.

The following commands are available:
```
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

To run to DpdlClient console application you need Java JRE >= 1.5 and run the following command:
```
java -jar DpdlEngine_V1.0_release.jar
```

NOTE: The newer release of Java (Java20) has introduced the concepts of 'modules'. A compliant 
version of DpdlEngine will be released soon.

If you need to run the DpdlClient on the latest version of Java, use the following command and add the modules you want to access via Dpdl scripting:

```
java --add-opens java.base/sun.net.www.protocol.http=ALL-UNNAMED --add-opens java.base/sun.net.www.protocol.https=ALL-UNNAMED -cp ./lib/mjcoap.jar -jar DpdlEngine_V1.0_release.jar
```


## Dpdl definition language

Dpdl allows to create compressed packets of data via a DpdlPacket code definition. The data in a DpdlPacket can be organized
in chunks of highly compressed data, along with database indexes. Data chunks can be allocated, queried and deallocated when not
needed anymore. This allows a very efficient method of accessing and searching big amounts of data in memory constrained 
devices.

Dpdl scripting can be embedded in the DpdlPacket code definition and allows to trigger its execution on predefined callbacks.
This makes a DpdlPacket an executable packet of data.

This is an example DpdlPacket code definition (a phonebook database):
```c++
call(dpdlInterpreter)
::module dpdl_PHONEBOOK_BZ
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

The DpdlPacket as defined above, can be allocated and queried via Dpdl scripting API or via the equivalent Java API

```python
int status = DPDLAPI_swapDpdlChunk("dpdl_PHONEBOOK_BZ", "BolzanoPhone")
if(status == dpdlTrue)
	status = DPDLAPI_selectDpdlService("dpdl_PHONEBOOK_BZ",, "BolzanoPhone", "armin 369")
fi
```

The first time a DpdlPacket is allocated (swapped), data is decompressed in a temporary storage. This process takes some time for the 1st allocation,
but is immediate for subsequent allocations, as long as the DpdlPacket is not explicitly deallocated.

### Data Types

A DpdlPacket chunk allocation supports the following types:

```c++
int
string
char
double
float
long
byte
Image
class
xml
dpdlpacket
```

