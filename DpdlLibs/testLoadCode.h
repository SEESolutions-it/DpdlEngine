# File: testLoadCode.h
#
# Example: This example shows how to load a Dpdl script object via loadCode(..) and call one of its functions
#
# Author: A.Costa
# e-mail: info@seesolutions.it
#
#

# main
println("test loadCode(..) with dpdl script LoadCodeFunc.h")

object mycode = loadCode("LoadCodeFunc.h")

string mystr1 = "Test"
object mystr2 = loadObj("String", "MEGA")

mycode.testFunc("LoadCodeFunc", mystr1, mystr2)

println("done")
