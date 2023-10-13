# File: testLoadCode.h
#
# Example: This example shows how to load a Dpdl script object via loadCode(..) and call one of its functions
#
# Author: A.Costa
# e-mail: info@seesolutions.it
#
#

# main
println("test loadCode(..) with dpdl script testLoadCodeFunc.h")

object mycode = loadCode("testLoadCodeFunc.h")

string mystr1 = "Test"
object mystr2 = loadObj("String", "MEGA")

mycode.testFunc("testLoadCodeFunc.h", mystr1, mystr2)

println("done")
