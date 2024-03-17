BEGIN {
	name_pattern = "[a-zA-Z_][a-zA-Z0-9_]*"
	error_color_str = "\033[31m"
	reset_color_str = "\033[0m"
}
{
        if (FNR == 1)
        {
                print "File: " FILENAME;
                table_name = $1;
                if (length(table_name) == 0)
                {
                        print error_color_str "No table name found." reset_color_str
                        nextfile
                }
                else if (table_name !~ "^" name_pattern "$")
                {
                        print error_color_str "\"" $1 "\" can't be used as a table name." reset_color_str
                        nextfile
                }
        }
        else if (FNR == 2)
        {
        	number_of_columns = NF
        	if (number_of_columns == 0) 
        	{
        		print error_color_str "No columns names found." reset_color_str
        		nextfile
        	}
                pattern = "^" name_pattern "(" FS name_pattern ")*$"
                for (i = 1; i <= NF; i++) 
                {
        		if ($i !~ pattern) 
        		{
            			print error_color_str "\"" $i "\" can't be used as a column name." reset_color_str
                        nextfile
        		}
    		}
                        
                gsub(FS, ", ", $0) 
                col_names = $0
                
        }
        else
        {
        	if (length($0) == 0)
        	{
        		next
        	}
                gsub(FS, ", ", $0)
                if (NF != number_of_columns)
                {
                        print error_color_str "Wrong number of values in line " FNR ". Expected " number_of_columns ", but found " NF "." reset_color_str
                }
                else
                {
                	printf "INSERT INTO %s (%s) \nVALUES (%s);\n", table_name, col_names, $0
                }
        }
}
                                                 
