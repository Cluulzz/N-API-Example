{
    "targets": [
        {
            "target_name": "main",
            "sources": [ "lib/main.cpp" ],
            "include_dirs" : [
 	 			"<!(node -e \"require('node-addon-api')\")"
			]
        }
    ],
}