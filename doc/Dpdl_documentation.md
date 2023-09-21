# Dpdl Documentation

				www.dpdl.biz
	
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

### Function and Control flow

function definition
```python
func myFunction(string param, object param....)

end
```

if statement
```python
if(<expression>)

fi
```

if else statement
```python
if(<expression>)

else

fi
```

while statement
```python
while(<expression>)

endwhile
```


### Dpdl native functions


### Dpdl reflection

Dpdl can access the underlying classes of a give JRE implementation or any other external libraries.

Static classes can be accessed via **getClass(..)** method and instance classes via **loadObj(..)** method.

The class names are resolved via the classes.tx file located in the folder ./DpdlLibs/libs/. NOTE: Only the full registered version of Dpdl allows editing of this file.

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
 
