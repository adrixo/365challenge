
#!/usr/bin/perl
use strict;
use warnings;

print "Welcome to age calculator; please enter your age: ";
my $age = <STDIN>;
chomp $age;

my $days = $age * 365;
my $months = $age * 12;
my $hours = $days * 24;
my $minutes = $hours * 60;

printf("Months: %d, days: %d, hours: %d, minutes: %d \n",$months, $days, $hours, $minutes);
