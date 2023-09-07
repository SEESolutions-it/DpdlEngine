# File: arraylistExample.h
#
# Example: array population and access
#
# Author: A.Costa
# e-mail: info@seesolutions.it
#
#

arr[] = "1 2 3 4 5"
arr_list[] = ""
int x = 0
while(x < arr.size())
    arr_list[x] = arr.getObj()
    println("added arr_list[" + x + "]=" + arr_list[x])
    x = x + 1
endwhile
x = 0
object arr_ref
while(x < arr_list.size())
   arr_ref = arr_list[x]
   println("arr_list[" + x + "]=" + arr_ref)
   println("getting element " + x)
   x = arr_ref.get(x)
   println("val: " + x)
endwhile
# 
arr2[] = "1 1.0 0x01 test"
println("arr: " + arr2)
object b = arr2[2]
println("b: " + b.toString())
