use strict;
use warnings;
use Switch;
 
my $filename = 'sherlock.txt';
open(my $fh, '<:encoding(UTF-8)', $filename)
	or die "Could not open file '$filename' $!";

my $alphanumeric = 0;

my $index = 0;
my @chapters= ('Nothing', 'nothing');
my @words = (0,0);

#Reading line per line
while (my $row = <$fh>) {
	chomp $row;
	#first of all we are reading alphanumeric characters
	for my $i (split //, $row) {
		switch($i){
			case /[a-z]/i	{$alphanumeric++}
			case [1..9]		{$alphanumeric++}
		}
	}
	for my $word (split / /,$row){
		if(substr($word, 0, 1) eq '#'){
			$chapters[$index] = $row;
			$index++;
			last;
		}
		$words[$index-1]++;
	}

	
}

print("Number of letters: $alphanumeric \n");

for(my $i=0; $i < $index; $i++){
	print("chapter: @chapters[$i]\nWords: @words[$i] \n\n");
}
