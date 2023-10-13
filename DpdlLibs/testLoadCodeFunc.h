# File: testFunc.h
#
# Example: This example shows how the script testLoadCode.h loads this script as object and 
#          calls a function defined here
#
# Author: A.Costa
# e-mail: info@seesolutions.it
#
#

func testFunc(string s, object o)
	println("s: " + s)
	println(o.toString())
end

# main
println("object testLoadCodeFunc.h loaded")

# scripts loaded as object with loadCode(..) must return 1 (success) or -1 (error)
return 1