# File: testFunc.h
#
# Example: This example shows how the script testLoadCode.h loads this script as object (with default constructor) and 
#          calls a function defined here
#
# Author: A.Costa
# e-mail: info@seesolutions.it
#
#

# constructor
func LoadCodeFunc()
	println("object LoadCodeFunc loaded")
end

func testFunc(string s, object o)
	println("s: " + s)
	println(o.toString())
end

# scripts loaded as object with loadCode(..) must return 1 (success) or -1 (error)
return 1