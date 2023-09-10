# File: validateDpdlDemo.h
#
# NOTE: Do not edit or delete this file, it's required to keep the Dpdl DEMO release active
#
# This scripts serves as a validator for the DEMO release of Dpdl. It simply accesses a web page of
# SEE Solutions at the following url: http://www.seesolutions.it
# 
# contact: info@seesolutions.it
#

# main
string URL_to_validate = "http://www.seesolutions.it/DemoDpdl_validator.html"

object url = loadObj("URL", URL_to_validate)
object url_connection = url.openConnection()

object url_in = url_connection.getInputStream()

if(url_in == nul)
	println("The DpdlEngine lite release requires internet connectivity for validation purposes Only!")
	println("To disable the validation process, a valid DpdlLicenseKey is required.")
	exit(-1)
fi

object url_in_read = loadObj("InputStreamReader", url_in)
object buf_read = loadObj("BufferedReader", url_in_read)
object buf_str = loadObj("String", "")

string web_content = ""
while(buf_str != null)
	buf_str = buf_read.readLine()
	if(buf_str != null)
		web_content = web_content + buf_str.toString()
	fi
endwhile

bool check_ok = false
object check_url = loadObj("String", web_content)
if(check_url != null)
	check_ok = check_url.contains("Dpdl (Dynamic Packet Definition Language) Demo validator 260a5348b14")
fi
println("DEMO validation: " + check_ok)
if(check_ok == false)
	println("exiting...")
	exit(-1)
fi

