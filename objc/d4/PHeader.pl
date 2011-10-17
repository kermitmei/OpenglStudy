# This header is used for the tools to create Y5's C++ source code.

# Use:  
#   Used to replace the specific data in the line.
# Args  --- 3:
#   arg[0] is the old text;
#   arg[1] is the new text;
#   arg[2] is the hole line text. 
# Ret
#    Return the $line data which has be replaced.
sub replaceContInText
{
    my $oldText =  @_[0];
    my $newText =  @_[1];
    my $text	= \@_[2];

    foreach my $en ($$text =~ m/$oldText/ig) {
	my $uc_tmp = uc($en);
	if($en eq $uc_tmp) {
	    my $uc_newText = uc($newText);
	    $$text =~ s/$en/$uc_newText/g;
	}elsif(substr($en,0,1) eq uc(substr($en,0,1))) {
	    $$text =~ s/$en/$newText/g;
	}else {
	    $$text =~ s/$en/lc($newText)/g;
	}
    }
    return $$text;
}


# Use:  
#   Get all the current headers' name under the specific dir.
# Args  --- 3:
#   arg[0] is the directory;
# Ret
#    Return the sorted array of the names.
sub getHeaderNames
{
    my $widgetsDir = @_[0];
    my @allNames;
    my $dir;
    
    opendir($dir,$widgetsDir) || die "Error in opening dir $widgetsDir\n";
    while(($filename = readdir($dir))) {
	my $tmp = $filename;
	if($tmp =~ m/.+\.h$/) {
	    $tmp =~ s/\.h//;
	    push(@allNames,$tmp);
	}
    }
    closedir($dir);
    return sort(@allNames);
}

# Use:  
#   Read all of the text in the file into $var
# Args  --- 3:
#   arg[0] is the file name;
#   arg[1] is the variant where you want to save the text;
# Ret
#    Return Nothing
sub readTextFromFile
{
    my $fileName  =  @_[0];
    my $text	  = \@_[1];
    my $fn;
    die "Can not open file: ".$fileName
	unless(open($fn,"<".$fileName));
    $$text = do { local $/; <$fn>; };
    close($fn);
}

# Use:  
#   Read all of the files and find that has main() function;
# Args  --- 3:
#   arg[0] is the file name;
#   arg[1] is the variant where you want to save the text;
# Ret
#    Return Nothing
sub findMainFile
{
    my $mainFn;

    
    return $mainFn;
}
