# Dpdl (Dynamic Packet Definition Language) Documentation

The Dpdl scripting language is implemented within the DpdlEngine, a cross platform, constraint device
framework and library to encode, decode, control and visualize data using an efficient
data allocation paradigm with build-in database technology and scripting engine. Dpdl has been
developed since year 2003 targeting in first place the development of applications on small
memory footprint devices and mobile applications, that's why Dpdl was foreseen to run on a very
small memory heap (Kb range). Dpdl is particularly useful for fast prototyping.


**Features:**
	- Encoding of DpdlPackets as defined by the Dpdl Packet definition language
	- Decoding and querying of DpdlPackets
	- Build-in Dpdl scripting engine with support for custom function extensions
	- Small footprint Java Virtual Machine included (open source)
	- Support for Bluetooth(tm) with JSR-82 implementation
	- Support for CoAP (Constrained Application Protocol) compliant to the current IETF standard RFC 7252
	- Support for emulated double precision floating point numbers types (Float and Double)

Dpdl supports a wide range of platforms and a small footprint open-source virtual machine written in C
is available so that it can be compiled and run on almost every platform.

**Supported platforms:**
	
* J2ME MIDP (Mobile Information Device Profile) -> MIDP 1.0 and MIDP 2.0 (CLDC 1.0, CLDC 2.0)
* Java ME CLDC & GCF (JSR 360)
* Java ME Embedded Profile (JSR 361)
* Java versions >= 1.4 and later
* Java > 1.1 (but without 'loadObj' and 'getClass' methods)
* Platforms with ANSI C compiler where the included open source virtual machine (DpdlVM) can be compiled
	
	
## Dpdl definition language


## Dpdl scripting language

**Features:**
	- Basic types supported (int, byte, double, long, string, bool, array[], object)
	- Native threads
	- Full featured API: native API, Dpdl API, MIDP API
	- Record Store creation and access
	- Static script execution: static code declarations (*.h_static) are executed only once in a Thread
	- Functions that allow to access the full underlying JRE API or other external libraries
	- Support for custom function extensions


### Variable Type definition

```
int i = 1
byte b = 0x01 
double d = 1.0
long l = 1000L
string s = "mystr"
bool t = true | false
array[] = "1 1.0 0x01 test"
object myobj = getClass(..)
```

### Function and Control flow

function definition
```
func myFunction(string param, object param....)

end
```

if statement
```
if(<expression>)

fi
```

if else statement
```
if(<expression>)

else

fi
```

while statement
```
while(<expression>)

endwhile
```


### Dpdl native functions


### Dpdl reflection

Dpdl can access the underlying classes of a give JRE implementation or other external libraries.

Static classes can be accessed via getClass(..) method and instance classes via loadObj(..) method.

Example:
```python
# static class loading
object calendar = getClass("java.util.Calendar")
object cal_inst = calendar.getInstance()
int day_ = cal_inst.get(calendar.DATE)
println("day: " + day_)

# instance class loading
object str = loadObj("java.lang.String", "Test MyString")
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
```
import dpdl.dpdlDpdlEngine.scripting.BasicDpdlExtension;

public class MyTestDpdlExtension extends BasicDpdlExtension{

    public Object dpdlCall(String name,ArrayList param) throws DpdlException {
        if (name.equals("myprintln")) {
            String str = "";
            for(int p=0;p<param.size();p++) {
                str = str + param.get(p);
            }
            System.out.println("myprintln: " + str);
            return null;
        }else{ 
        	throw new DpdlUnsupportedException(name);
        } 
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
version of DpdlEngine will be released soon. In the meantime, if you need to run the DpdlClient on the latest version
of Java, use the following command and add the modules you want to access via Dpdl scripting:

```
java --add-opens java.base/sun.net.www.protocol.http=ALL-UNNAMED --add-opens java.base/sun.net.www.protocol.https=ALL-UNNAMED -cp ./lib/mjcoap.jar -jar DpdlEngine_V1.0_release.jar
```
 
