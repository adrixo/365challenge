# simple program tryng to learn perl
# it just ask for data 

use strict;
use warnings;

my $userLoop ==0;

while($userLoop == 0){

	printf("Employee name: ");
	my $name = <STDIN>;
	chomp $name;

	printf("Employee age: ");
	my $age = <STDIN>;
	chomp $age;

	printf("Price per hour: ");
	my $price = <STDIN>;
	chomp $price;

	my $filename = 'store.txt';
	open(my $fh, '>>', $filename) or die "Could not open file '$filename' $!";
	print $fh "$name, $age, $price\n";
	close $fh;

	printf("Type 0 if you want to continue: ");
	$userLoop = <STDIN>;
	chomp $userLoop;
}
